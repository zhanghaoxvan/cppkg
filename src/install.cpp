#include "../include/install.hpp"
#include "../include/system.hpp"

void cppkg::install::install_local(const std::string &package_name) {
    std::string package = std::string(package_name.begin(), package_name.begin() + package_name.rfind("."));
    // unzip file
    system(("unzip " + package + ".cppkg").c_str());
    // copy the floder to ~/.cppkg
    system(("cp -rf " + package + " " + getenv("HOME") + "/.cppkg/" + package).c_str());
    // delete the zip file
    system(("rm " + package + ".zip").c_str());
    // delete the floder
    system(("rm -r " + package).c_str());
    // Create a symlink to the package at /usr/include
    cppkg::sys::link_headers("~/.cppkg/" + package + "/include");
}

void cppkg::install::install_web(const std::string &package_name) {
    // Download Package File
    system(("git archive --remote=git@github.com:zhanghaoxvan/cppkg-packages.git HEAD:"
        + package_name + " --format=zip --output=" + package_name + ".cppkg").c_str());
    // Install Package
    install_local(package_name + ".cppkg");
}