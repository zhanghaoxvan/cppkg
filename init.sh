#!/bin/bash

#   Install
#      _                                     _                         _              
#   __| |   ___   _ __     ___   _ __     __| |   ___   _ __     ___  (_)   ___   ___ 
#  / _` |  / _ \ | '_ \   / _ \ | '_ \   / _` |  / _ \ | '_ \   / __| | |  / _ \ / __|
# | (_| | |  __/ | |_) | |  __/ | | | | | (_| | |  __/ | | | | | (__  | | |  __/ \__ \
#  \__,_|  \___| | .__/   \___| |_| |_|  \__,_|  \___| |_| |_|  \___| |_|  \___| |___/
#                |_|                                                                  

DISTRO=$(grep -Ei '^ID=' /etc/os-release | cut -d '=' -f 2 | tr -d '"')
case $DISTRO in
    "ubuntu" | "debian") PKG_MANAGER="apt" ;;
    "centos" | "rhel")
        if command -v dnf &> /dev/null; then
            PKG_MANAGER="dnf"
        else
            PKG_MANAGER="yum"
        fi
        ;;
    "fedora") PKG_MANAGER="dnf" ;;
    "arch") PKG_MANAGER="pacman" ;;
    "opensuse") PKG_MANAGER="zypper" ;;
    "alpine") PKG_MANAGER="apk" ;;
    *) echo "Unknown: $DISTRO"; exit 1 ;;
esac
pkg_install() {
    case $PKG_MANAGER in
        "apt")      sudo apt install -y "$@" ;;
        "dnf")      sudo dnf install -y "$@" ;;
        "yum")      sudo yum install -y "$@" ;;
        "pacman")   sudo pacman -S --noconfirm "$@" ;;
        "zypper")   sudo zypper install -y "$@" ;;
        "apk")      sudo apk add --no-cache "$@" ;;
        *)          echo "Unknown Command" ;;
    esac
}

printf "Install `unzip`..."
sudo $1 install unzip > /dev/null
if [ ! $? -eq 0 ]; then
    exit $?
fi
printf "Install `git`..."
sudo $1 install git > /dev/null
if [ $? -eq 0 ]; then
    exit $?
fi
# create floder
mkdir ~/.cppkg
mkdir ~/.cppkg/bin
# Add Path
echo "export PATH=~/.cppkg/:~/.cppkg/bin:$PATH" > ~/.bashrc
