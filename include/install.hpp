#pragma once
#include "includes.hpp"
#include "progressbar.hpp"

namespace cppkg::install {
    void install(const std::string &package_name) {
        std::cout << "Install Process:";
        progressbar pb(100, true, std::cout);
        // system("wget ")
    }
}