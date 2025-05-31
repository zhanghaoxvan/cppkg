![Logo](./logo.ico)

# cppkg

A simple package manager what can manage some packages what are developed for C/C++.

## Install
1. Use `git` to download the project.
```bash
git clone --depth=1 https://github.com/zhanghaoxvan/cppkg.git
```
2. Enter the `cppkg` directory.
```bash
cd cppkg
```
3. Compile it.
```bash
make
```
4. Install `cppkg` in your computer.
```bash
make install
```
## Usage
### Install a Package
- If you want to install a package such as `test-pkg`, you can input this prompt and install it.
```bash
cppkg install test-pkg
```
- If you want to update a package(`test-pkg`), you need to add a `--force` option:
```bash
cppkg install test-pkg --force
```
- If you have a Package File(`test-pkg.cppkg`), you can install it like this.
```bash
cppkg install --local test-pkg.cppkg
```
- If you have a newer package file(`test-pkg.cppkg`) and want to update your package with it, add `--force`:
```bash
cppkg install --local test-pkg.cppkg --force
```
You can install more packages at once.
### Get Information of a Package
- If you want to get Information of a package(`test-pkg`), use:

  ```bash
  cppkg info test-pkg
  ```

  

### Remove a Package
- If you want to remove a package(`test-pkg`), enter this:

  ```bash
  cppkg remove test-pkg
  ```

  You can remove more packages at once.

### List Installed Packages

- Use Like this:

  ```bash
  cppkg list
  ```

  

### Search a Package on Web

- Enter this(e.g. search `test-pkg`):

  ```bash
  cppkg search test-pkg
  ```

### Show Help
- Use This:

  ```bash
  cppkg help
  ```

  

  ### Update [`lists`](https://github.com/zhanghaoxvan/cppkg-packages/blob/main/lists)

  - Enter:

    ```bash
    cppkg update
    ```

    

<div style="
  --light-bg:#ddf4ff; --light-border:#84d8ff; --light-text:#0969da; --light-bar:#218bff;
  --dark-bg:#0c2d6b; --dark-border:#1c4a8a; --dark-text:#e6f0ff; --dark-bar:#3d8bf0;
  position:relative;padding:12px 16px;margin:16px 0;border-radius:6px;
  font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',Helvetica,Arial,sans-serif;
  font-size:14px;line-height:1.5;
  border:1px solid var(--light-border);background:var(--light-bg);color:var(--light-text);
  @media (prefers-color-scheme: dark) {
    border-color:var(--dark-border);background:var(--dark-bg);color:var(--dark-text)
  }
">
  <div style="
    position:absolute;top:0;bottom:0;left:0;width:4px;border-radius:6px 0 0 6px;
    background:var(--light-bar);
    @media (prefers-color-scheme: dark) { background:var(--dark-bar) }
  "></div>
  <div style="font-weight:600;margin-bottom:4px;display:flex;align-items:center">
    <span style="margin-right:8px">ℹ️</span><span>Note</span>
  </div>
  <p style="margin:0">Don't forget to add `cppkg` to your `PATH` environment variable and use `sudo` when you install or remove packages.</p>
</div>

## Implementation
- [x] `cppkg install <packages> [--force]`
- [x] `cppkg install --local <local package files> [--force]`
- [x] `cppkg remove <packages>`
- [x] `cppkg list`
- [x] `cppkg search <packages>`
- [x] `cppkg help`
- [x] `cppkg update`


## Contributing
- Fork the project.
- Create a new branch.
- Commit your changes.
- Push to the branch.
- Create a new Pull Request.

## License
This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.
