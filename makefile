.PHONY: all clean help

# Use <filesystem> from C++17
all: ./src/main.cpp
	@mkdir -p ./bin
	@g++ ./src/main.cpp -o ./bin/cppkg -std=c++17
clean:
	@rm -f ./bin/cppkg

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all      Build the program"
	@echo "  clean    Remove the compiled files"
	@echo "  help     Display this help message"
