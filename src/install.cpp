#include "../include/install.hpp"
#include "../include/symlink.hpp"

void cppkg::install::install_local(const std::string &package_name) {
    std::string package = std::string(package_name.begin(), package_name.begin() + package_name.rfind("."));
    // Rename File *.cppkg to *.zip
    system(("mv " + package_name + " " + package + ".zip").c_str());
    // unzip file
    system(("unzip " + package + ".zip").c_str());
    // copy the floder to ~/.cppkg
    system(("cp -r " + package + " ~/.cppkg/" + package).c_str());
    // delete the zip file
    system(("rm " + package + ".zip").c_str());
    // delete the floder
    system(("rm -r" + package).c_str());
    // Create a symlink to the package at /usr/include
    cppkg::utils::symlink::link_headers(("~/.cppkg/" + package));
}

void cppkg::install::install_web(const std::string &package_name) {
    // Download Package File
    system(("git archive --remote=https://github.com/cppkg-packages/" +
        package_name + ".git" + " --format=zip --output=" + package_name + ".cppkg").c_str());
    // Install Package
    install_local(package_name + ".cppkg");
}