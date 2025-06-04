#include "../include/remove.hpp"

namespace cppkg::remove {

void remove(std::string package_name) {
    
    // 1. Construct full package path
    const std::filesystem::path pkg_dir = 
        std::filesystem::path(std::getenv("HOME")) / ".cppkg" / package_name;
    
    try {
        // 2. Verify package exists
        if (!std::filesystem::exists(pkg_dir)) {
            throw std::filesystem::filesystem_error(
                "Package not found",
                pkg_dir,
                std::make_error_code(std::errc::no_such_file_or_directory)
            );
        }

        // 3. Remove recursively
        std::filesystem::remove_all(pkg_dir);

        // 4. Verify removal succeeded
        if (std::filesystem::exists(pkg_dir)) {
            throw std::filesystem::filesystem_error(
                "Failed to completely remove package",
                pkg_dir,
                std::make_error_code(std::errc::operation_not_permitted)
            );
        }

    } catch (const std::filesystem::filesystem_error& e) {
        // Wrap filesystem errors with additional context
        throw std::filesystem::filesystem_error(
            "[cppkg::remove] " + std::string(e.what()),
            e.path1(),
            e.path2(),
            e.code()
        );
    }
}

} // namespace cppkg::remove