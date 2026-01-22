## Example of displaying japanese in Raylib

<img width="802" height="477" alt="pic" src="https://github.com/user-attachments/assets/e82a785a-70ad-45ce-ada7-c1af60f6c39a" />

## How to build
### Windows (MSVC)
```bash
# Debug Build
$ script\build_msvc.bat
# Release Build
$ script\build_msvc.bat --release

# Build and Run
$ call script\build_msvc.bat && bin\debug\app.exe
```

### Windows (Mingw-w64/MSYS2)
```bash
# Debug Build
$ ./script/build_mingw64.sh
# Release Build
$ ./script/build_mingw64.sh --release

# Build and Run
$ ./script/build_mingw64.sh && ./bin/debug/app.exe
```

### WSL2 or Linux
```bash
# Debug Build
$ ./script/build_linux.sh
# Release Build
$ ./script/build_linux.sh --release

# Build and Run
$ ./script/build_linux.sh && ./bin/debug/app
```
