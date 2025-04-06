#pragma once
#include "includes.hpp"

namespace cppkg::help {
    void help() {
        std::cout << "Usage:" << std::endl;
        std::cout << "cppkg install <packages-file>:" << std::endl;
        std::cout << "    cppkg install <package> - install a package." << std::endl;
        std::cout << "    cppkg install --local <local package file> - install a local package." << std::endl;
        std::cout << "cppkg remove <package> - remove a package." << std::endl;
        std::cout << "cppkg list             - list all installed packages." << std::endl;
        std::cout << "cppkg search <package> - search a package." << std::endl;
        std::cout << "cppkg help             - show this text and exit." << std::endl;
        std::cout << "cppkg version          - show version information." << std::endl;
    }
}