#include "includes.hpp"

namespace cppkg::search {
    /**
     * @brief Searches for packages in the remote repository
     * 
     * This function:
     * 
     * 1. Queries the remote repository for packages matching the search term.
     * 
     * 2. Open the `lists` file located at `~/.cppkg/lists/lists` to read the package names.
     * 
     * 3. Displays the results, including package names.
     * 
     * 4. Closes the file after reading.
     * 
     * @param term The search term to look for in package names and descriptions
     * @throws std::runtime_error If the search operation fails (e.g., network issues).
     * @note Requires Git and network access and `cppkg update` function.
     */
    void search(const std::string& term);
}