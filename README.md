![Logo](./logo.ico)

# cppkg

A simple package manager what can manage some packages what are developed for C/C++.

## Install
- Use `git` to download the project and compile it.
```bash
git clone https://github.com/zhanghaoxvan/cppkg.git
cd cppkg
make 
```
- Download the binary from [Github](https://github.com/zhanghaoxvan/cppkg/releases).

## Usage
- `cppkg install <packages>` to install a package.
- - If you want to install packages by force(maybe because updates), input `cppkg install <packages> --force`.
- `cppkg install --local <local package files>` to install a local package
- - If you want to install packages by force too, input `cppkg install --local <local package files> --force`.
- `cppkg info <packages>` to show information of a package.
- `cppkg remove <packages>` to remove a package.
- `cppkg list` to list all installed packages.
- `cppkg search <package>` to search a package.
- `cppkg help` to show help information.
- `cppkg update` to update packages list

Don't forget to add `cppkg` to your `PATH` environment variable and use `sudo` when you install or remove packages.

## Implementation
- [x] `cppkg install <packages> [--force]`
- [x] `cppkg install --local <local package files> [--force]`
- [ ] `cppkg remove <packages>`
- [ ] `cppkg list`
- [ ] `cppkg search <package>`
- [x] `cppkg help`
- [ ] `cppkg update`


## Contributing
- Fork the project.
- Create a new branch.
- Commit your changes.
- Push to the branch.
- Create a new Pull Request.

## License
This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.
