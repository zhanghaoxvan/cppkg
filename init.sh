#!/bin/bash

# Install dependencies
if [ ! -e "~/cppkginit" ]; then
    if [ $# -lt 1 ]; then # $ init.sh
        printf "sh init.sh <System>"
        printf "For example:"
        printf "test@ubuntu:~$ sh init.sh ubuntu"
        printf "Supported Systems:"
        printf "    ubuntu"    # use `apt`
        printf "    debian"    # use `apt`
        printf "    centos"    # use `yum`
        printf "    rhel"      # use `yum`
        printf "    fedora"    # use `dnf`
        printf "    arch"      # use `pacman`
        printf "    manjaro"   # use `pacman`
        printf "    opensuse"  # use `zypper`
        printf "    alpine"    # use `apk`
        exit
    else
        package_manager=
        case "$1" in
            ubuntu|debian)
                package_manager="apt"
                ;;
            centos|rhel)
                package_manager="yum"
                ;;
            fedora)
                package_manager="dnf"
                ;;
            arch|manjaro)
                package_manager="pacman"
                ;;
            opensuse)
                package_manager="zypper"
                ;;
            alpine)
                package_manager="apk"
                ;;
            *)
                printf "Unsupported system: $1"
                printf "Input your package manager:"
                read package_manager
                ;;
        esac
        printf "Install `unzip`..."
        sudo $package_manager install unzip
        if [ ! $? -eq 0 ]; then
            exit $?
        fi
        printf "Install `git`..."
        sudo $package_manager install git
        if [ $? -eq 0 ]; then
            exit $?
        fi
    fi
fi
