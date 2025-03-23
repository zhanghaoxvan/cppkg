.PHONY: all clean help
all: main

# Use <filesystem> from C++17
main: ./src/main.cpp
	@echo "Compiling..."
	@mkdir -p ./bin
	@g++ ./src/main.cpp -o ./bin/cppkg -std=c++17
	@echo "Done."
clean:
	@echo "Cleaning..."
	@rm -f ./bin/cppkg
	@echo "Done."

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all      Build the program"
	@echo "  clean    Remove the compiled files"
	@echo "  help     Display this help message"