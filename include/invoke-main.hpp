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
        if (args[1] == "install") {
            if (args.size() < 3) {
                std::cerr << "Error: No package name provided." << std::endl;
                return;
            }
            if (args[2] == "--local") {
                if (args.size() < 4) {
                    std::cerr << "Error: No local package file provided." << std::endl;
                    return;
                }
                cppkg::install::install(args[3]);
            } else {
                cppkg::install::install(args[2]);
            }
        } else if (args[1] == "remove") {
            // Implement remove functionality
        } else if (args[1] == "list") {
            // Implement list functionality
        } else if (args[1] == "search") {
            // Implement search functionality
        } else if (args[1] == "help") {
            cppkg::help::help();
        } else if (args[1] == "version") {
            // Implement version functionality
        } else {
            std::cerr << "Error: Unknown command '" << args[1] << "'." << std::endl;
            std::cerr << "Use 'cppkg help' for a list of available commands." << std::endl;
        }
    }
}