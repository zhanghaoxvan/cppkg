#pragma once
#include "includes.hpp"
#include "install.hpp"
#include "help.hpp"
#include "info.hpp"
#include "update.hpp"
#include "list.hpp"
#include "remove.hpp"

namespace cppkg {
    // Function to invoke the main function of the given executable
    void invoke_main(std::vector<std::string> args);
}