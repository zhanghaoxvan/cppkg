# Cross-platform Makefile for Windows MSYS and Unix-like systems

.PHONY: all clean help install uninstall

# Detect OS
ifeq ($(OS),Windows_NT)
export LANG := en_US.UTF-8
    DETECTED_OS := Windows
    MKDIR := mkdir -p
    RMDIR := rm -rf
    CP := cp
    BIN_EXT := .exe
    HOME_DIR := $(shell echo ${HOME})
    INSTALL_DIR := $(HOME_DIR)/.cppkg/bin
    LDFLAGS := -static -lstdc++ -lstdc++fs -lwinpthread
else
    DETECTED_OS := $(shell uname -s)
    MKDIR := mkdir -p
    RMDIR := rm -rf
    CP := cp
    BIN_EXT :=
    HOME_DIR := $(shell echo ${HOME})
    INSTALL_DIR := $(HOME_DIR)/.cppkg/bin
    LDFLAGS := -lstdc++fs
endif
# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# Files and directories
SRC_DIR := ./src
BIN_DIR := ./bin
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
TARGET := $(BIN_DIR)/cppkg$(BIN_EXT)

all: $(SRCS)
	@$(MKDIR) $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	@echo "[$(DETECTED_OS)] Build successful: $@"

clean:
	@$(RMDIR) $(BIN_DIR)
	@echo "Cleaned build directory"

help:
	@printf "%s\n" \
	"                         _            " \
	"   ___   _ __    _ __   | | __   __ _ " \
	"  / __| | '_ \  | '_ \  | |/ /  / _\`|" \
	" | (__  | |_) | | |_) | |   <  | (_| |" \
	"  \___| | .__/  | .__/  |_|\_\  \__, |" \
	"        |_|     |_|             |___/ "
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all        Build cppkg (default target)"
	@echo "  clean      Clean build files"
	@echo "  help       Show this help message"
	@echo "  install    Install cppkg system-wide"
	@echo "  uninstall  Uninstall cppkg"
	@echo ""
	@echo "Detected system: $(DETECTED_OS)"

install: $(TARGET)
	@$(MKDIR) $(INSTALL_DIR)
	@$(CP) $(TARGET) $(INSTALL_DIR)/
	@echo "Successfully installed!"
ifeq ($(DETECTED_OS),Windows)
	@echo "For Windows users:"
	@echo "1. Add this path to your system PATH environment variable:"
	@echo "   $(INSTALL_DIR)"
	@echo "2. Or add to your MSYS2 ~/.bashrc:"
	@echo "   export PATH=\"$(INSTALL_DIR):\$$PATH\""
else
	@echo "For Unix users:"
	@echo "Add this to your shell config (~/.bashrc, ~/.zshrc, etc):"
	@echo "export PATH=\"$$HOME/.cppkg/bin:\$$PATH\""
endif

uninstall:
	@$(RMDIR) $(HOME_DIR)/.cppkg
	@echo "Uninstalled cppkg and removed $(HOME_DIR)/.cppkg"
	@echo "Please manually remove the path from your PATH variable"
