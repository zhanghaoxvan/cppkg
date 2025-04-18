#include "../include/info.hpp"

void cppkg::info::info(const std::string& package_name) {
    system(("git archive --remote=https://github.com/cppkg-packages/" +
        package_name + ".git" + " --format=zip --output=" + package_name + ".zip").c_str());
    system(("unzip " + package_name + ".zip").c_str());
    system(("rm " + package_name + ".zip").c_str());
    std::ifstream file(package_name + "/info.json");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open info.json file." << std::endl;
        return;
    }
    nlohmann::json j;
    file >> j;
    std::cout << "Package Name: " << j["name"] << std::endl;
    std::cout << "Version: " << j["version"] << std::endl;
    std::cout << "Description: " << j["description"] << std::endl;
    std::cout << "Author: " << j["author"] << std::endl;
    std::cout << "License: " << j["license"] << std::endl;
    std::cout << "Header Floder: " << j["header-folder"] << std::endl;
    std::cout << "executable Floder: " << j["executable-folder"] << std::endl;
}