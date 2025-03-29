#!/bin/bash

# Get The Library which `cppkg` relyed.

if [ $# -eq 1 ]; then # $ init.sh
    echo "sh init.sh <System>"
    echo "For example:"
    echo "test@ubuntu:~$ sh init.sh ubuntu"
    echo "Supported Systems:"
    echo "    ubuntu"    # use `apt`
    echo "    debian"    # use `apt`
    echo "    centos"    # use `yum`
    echo "    rhel"      # use `yum`
    echo "    fedora"    # use `dnf`
    echo "    arch"      # use `pacman`
    echo "    manjaro"   # use `pacman`
    echo "    opensuse"  # use `zypper`
    echo "    alpine"    # use `apk`
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
            echo "Unsupported system: $1"
            echo "Input your package manager:"
            read package_manager
            ;;
    esac
    sudo $package_manager install unzip # unzip package
fi
