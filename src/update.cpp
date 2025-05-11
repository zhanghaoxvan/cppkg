#include "../include/update.hpp"

void cppkg::update::update_packages_list() {
    system("git archive --remote=https://github.com/cppkg-packages/lists --format=zip --output=lists.zip");
    system("unzip lists.zip");
    system("cp lists/lists ~/.cppkg/lists");
    system("rm -rf lists lists.zip");
}