#pragma once
#include "includes.hpp"

namespace cppkg::install {

    /**
     * @brief Installs a local .cppkg package file.
     * 
     * This function:
     * 
     * 1. Unzips the package file.
     * 
     * 2. Copies the package to `~/.cppkg/`.
     * 
     * 3. Cleans up temporary files.
     * 
     * 4. Creates a symlink from `/usr/include` to the package's include directory.
     * 
     * @param package_name Name of the package file (e.g., "example.cppkg").
     * @throws std::runtime_error If any system command fails.
     * 
     * @note Requires `unzip`, `cp`, and `rm` commands to be available.
     * @note Symlink creation to `/usr/include` typically requires root privileges.
     */
    void install_local(const std::string& package_name);

    /**
     * @brief Downloads and installs a package from a remote repository.
     * 
     * This function:
     * 
     * 1. Downloads the package from a Git repository.
     * 
     * 2. Delegates to `install_local()` for installation.
     * 
     * @param package_name Name of the package (e.g., "example").
     * @throws std::runtime_error If Git download or installation fails.
     * 
     * @note Requires Git and network access.
     */
    void install_web(const std::string& package_name);
} // namespace cppkg::install
