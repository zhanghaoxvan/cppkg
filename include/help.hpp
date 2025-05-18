#pragma once
#include "includes.hpp"

namespace cppkg::help {
    /**
     * @brief Displays the CPPKG ASCII art logo.
     * 
     * Prints a stylized "CPPKG" banner to stdout for visual branding.
     */
    void show_icon();

    /**
     * @brief Displays the help message and usage instructions.
     * 
     * Shows:
     * 
     * 1. The CPPKG logo (via `show_icon()`)
     * 
     * 2. Available commands and their syntax
     * 
     * 3. Brief descriptions of each command
     */
    void help();
} // namespace cppkg::help