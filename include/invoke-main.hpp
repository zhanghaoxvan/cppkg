#pragma once
#include "includes.hpp"
#include "install.hpp"
#include "help.hpp"
#include "info.hpp"

namespace fs = std::filesystem;
namespace cppkg {
    // Function to invoke the main function of the given executable
    void invoke_main(std::vector<std::string> args);
}