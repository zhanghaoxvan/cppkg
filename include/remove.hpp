#pragma once

#include "includes.hpp"

namespace cppkg::remove {

    /**
     * @brief Removes a specified package from the local C++ package manager storage.
     * 
     * This function permanently deletes the package directory located at:
     * `~/.cppkg/<package_name>` and all its contents.
     * 
     * @param package_name Name of the package to remove (case-sensitive).
     *                     Should match the exact directory name in ~/.cppkg/.
     * 
     * @throws std::filesystem_error If:
     * 
     * - The package directory doesn't exist
     * 
     * - Permission denied when deleting
     * 
     * - Filesystem operations fail
     * 
     * @note Requires C++17 filesystem support
     * @warning This is an irreversible operation. No backup is created.
     * 
     * @example
     * // Remove package "test-pkg"
     * cppkg::remove::remove("test-pkg");
     */
    void remove(std::string package_name);

} // namespace cppkg::remove