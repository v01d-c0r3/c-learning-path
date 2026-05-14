# Lesson: CMake, shared/static libs & cross-compilation

## Why CMake?

Makefiles become unmaintainable on large projects. CMake generates Makefiles (or Ninja files) for you, handles dependencies, and works cross-platform.

## Minimal CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyProject C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Static library
add_library(mylib STATIC mylib.c)

# Executable
add_executable(myapp main.c)
target_link_libraries(myapp mylib)
```

## Building

```bash
mkdir build && cd build
cmake ..          # generate build system
make              # build everything
```

Always build out-of-source (in a `build/` directory) to keep source tree clean.

## Static vs shared libraries

**Static (`.a`)** — code is copied into the executable at link time. Bigger binary, no runtime dependency.

**Shared (`.so`)** — code lives in a separate file, loaded at runtime. Smaller binary, can be updated independently.

```cmake
add_library(mylib_static STATIC mylib.c)   # produces libmylib_static.a
add_library(mylib_shared SHARED mylib.c)   # produces libmylib_shared.so
```

```bash
# Link shared library manually:
gcc -L. -lmylib -o app main.c
LD_LIBRARY_PATH=. ./app   # tell loader where to find the .so
```

## Install targets

```cmake
install(TARGETS mylib myapp
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)
install(FILES mylib.h DESTINATION include)
```

## Cross-compilation toolchain file

```cmake
# arm-toolchain.cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
```

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=arm-toolchain.cmake ..
```

---

## My notes

**What confused me:**

**What clicked:**

**Static vs shared — when to use each:**

**Things to look up later:**
