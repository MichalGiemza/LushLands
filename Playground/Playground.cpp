﻿#include <iostream>
#include <filesystem>
#include <unordered_map>
//namespace fs = std::filesystem;
//int main() {
//    fs::path p1 = "/usr/lib/sendmail.cf"; // portable format
//    fs::path p2 = "C:\\users\\abcdef\\AppData\\Local\\Temp\\"; // native format
//    fs::path p3 = U"D:/猫.txt"; // UTF-32 string
//    fs::path p4 = u8"~/狗.txt"; // UTF-8 string
//
//    std::cout << "p1 = " << p1 << '\n'
//        << "p2 = " << p2 << '\n'
//        << "p3 = " << p3 << '\n'
//        << "p4 = " << p4 << '\n';
//}

//class baseClass {
//public:
//    virtual baseClass myFunction() = 0;
//};
//
//class derivedClass : public baseClass {
//public:
//    virtual baseClass myFunction() override {};
//};

//typedef const char *entitytype;
//struct ChunkPosition {
//    int x;
//    int z;
//    bool operator==(const ChunkPosition &other) const {
//        return x == other.x && z == other.z;
//    }
//};
//template<> struct std::hash<ChunkPosition> {
//    std::size_t operator()(const ChunkPosition &p) const {
//        return
//            hash<int>()(p.x) ^
//            hash<int>()(p.z);
//    }
//};
//std::unordered_map<entitytype, char *> groundTiles = std::unordered_map<entitytype, char *>();
//int main(int argc, char **argv) {
//    (void)argc;
//    (void)argv;
//
//    //ChunkPosition c = { 12, 43 };
//    entitytype c = "cac";
//
//    groundTiles[c] = (char *)"ccc";
//
//    std::cout << groundTiles[c];
//}

//#include <windows.h>
//#include <iostream>
//#include <exception>
//#include <unordered_map>
//
//class Cl {
//public:
//    char c;
//    Cl(char x) { c = x; }
//    Cl() { c = 'X'; }
//};
//
//int main(int argc, char **argv) {
//    (void)argc;
//    (void)argv;

    //std::unordered_map<int, Cl*> um = std::unordered_map<int, Cl*>();
    //
    //um[2] = new Cl('T');
    //
    //std::cout << um[2]->c << um[3] << std::endl;
    //return 0;

    //const int chunkRenderDistance = 3;
    //const int chunksInLine = (chunkRenderDistance - 1) * 2 + 1;
    //const int displacement = chunksInLine / 2;
    //const int chunkAmount = chunksInLine * chunksInLine;
    //
    //for (int i = 0; i < chunksInLine; i++) {
    //    for (int j = 0; j < chunksInLine; j++) {
    //        std::cout << - displacement + j << ", ";
    //        std::cout << - displacement + i << std::endl;
    //    }
    //}
//}

//#include <filesystem>
//#include <iostream>
//#include <math.h>
//
//char * t1 = (char *)"..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png";
//char * t2 = (char *)"..\\Assets\\textures\\32x32 and 64x64 Pixel Art Textures by 711studios\\32x32 Tiles\\Dehydrated_Earth.png";
//
//template<> struct std::hash<char *> {
//    std::size_t operator()(const char *p) const {
//        std::size_t sum = 0;
//        for (int i = 0; p[i] != 0; i++) {
//            sum = 33 * sum + p[i];
//        }
//        return sum;
//    }
//};
//
//int main() {
//    std::hash<char *> str_hash = std::hash<char *>();
//    std::cout << "Vals: " << str_hash(t1) << "\n" << str_hash(t2) << "\n" << str_hash(t1) << "\n" << str_hash(t2) << "\n";
//
//}

//
//int main(int argc, char **argv) {
//    (void)argc;
//    (void)argv;
//    std::cout << "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png" << std::endl;
//}




int main() {
    std::cout << -1231 % 32 << std::endl;
}