#pragma once
#include "includes.hpp"
#include "json.hpp"

namespace cppkg::info {
    /**
     * @brief Retrieves and displays metadata for a specified package.
     * 
     * This function:
     * 
     * 1. Downloads the package's metadata from a Git repository.
     * 
     * 2. Extracts the `info.json` file.
     * 
     * 3. Parses and displays key package information (name, version, etc.).
     * 
     * @param package_name Name of the package (e.g., "example").
     * 
     * @throws std::runtime_error If:
     * 
     * - Git download fails.
     * 
     * - `info.json` is missing or invalid.
     * 
     * @note Requires Git, `unzip`, and the `nlohmann/json` library(has included).
     * @note Temporary files (`package_name.zip` and extracted dir) are cleaned up.
     */
    void info(const std::string& package_name);
} // namespace cppkg::info