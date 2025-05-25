#include "../include/invoke-main.hpp"

namespace cppkg {
    void invoke_main(const std::vector<std::string>& args) {
        // Show help if no arguments provided
        if (args.empty()) {
            cppkg::help::help();
            return;
        }

        const std::string& command = args[0];
        std::vector<std::string> cmd_args(args.begin() + 1, args.end());

        try {
            // Install command handler
            if (command == "install") {
                bool force = false;
                auto force_it = std::find(cmd_args.begin(), cmd_args.end(), "--force");
                
                // Extract force flag if present
                if (force_it != cmd_args.end()) {
                    force = true;
                    cmd_args.erase(force_it);
                }

                if (cmd_args.empty()) {
                    throw std::runtime_error("No package(s) specified for installation");
                }

                // Local file installation
                if (cmd_args[0] == "--local") {
                    if (cmd_args.size() < 2) {
                        throw std::runtime_error("No local package files specified");
                    }
                    
                    for (size_t i = 1; i < cmd_args.size(); ++i) {
                        // Check if the floder exists
                        if (cppkg::sys::has_subdirectory(
                                std::filesystem::path(std::getenv("HOME")) / ".cppkg",
                                cmd_args[i]
                            ) && !force) {
                            std::cerr << "Package already exists: " << cmd_args[i] << std::endl;
                            continue;
                        }
                        cppkg::install::install_local(cmd_args[i]);
                    }
                } else { // Remote package installation
                    for (size_t i = 0; i < cmd_args.size(); ++i) {
                        // Check if the floder exists
                        if (cppkg::sys::has_subdirectory(
                                std::filesystem::path(std::getenv("HOME")) / ".cppkg",
                                cmd_args[i]
                            ) && !force) {
                            std::cerr << "Package already exists: " << cmd_args[i] << std::endl;
                            continue;
                        }
                        cppkg::install::install_web(cmd_args[i]);
                    }
                }
            } else if (command == "remove") { // Remove command handler
                if (cmd_args.empty()) {
                    throw std::runtime_error("No packages specified for removal");
                }
                
                for (const auto& pkg : cmd_args) {
                    cppkg::remove::remove(pkg);
                }
            } 
            else if (command == "list") { // List installed packages
                cppkg::list::list();
            } else if (command == "search") {// Search packages
                if (cmd_args.empty()) {
                    throw std::runtime_error("No search terms provided");
                }
                // Implementation would go here...
            } else if (command == "help") { // Show help
                cppkg::help::help();
            }
            
            else if (command == "info") { // Show package info
                if (cmd_args.empty()) {
                    throw std::runtime_error("No packages specified for info query");
                }
                
                for (const auto& pkg : cmd_args) {
                    cppkg::info::info(pkg);
                }
            }
            // Update package lists
            else if (command == "update") {
                cppkg::update::update_packages_list();
            }
            // Unknown command
            else {
                throw std::runtime_error("Unknown command: " + command);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cerr << "Use 'cppkg help' for usage information" << std::endl;
        }
    }
} // namespace cppkg