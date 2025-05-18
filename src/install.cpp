#include "../include/install.hpp"
#include "../include/system.hpp"

namespace cppkg::install {

void install_local(const std::string& package_name) {
    // Extract package name without extension (e.g., "example.cppkg" -> "example")
    std::string package = std::string(package_name.begin(), package_name.begin() + package_name.rfind("."));

    // Step 1: Unzip the package file
    if (system(("unzip " + package + ".cppkg").c_str())) {
        throw std::runtime_error("Failed to unzip package: " + package_name);
    }

    // Step 2: Copy to ~/.cppkg/
    std::string install_dir = std::string(getenv("HOME")) + "/.cppkg/" + package;
    if (system(("cp -rf " + package + " " + install_dir).c_str())) {
        throw std::runtime_error("Failed to copy package to ~/.cppkg");
    }

    // Step 3: Cleanup temporary files
    if (system(("rm " + package + ".zip").c_str())) {
        std::cerr << "Warning: Failed to delete .zip file\n";
    }
    if (system(("rm -r " + package).c_str())) {
        std::cerr << "Warning: Failed to delete temporary directory\n";
    }

    // Step 4: Create symlink to /usr/include
    std::string include_path = install_dir + "/include";
    cppkg::sys::symlink(
        include_path,
        "/usr/include",
        cppkg::sys::symlink_type::DIRECTORY
    );
}

void install_web(const std::string& package_name) {
    // Step 1: Download package via Git
    std::string git_cmd = "git archive --remote=git@github.com:zhanghaoxvan/cppkg-packages.git HEAD:"
                        + package_name + " --format=zip --output=" + package_name + ".cppkg";
    if (system(git_cmd.c_str())) {
        throw std::runtime_error("Failed to download package: " + package_name);
    }

    // Step 2: Install the downloaded package
    install_local(package_name + ".cppkg");
}

} // namespace cppkg::install