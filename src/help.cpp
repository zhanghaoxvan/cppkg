#include "../include/help.hpp"
namespace cppkg::help {

    void show_icon() {
        std::cout << R"(                         _            )" << std::endl;
        std::cout << R"(   ___   _ __    _ __   | | __   __ _ )" << std::endl;
        std::cout << R"(  / __| | '_ \  | '_ \  | |/ /  / _` |)" << std::endl;
        std::cout << R"( | (__  | |_) | | |_) | |   <  | (_| |)" << std::endl;
        std::cout << R"(  \___| | .__/  | .__/  |_|\_\  \__, |)" << std::endl;
        std::cout << R"(        |_|     |_|             |___/ )" << std::endl;
    }

    void help() {
        show_icon();
        
        std::cout << "\nUsage:\n";
        
        // Installation commands
        std::cout << "  cppkg install <packages> [--force]\n"
                  << "      Install packages from the repository.\n\n"
                  << "  cppkg install --local <package_files> [--force]\n"
                  << "      Install packages from local .cppkg files.\n\n";
        
        // Package management
        std::cout << "  cppkg info <package>\n"
                  << "      Show detailed information about a package.\n\n"
                  << "  cppkg remove <packages>\n"
                  << "      Remove installed packages.\n\n"
                  << "  cppkg list\n"
                  << "      List all installed packages.\n\n";
        
        // Remote operations
        std::cout << "  cppkg search <query>\n"
                  << "      Search for packages online.\n\n"
                  << "  cppkg update\n"
                  << "      Update the package index from the repository.\n\n";
        
        // Miscellaneous
        std::cout << "  cppkg help\n"
                  << "      Display this help message.\n";
    }
} // namespace cppkg::help