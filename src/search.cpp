#include "../include/search.hpp"
#include "../include/update.hpp"

namespace cppkg::search {

    void search(const std::string& term) {
        try {
            // Step 1: Update the package list and ensure the latest data is available
            cppkg::update::update_packages_list(); // Now, the latest `lists` file is available and
                                                   // stored in `~/.cppkg/lists/lists`
            const std::string lists_path =
                std::string((std::filesystem::path(getenv("HOME")) / ".cppkg" / "lists" / "lists").string());
            // Step 2: Open the lists file for reading
            std::ifstream lists_file(lists_path);
            if (!lists_file.is_open()) {
                throw std::runtime_error("Failed to open the lists file: " + lists_path);
            }
            // Step 3: Read the file line by line and search for the term
            std::string line;
            bool found = false;
            while (std::getline(lists_file, line)) {
                // Check if the line contains the search term
                if (line.find(term) != std::string::npos) {
                    std::cout << line << std::endl; // Print the matching package name
                    found = true;
                }
            }
            if (!found) {
                std::cout << "No packages found matching the term: " << term << std::endl;
            }
            // Step 4: Close the file
            lists_file.close();
        } catch (const std::exception& e) {
            throw std::runtime_error("Something went wrong while searching for packages:" + std::string(e.what()));
        }
    }

}
