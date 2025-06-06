#include "../include/info.hpp"

namespace cppkg::info {
    void info(const std::string& package_name) {
        // Step 1: Download package metadata via Git
        std::string git_cmd = "git archive --remote=git@github.com:zhanghaoxvan/cppkg-packages.git HEAD:" + package_name + " --format=zip --output=" + package_name + ".zip";
        if (system(git_cmd.c_str()) != 0) {
            throw std::runtime_error("Failed to download package metadata: " + package_name);
        }

        // Step 2: Extract the ZIP archive
        try {
            cppkg::sys::unzip("unzip " + package_name + ".zip");
        } catch (const std::exception& e) {
            throw std::runtime_error("Failed to extract package: " + package_name + ": " + e.what());
        }

        // Step 3: Clean up the ZIP file (ignore errors)
        try {
            std::filesystem::remove(package_name + ".zip");
        } catch (const std::exception& e) {
            ; // We don't need to focus on exceptions,
              // but we have to write this try-catch block
              // in case exceptions are passed out
        }

        // Step 4: Parse and display info.json
        std::ifstream file(package_name + "/info.json");
        if (!file.is_open()) {
            throw std::runtime_error("Missing or inaccessible info.json in package: " + package_name);
        }

        try {
            nlohmann::json j;
            file >> j;

            // Validate required fields
            const std::vector<std::string> required_fields = { "name", "version", "description", "author", "license" };
            for (const auto& field : required_fields) {
                if (!j.contains(field)) {
                    throw std::runtime_error("Invalid info.json: missing field '" + field + "'");
                }
            }

            // Display package info
            std::cout << "Package: " << j["name"] << "\n"
                    << "  Version: " << j["version"] << "\n"
                    << "  Description: " << j["description"] << "\n"
                    << "  Author: " << j["author"] << "\n"
                    << "  License: " << j["license"] << "\n";

        } catch (const nlohmann::json::exception& e) {
            throw std::runtime_error("Failed to parse info.json: " + std::string(e.what()));
        }

        // Step 5: Clean up extracted directory (ignore errors)
        try {
            std::filesystem::remove_all(package_name);
        } catch (const std::exception& e) {
            ; // See the lines 22~24
        }
    }
} // namespace cppkg::info