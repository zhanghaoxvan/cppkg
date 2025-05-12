#include "../include/invoke-main.hpp"

void cppkg::invoke_main(std::vector<std::string> args) {
    if (args.size() < 2) {
        cppkg::help::help();
        return;
    }
    if (args[1] == "install") {
        if (args.size() < 3) {
            std::cerr << "Error: No package name provided." << std::endl;
            return;
        }
        bool force = *(args.end() - 1) == "--force";
        if (args[2] == "--local") {
            if (args.size() < 4) {
                std::cerr << "Error: No local package file provided." << std::endl;
                return;
            }
            for (int i = 3; i < args.size(); i++) {
                if (!force || !std::filesystem::exists(std::string(getenv("HOME")) + "/.cppkg")) {
                    continue;
                }
                cppkg::install::install_local(args[i]);
            }
        } else {
            for (int i = 2; i < args.size(); i++) {
                if (!force || !std::filesystem::exists(std::string(getenv("HOME")) + "/.cppkg")) {
                    continue;
                }
                cppkg::install::install_web(args[i]);
            }
        }
    } else if (args[1] == "remove") {
        
    } else if (args[1] == "list") {
        // Implement list functionality
    } else if (args[1] == "search") {
        // Implement search functionality
    } else if (args[1] == "help") {
        cppkg::help::help();
    } else if (args[1] == "info") {
        for (int i = 2; i < args.size(); i++) {
            cppkg::info::info(args[i]);
        }
    } else if (args[1] == "update") {
        cppkg::update::update_packages_list();
    } else {
        std::cerr << "Error: Unknown command '" << args[1] << "'." << std::endl;
        std::cerr << "Use 'cppkg help' for a list of available commands." << std::endl;
    }
}