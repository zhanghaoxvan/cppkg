#include "../include/system.hpp"

void cppkg::system::link_headers(std::string headers_path) {
    auto headers_floder =
        std::string(headers_path.begin() + headers_path.rfind('\\'), headers_path.end());
    std::system(("ln -s " +
        headers_path + " " + getenv("USERPROFILE") + "\\.cppkg\\include\\" + headers_floder).c_str());
}
void cppkg::system::link_executable(std::string executables_path) {
    auto executables_floder =
        std::string(executables_path.begin() + executables_path.rfind('\\'), executables_path.end());
    
}