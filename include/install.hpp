#pragma once
#include "includes.hpp"
#include "info.hpp"

namespace cppkg::install {
    void install(const std::string &package_name) {
        // Download Package File
        system(("wget https://zhanghaoxvan.top/packages/" + package_name + ".cppkg").c_str());
        // Rename File *.cppkg to *.zip
        system(("mv " + package_name + " " + std::string(package_name.begin(), package_name.begin() + package_name.rfind(".")) + ".zip").c_str());
        // unzip file
        system(std::string(package_name.begin(), package_name.begin() + package_name.rfind(".")) + ".zip");
        cppkg::info::info(package_name); // Show Information about this package
    }
}
