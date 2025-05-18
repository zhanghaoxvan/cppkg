#pragma once
#include "includes.hpp"

namespace cppkg::update {

    /**
     * @brief Updates the local package list from the remote repository.
     * 
     * This function:
     * 
     * 1. Downloads the latest package lists from the official repository
     * 
     * 2. Extracts and installs them to ~/.cppkg/lists
     * 
     * 3. Cleans up temporary files
     * 
     * @throws std::runtime_error If any step fails (download, extraction, or copy)
     * 
     * @note Requires:
     * 
     * - Git to be installed and in PATH
     * 
     * - unzip command available
     * 
     * - Write permissions to ~/.cppkg
     */
    void update_packages_list();

} // namespace cppkg::update