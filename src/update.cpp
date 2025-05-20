#include "../include/update.hpp"

namespace cppkg::update {

void update_packages_list() {
    const std::string repo_url = "https://github.com/cppkg-packages/lists";
    const std::string home_dir = getenv("HOME");
    const std::string cppkg_dir = home_dir + "/.cppkg";
    const std::string lists_dir = cppkg_dir + "/lists";

    try {
        // 1. Ensure ~/.cppkg exists
        if (!std::filesystem::exists(cppkg_dir)) {
            std::filesystem::create_directory(cppkg_dir);
        }

        // 2. Download package lists
        std::cout << "Downloading latest package lists...\n";
        if (system(("git archive --remote=" + repo_url + " --format=zip --output=lists.zip").c_str())) {
            throw std::runtime_error("Failed to download package lists");
        }

        // 3. Extract the archive
        std::cout << "Extracting package lists...\n";
        if (system("unzip -q lists.zip")) {  // -q for quiet mode
            throw std::runtime_error("Failed to extract package lists");
        }

        // 4. Install to ~/.cppkg/lists
        std::cout << "Updating local package lists...\n";
        if (system(("mkdir -p " + cppkg_dir + " && cp -rf lists/lists " + lists_dir).c_str())) {
            throw std::runtime_error("Failed to update local package lists");
        }

        // 5. Cleanup
        std::filesystem::remove("lists.zip");
        std::filesystem::remove_all("lists");

        std::cout << "Successfully updated package lists!\n";

    } catch (const std::exception& e) {
        // Cleanup in case of error
        std::filesystem::remove("lists.zip");
        std::filesystem::remove_all("lists");
        
        throw std::runtime_error(std::string("Package list update failed: ") + e.what());
    }
}

} // namespace cppkg::update