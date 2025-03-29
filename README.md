![Logo](logo.ico)

# cppkg

A simple package manager what can manage some packages what are developed for C/C++.

## Install
- Use `git` to download the project and compile it.
```bash
git clone https://github.com/zhanghaoxvan/cppkg.git
cd cppkg
make 
```
- Download the binary from [zhanghaoxvan.top](http://zhanghaoxvan.top/cppkg/) or [Github](https://github.com/zhanghaoxvan/cppkg/releases).

## Usage
- `cppkg install <package>` to install a package.
- `cppkg install --local <local package file>` to install a local package
- `cppkg remove <package>` to remove a package.
- `cppkg list` to list all installed packages.
- `cppkg search <package>` to search a package.
- `cppkg help` to show help information.
- `cppkg version` to show version information.

Don't forget to add `cppkg` to your `PATH` environment variable and use `sudo` when you install or remove packages.

## Contributing
- Fork the project.
- Create a new branch.
- Commit your changes.
- Push to the branch.
- Create a new Pull Request.

## License
This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.
