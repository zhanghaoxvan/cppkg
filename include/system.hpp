#pragma once

#include "includes.hpp"

namespace cppkg::system {
    void link_headers(std::string headers_path);
    void link_executable(std::string executables_path);
}