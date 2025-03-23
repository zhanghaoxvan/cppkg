#pragma once
#include "includes.hpp"
#include "install.hpp"

namespace fs = std::filesystem;
namespace cppkg {
    // Function to invoke the main function of the given executable
    void invoke_main(std::vector<std::string> args) {
        if (args.size() < 2) {
            std::cerr << "Usage: cppkg <command> [package]" << std::endl;
            return;
        } 
    }
}