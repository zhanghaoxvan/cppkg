#include "../include/invoke-main.hpp"

int main(int argc, char* argv[]) {
    cppkg::invoke_main(std::vector<std::string>(argv, argv + argc));
    return 0;
}