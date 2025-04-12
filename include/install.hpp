#pragma once
#include "includes.hpp"
namespace cppkg::install {
    void install_local(const std::string &package_name);
    void install_web(const std::string &package_name);
}
