#include "../include/list.hpp"

void cppkg::list::list() {
    std::cout << "Installed Packages will be listd here." << std::endl;
    std::cout << "Packages:" << std::endl;
    std::filesystem::directory_iterator it(std::filesystem::path(getenv("HOME")) / ".cppkg");
    try {
        for (const auto& entry : it) {
            if (entry.is_directory() && entry.path().filename() != "bin") {
                std::cout << "  " << entry.path() << std::endl;
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "There are the worst error in this software. "
            "You need to delete `cppkg` and recompile it." << std::endl
            << "Input: make remove to remove `cppkg`" << std::endl;
    }
}