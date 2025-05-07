#!/bin/bash

# Install dependencies

if [ $# -lt 1 ]; then # $ init.sh
    printf "sh init.sh <Package Manager>"
    printf "For example:"
    printf "test@ubuntu:~$ sh init.sh apt"
    exit
else
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
fi
# Add Path
echo "export PATH=~/.cppkg/cppkg:$PATH" > ~/.bashrc
