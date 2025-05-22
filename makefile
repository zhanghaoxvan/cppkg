.PHONY: all clean help install remove

# Use <filesystem> from C++17
all: ./src/*.cpp
	@mkdir -p ./bin
	@g++ $^ -o ./bin/cppkg -std=c++17
clean:
	@rm -f ./bin/cppkg
help:
	@echo -e "                         _            \n   ___   _ __    _ __   | | __   __ _ \n  / __| | '_ \  | '_ \  | |/ /  / _\` |\n | (__  | |_) | | |_) | |   <  | (_| |\n  \___| | .__/  | .__/  |_|\_\  \\__, |\n        |_|     |_|             |___/ "
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all      Build cppkg"
	@echo "  clean    Remove ./bin/cppkg"
	@echo "  help     Display this help message"
	@echo "  install  Install cppkg in your computer"
install:
	@mkdir -p ~/.cppkg
	@cp ./bin/cppkg ~/.cppkg/cppkg
	@sh init.sh
remove:
	@sh uninstall.sh