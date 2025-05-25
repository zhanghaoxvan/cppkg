#pragma once
#include "includes.hpp"
#include "install.hpp"
#include "help.hpp"
#include "info.hpp"
#include "update.hpp"
#include "list.hpp"
#include "remove.hpp"
#include "system.hpp"

namespace cppkg {
    /**
     * @brief Dispatches commands to appropriate package manager functions
     * @param args Command-line arguments (excluding program name)
     * 
     * Handles all main commands:
     * 
     * - install [--local] [--force] <packages>
     * 
     * - remove <packages>
     * 
     * - list
     * 
     * - info <packages> 
     * 
     * - update
     * 
     * - help
     */
    void invoke_main(std::vector<std::string> args);
}