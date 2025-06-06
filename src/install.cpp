#include "../include/install.hpp"
#include "../include/system.hpp"

namespace cppkg::install {

    void install_local(const std::string& package_name) {
        // Extract package name without extension (e.g., "example.cppkg" -> "example")
        std::string package = std::string(package_name.begin(), package_name.begin() + package_name.rfind("."));

        // Step 1: Unzip the package file
        try {
            cppkg::sys::unzip(package_name);
        } catch (const std::exception& e) {
            throw;
        }

        // Step 2: Copy to ~/.cppkg/
        std::filesystem::path install_dir = std::filesystem::path(getenv("HOME")) / ".cppkg/" / package;
        try {
            std::filesystem::copy_file(package, install_dir, std::filesystem::copy_options::overwrite_existing);
        } catch (const std::exception& e) {
            throw std::runtime_error("Failed to copy package to ~/.cppkg: " + std::string(e.what()));
        }

        // Step 3: Cleanup temporary files
        try {
            std::filesystem::remove(package + ".zip");
        } catch (const std::exception&) {
            std::cerr << "Warning: Failed to delete .zip file\n";
        }
        try {
            std::filesystem::remove_all(package);
        } catch (const std::exception&) {
            std::cerr << "Warning: Failed to delete temporary directory\n";
        }

        // Step 4: Create symlink to /usr/include
        std::string include_path = (install_dir / "include").string();
        cppkg::sys::symlink(
            include_path,
            "/usr/include",
            cppkg::sys::symlink_type::DIRECTORY
        );
    }

    void install_web(const std::string& package_name) {
        // Step 1: Download package via Git
        std::string git_cmd = "git archive --remote=git@github.com:zhanghaoxvan/cppkg-packages.git HEAD:" + package_name + " --format=zip --output=" + package_name + ".cppkg";
        if (system(git_cmd.c_str())) {
            throw std::runtime_error("Failed to download package: " + package_name);
        }

        // Step 2: Install the downloaded package
        install_local(package_name + ".cppkg");
    }

} // namespace cppkg::install