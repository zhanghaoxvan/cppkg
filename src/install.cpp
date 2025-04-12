#include "../include/install.hpp"
void cppkg::install::install_local(const std::string &package_name) {
    // Rename File *.cppkg to *.zip
    system(("mv " + package_name + " " + std::string(package_name.begin(), package_name.begin() + package_name.rfind(".")) + ".zip").c_str());
    // unzip file
    system((std::string(package_name.begin(), package_name.begin() + package_name.rfind(".")) + ".zip").c_str());
    // copy the floder to ~/.cppkg
    system(("cp -r " + std::string(package_name.begin(), package_name.begin() + package_name.rfind(".")) + " ~/.cppkg/").c_str());
    // delete the zip file
    system(("rm " + std::string(package_name.begin(), package_name.begin() + package_name.rfind(".")) + ".zip").c_str());
}
void cppkg::install::install_web(const std::string &package_name) {
    // Download Package File
    system(("wget https://zhanghaoxvan.top/packages/" + package_name + ".cppkg").c_str());
    // Install Package
    install_local(package_name + ".cppkg");
}