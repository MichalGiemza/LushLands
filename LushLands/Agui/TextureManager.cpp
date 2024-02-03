#include "Agui/TextureManager.h"


const std::string TM::pngExt = std::string(".png");
const std::string TM::jsonExt = std::string(".json");
entitytype TM::defaultTex = NULL;
std::unordered_map<entitytype , std::vector<ALLEGRO_BITMAP *>> TM::textures;
std::unordered_map<entitytype , std::vector<agui::Allegro5Image *>> TM::images;
std::unordered_map<std::string, ALLEGRO_BITMAP *> TM::rawBitmaps;
bool TextureManager::initialized = false;


std::vector<ALLEGRO_BITMAP *> *TextureManager::loadTextures(std::vector<TextureLocalization> tls) {
    std::vector<ALLEGRO_BITMAP *> *texSet = new std::vector<ALLEGRO_BITMAP *>();
    int i = 0;
    for (const auto &tl : tls) {
        auto rawBitmap = getRawBitmap(&tl);
        texSet->push_back(al_create_sub_bitmap(rawBitmap, tl.x, tl.y, tl.w, tl.h));
        i += 1;
    }
    return texSet;
}

std::vector<agui::Allegro5Image *> *TextureManager::prepareImages(std::vector<ALLEGRO_BITMAP *> *bmps) {
    std::vector<agui::Allegro5Image *> *imgs = new std::vector<agui::Allegro5Image *>();
    for (auto &bmp : *bmps) {
        agui::Allegro5Image *img = new agui::Allegro5Image();
        img->setBitmap(bmp);
        imgs->push_back(img);
    }
    return imgs;
}

ALLEGRO_BITMAP *TextureManager::getRawBitmap(const TextureLocalization *tl) {
    if (not rawBitmaps[tl->path]) {
        rawBitmaps[tl->path] = al_load_bitmap(tl->path.c_str());
    }
    return rawBitmaps[tl->path];
}

void TextureManager::init() {
    if (not initialized) {
        defaultTex = CR::selectEntityType("default", true);
        loadAllTextures();
        initialized = true;
    }
}

void TextureManager::loadAllTextures() {
    // All textures from textures directory
    NameToTexLocs *tlm = prepareTextureLocalizations();
    for (auto &tls : *tlm) {
        std::string texName = tls.first;
        entitytype et = CR::selectEntityType(texName, true);
        textures[et] = *loadTextures(tls.second);
        images[et] = *prepareImages(&textures[et]);
    }
}

ALLEGRO_BITMAP *TextureManager::getTexture(entitytype texName, int variation) {
    entitytype texId = CR::selectEntityType(texName);
    if (not textures.contains(texId) or variation >= textures[texId].size()) {
        return textures[defaultTex][0];
    }
    return textures[texId][variation];
}

agui::Allegro5Image *TextureManager::getImage(entitytype texName, int variation) {
    entitytype texId = CR::selectEntityType(texName);
    if (not images.contains(texId) or variation >= images[texId].size()) {
        return images[defaultTex][0];
    }
    return images[texId][variation];
}

NameToTexLocs *TextureManager::prepareTextureLocalizations() {
    NameToTexLocs *tlm = new NameToTexLocs();
    // Json files
    for (const auto &fn : fs::directory_iterator(texturesDir)) {
        if (fs::is_regular_file(fn)) {
            std::string texName = fn.path().stem().string();
            if (fn.path().extension().string() == jsonExt) {
                std::vector<TextureLocalization> *tls = &(*tlm)[texName];
                auto texJson = JsonHandler::parseJson(fn.path());
                auto x = texJson.dump();
                int variationCounter = 0;
                for (json::iterator je = texJson.begin(); je != texJson.end(); ++je) {
                    TextureLocalization *tl = new TextureLocalization();
                    tl->x = je->at("Position").at("X");
                    tl->y = je->at("Position").at("Y");
                    tl->w = je->at("Size").at("W");
                    tl->h = je->at("Size").at("H");
                    tl->variation = variationCounter;
                    tls->push_back(*tl);
                    variationCounter += 1;
                }
            }
        }
    }
    // Image paths
    for (const auto &fn : fs::directory_iterator(texturesDir)) {
        if (fs::is_regular_file(fn)) {
            std::string texName = fn.path().stem().string();
            if (fn.path().extension().string() == pngExt) {
                auto &tls = (*tlm)[texName];
                if (tls.empty()) {
                    TextureLocalization *tl = new TextureLocalization();
                    tl->path = fn.path().string();
                    tls.push_back(*tl);
                } else {
                    for (auto &tl : tls) {
                        tl.path = fn.path().string();
                    }
                }
            }
        }
    }
    return tlm;
}
