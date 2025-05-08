#include "../include/system.hpp"

void cppkg::sys::link_headers(std::string headers_path) {
    auto headers_floder = std::string(headers_path.begin() + headers_path.rfind('/'), headers_path.end());
    std::system(("ln -s " + headers_path + " /usr/include/" + headers_floder).c_str());
}
void cppkg::sys::link_executable(std::string executables_path) {
    auto executables_floder = std::string(executables_path.begin() + executables_path.rfind('/'), executables_path.end());
    std::system(("ln -s" + executables_path + "/usr/bin/" + executables_floder).c_str());
}