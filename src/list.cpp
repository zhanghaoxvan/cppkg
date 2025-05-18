#include "../include/list.hpp"

namespace cppkg::list {

    void list() {
        const auto cppkg_dir = std::filesystem::path(getenv("HOME")) / ".cppkg";
        
        // Create directory if it doesn't exist
        if (!std::filesystem::exists(cppkg_dir)) {
            std::filesystem::create_directory(cppkg_dir);
            std::cout << "No packages installed. ~/.cppkg directory created.\n";
            return;
        }

        std::cout << "Installed Packages:\n";
        
        try {
            size_t package_count = 0;
            for (const auto& entry : std::filesystem::directory_iterator(cppkg_dir)) {
                if (entry.is_directory() && entry.path().filename() != "bin") {
                    std::cout << "  • " << entry.path().filename().string() << "\n";
                    package_count++;
                }
            }

            if (package_count == 0) {
                std::cout << "  (No packages installed)\n";
            }

        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "\nError: Failed to list packages (" << e.what() << ")\n"
                    << "Possible solutions:\n"
                    << "  1. Run 'make remove' to reinstall\n"
                    << "  2. Manually check permissions for ~/.cppkg\n";
        }
    }

} // namespace cppkg::list