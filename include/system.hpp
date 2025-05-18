#pragma once

#include "includes.hpp"

namespace cppkg::sys {
    /**
     * @brief Enum class to specify the type of symbolic link to create.
     * 
     * - `FILE`: Creates a symbolic link to a file.
     * 
     * - `DIRECTORY`: Creates a symbolic link to a directory.
     * 
     * @note On Windows, file/directory symlinks are distinct and require correct type selection.
     */
    enum class symlink_type {
        FILE,     // Symbolic link to a file.
        DIRECTORY // Symbolic link to a directory.
    };
    /**
     * @brief Creates a symbolic link from `dest_path` to `src_path`.
     * 
     * @param src_path  Source path (the target the symlink will point to).
     * @param dest_path Destination path (where the symlink will be created).
     * @param type      Type of symlink (file or directory). Defaults to `FILE`.
     * 
     * @throws std::runtime_error If:
     * - `src_path` does not exist.
     * - Filesystem operations fail (e.g., permission denied, invalid paths).
     * 
     * @note On Unix-like systems, `create_symlink` works for both files and directories,
     *       but explicitly using `DIRECTORY` improves cross-platform compatibility.
     */
    void symlink(
        const std::string& headers_path,
        const std::string& dest_path,
        symlink_type type
    );
} // namespace cppkg::sys