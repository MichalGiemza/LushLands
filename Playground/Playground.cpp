#include <iostream>
#include <fstream>
#include <boost/json.hpp>



int main() {
    // Open the JSON file for reading
    std::ifstream jsonFile("example.json");
    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open JSON file." << std::endl;
        return 1;
    }

    // Read the contents of the JSON file
    std::string jsonString((std::istreambuf_iterator<char>(jsonFile)),
        std::istreambuf_iterator<char>());

    // Parse the JSON string
    boost::json::error_code error;
    boost::json::value jsonValue = boost::json::parse(jsonString, error);
    if (error) {
        std::cerr << "Failed to parse JSON: " << error.message() << std::endl;
        return 1;
    }

    // Access the JSON data
    if (jsonValue.is_object()) {
        const boost::json::object &jsonObject = jsonValue.as_object();
        for (const auto &pair : jsonObject) {
            std::cout << "Key: " << pair.key() << ", Value: " << pair.value() << std::endl;
        }
    }

    return 0;
}
 