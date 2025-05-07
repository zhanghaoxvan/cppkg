.PHONY: all clean help install

# Use <filesystem> from C++17
all: ./src/*.cpp
	@mkdir -p ./bin
	@g++ $^ -o ./bin/cppkg -std=c++17
clean:
	@rm -f ./bin/cppkg
help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all      Build the program"
	@echo "  clean    Remove the compiled files"
	@echo "  help     Display this help message"
install:
	ifeq ($(OS), Windows_NT)
# Windows
		powershell .\init.ps1
	else
# Linux
		bash -c .\init.sh
