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
            try {
                cppkg::sys::unzip("lists.zip");
            } catch (const std::exception& e) {
                throw;
            }

            // 4. Install to ~/.cppkg/lists
            try {
                // Create directories recursively
                std::filesystem::create_directories(cppkg_dir);
                
                // Copy the lists directory
                std::filesystem::path source = "lists/lists";
                std::filesystem::path destination = lists_dir;
                
                if (!std::filesystem::exists(source) || !std::filesystem::is_directory(source)) {
                    throw std::runtime_error("Source directory 'lists/lists' does not exist or is not a directory");
                }
                
                // Use copy_options to control the copy behavior
                std::filesystem::copy_options options = std::filesystem::copy_options::recursive | 
                                        std::filesystem::copy_options::overwrite_existing;
                std::filesystem::copy(source, destination, options);
            } catch (const std::filesystem::filesystem_error& e) {
                throw std::runtime_error("Failed to update local package lists: " + 
                                    std::string(e.what()));
            } catch (const std::exception& e) {
                throw std::runtime_error("Failed to update local package lists: " + 
                                    std::string(e.what()));
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