#include "../include/help.hpp"

void cppkg::help::show_icon() {
    std::cout << R"(                         _            )" << std::endl;
    std::cout << R"(   ___   _ __    _ __   | | __   __ _ )" << std::endl;
    std::cout << R"(  / __| | '_ \  | '_ \  | |/ /  / _` |)" << std::endl;
    std::cout << R"( | (__  | |_) | | |_) | |   <  | (_| |)" << std::endl;
    std::cout << R"(  \___| | .__/  | .__/  |_|\_\  \__, |)" << std::endl;
    std::cout << R"(        |_|     |_|             |___/ )" << std::endl;
}
void cppkg::help::help() {
    show_icon();
    std::cout << "Usage:" << std::endl;
    std::cout << "cppkg install <packages-file>:" << std::endl;
    std::cout << "    cppkg install <package> - install a package." << std::endl;
    std::cout << "    cppkg install --local <local package file> - install a local package." << std::endl;
    std::cout << "cppkg remove <package> - remove a package." << std::endl;
    std::cout << "cppkg list             - list all installed packages." << std::endl;
    std::cout << "cppkg search <package> - search a package." << std::endl;
    std::cout << "cppkg help             - show this text and exit." << std::endl;
    std::cout << "cppkg version          - show version of cppkg." << std::endl;
}