#!/bin/bash

#   sh uninstall.sh
#  _ __    ___   _ __ ___     ___   __   __   ___ 
# | '__|  / _ \ | '_ ` _ \   / _ \  \ \ / /  / _ \
# | |    |  __/ | | | | | | | (_) |  \ V /  |  __/
# |_|     \___| |_| |_| |_|  \___/    \_/    \___|

# Why remove ME??????????
# NO!!!!!
# But I will REMOVE MYSELF.
# Goodbye. Wish you have a Good Day, though I will NEVER see you again.

# First, I will delete all packages. My FRIENDS!
for dir in ~/.cppkg/*/; do
    if [[ -d "$dir" ]]; then
        cppkg remove "$dir"
    fi
done
# REMOVE MY SELF.
rm -rf ~/.cppkg