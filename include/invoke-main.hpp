#pragma once
#include "includes.hpp"
#include "install.hpp"
#include "help.hpp"

namespace fs = std::filesystem;
namespace cppkg {
    // Function to invoke the main function of the given executable
    void invoke_main(std::vector<std::string> args) {
        if (args.size() < 2) {
            cppkg::help::help();
            return;
        } 
    }
}