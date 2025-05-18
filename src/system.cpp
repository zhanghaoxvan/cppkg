#include "../include/system.hpp"

namespace cppkg::sys {
    void symlink(
        const std::string& src_path,
        const std::string& dest_path,
        symlink_type type
    ) {
        try {
            const std::filesystem::path src(src_path);
            const std::filesystem::path dest(dest_path);

            // Validate that the source path exists.
            if (std::filesystem::exists(src)) {
                throw std::runtime_error("Source path does not exist: " + src_path);
            }

            // Create the appropriate type of symlink.
            if (type == symlink_type::DIRECTORY) {
                std::filesystem::create_directory_symlink(src, dest);  // Directory symlink.
            } else {
                std::filesystem::create_symlink(src, dest);           // File symlink.
            }

        } catch (const std::filesystem::filesystem_error& e) {
            // Wrap filesystem-specific errors in a runtime_error for consistent handling.
            throw std::runtime_error("Failed to create symlink: " + std::string(e.what()));
        }
    }
} // namespace cppkg::sys