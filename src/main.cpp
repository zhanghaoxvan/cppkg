#include "../include/invoke-main.hpp"

int main(int argc, char* argv[]) {
    cppkg::invoke_main(std::vector<std::string>(argv + 1, argv + argc));
    return 0;
}