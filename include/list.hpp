#pragma once
#include "includes.hpp"

namespace cppkg::list {

    /**
     * @brief Lists all installed packages in the user's ~/.cppkg directory.
     * 
     * Scans the `~/.cppkg` directory and displays:
     * 
     * - All valid package directories
     * 
     * - Skips special directories (e.g., "bin")
     * 
     * @throws std::filesystem::filesystem_error If directory access fails.
     * 
     * @note Requires C++17 filesystem support.
     * @note Creates ~/.cppkg if it doesn't exist.
     */
    void list();

} // namespace cppkg::list