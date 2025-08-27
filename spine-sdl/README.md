# spine-sdl

The spine-sdl runtime provides functionality to load, manipulate and render [Spine](http://esotericsoftware.com) skeletal animation data using [SDL](https://www.libsdl.org/). spine-sdl is based on [spine-c](../spine-c) and [spine-cpp](../spine-cpp). Note that spine-c depends on spine-cpp, so both are required regardless of which API you choose to use.

# See the [spine-sdl documentation](http://esotericsoftware.com/spine-documentation#runtimes) for in-depth information

## Licensing

You are welcome to evaluate the Spine Runtimes and the examples we provide in this repository free of charge.

You can integrate the Spine Runtimes into your software free of charge, but users of your software must have their own [Spine license](https://esotericsoftware.com/spine-purchase). Please make your users aware of this requirement! This option is often chosen by those making development tools, such as an SDK, game toolkit, or software library.

In order to distribute your software containing the Spine Runtimes to others that don't have a Spine license, you need a [Spine license](https://esotericsoftware.com/spine-purchase) at the time of integration. Then you can distribute your software containing the Spine Runtimes however you like, provided others don't modify it or use it to create new software. If others want to do that, they'll need their own Spine license.

For the official legal terms governing the Spine Runtimes, please read the [Spine Runtimes License Agreement](http://esotericsoftware.com/spine-runtimes-license) and Section 2 of the [Spine Editor License Agreement](http://esotericsoftware.com/spine-editor-license#s2).

## Spine version

spine-sdl works with data exported from Spine 4.3.xx.

spine-sdl supports all Spine features except screen blend mode and two color tinting.

## Usage

### Integration with CMake (Recommended)

The easiest way to integrate spine-sdl into your project is via CMake FetchContent:

```cmake
include(FetchContent)
FetchContent_Declare(
    spine-sdl
    GIT_REPOSITORY https://github.com/esotericsoftware/spine-runtimes.git
    GIT_TAG 4.3
    SOURCE_SUBDIR spine-sdl
)
FetchContent_MakeAvailable(spine-sdl)

# For C API
target_link_libraries(your_target spine-sdl-c)

# For C++ API
target_link_libraries(your_target spine-sdl-cpp)
```

This will automatically fetch and build spine-sdl along with its dependencies (spine-c, spine-cpp, and SDL).

### Manual Integration

If you prefer manual integration:

1. Download the Spine Runtimes source using git (`git clone https://github.com/esotericsoftware/spine-runtimes`) or download it as a zip.
2. Add the required source files to your project:
   - For C API: Add sources from `spine-cpp/src`, `spine-c/src`, and `spine-sdl/src/spine-sdl-c.c`
   - For C++ API: Add sources from `spine-cpp/src`, `spine-c/src`, and `spine-sdl/src/spine-sdl-cpp.cpp`
3. Add the include directories: `spine-cpp/include`, `spine-c/include`, and `spine-sdl/src`
4. Link against SDL2

See the [Spine Runtimes documentation](http://esotericsoftware.com/spine-documentation#runtimes) for detailed API usage.

## Examples

The repository includes example code for both C and C++ APIs:
- C example: [example/main.c](example/main.c)
- C++ example: [example/main.cpp](example/main.cpp)

### Building the Examples

### Windows

1. Install [Visual Studio Community](https://visualstudio.microsoft.com/downloads/) with C++ support and Windows SDK.
2. Install [CMake](https://cmake.org/download/) via the Windows installer package.
3. Clone the repository: `git clone https://github.com/esotericsoftware/spine-runtimes`
4. Run CMake GUI from the start menu
5. Set source directory to `spine-runtimes/spine-sdl`
6. Set build directory to `spine-runtimes/spine-sdl/build`
7. Click `Configure`, then `Generate`
8. Open the generated solution in Visual Studio
9. Set `spine-sdl-c-example` or `spine-sdl-cpp-example` as the startup project
10. Run the project

### Linux

1. Install dependencies:
   ```bash
   sudo apt-get install cmake ninja-build  # Ubuntu/Debian
   # or equivalent for your distribution
   ```
2. Clone the repository: `git clone https://github.com/esotericsoftware/spine-runtimes`
3. Build and run:
   ```bash
   cd spine-runtimes/spine-sdl
   ./build.sh
   ./build/debug/spine-sdl-c-example    # Run C example
   ./build/debug/spine-sdl-cpp-example  # Run C++ example
   ```

### macOS

1. Install [Xcode](https://developer.apple.com/xcode/)
2. Install [Homebrew](http://brew.sh/)
3. Install dependencies:
   ```bash
   brew install cmake ninja
   ```
4. Clone the repository: `git clone https://github.com/esotericsoftware/spine-runtimes`
5. Build and run:
   ```bash
   cd spine-runtimes/spine-sdl
   ./build.sh
   ./build/debug/spine-sdl-c-example    # Run C example
   ./build/debug/spine-sdl-cpp-example  # Run C++ example
   ```