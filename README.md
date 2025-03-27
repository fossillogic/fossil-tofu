# ***ToFu Data Structures and Algorithms Library by Fossil Logic***

ToFu is a versatile, platform-independent library offering a comprehensive suite of data structures, algorithms, and a generic Tofu type, all designed to facilitate high-performance and reliable software development. Written in both C and C++, ToFu is engineered to deliver optimal performance across a wide range of operating systems. The library employs the Meson build system, ensuring a streamlined development and deployment process.

## Key Features

1. **Cross-Platform Compatibility**: Ensures consistent performance and functionality across major operating systems, including Windows, macOS, and Linux.
2. **Modular Design**: Provides a suite of modular components that can be easily integrated and customized to suit specific project needs.
3. **Efficient Build System**: Utilizes the Meson build system for its C and C++ components, known for fast build times and a user-friendly syntax.
4. **High Performance**: Implemented in C and C++ to maximize performance and resource efficiency, suitable for both desktop and embedded applications.
5. **Extensive Documentation and Examples**: Includes comprehensive documentation and example code to help developers get started quickly and effectively.

## Generic Tofu Type

ToFu introduces the `fossil_tofu_t` type, a generic container type that supports various operations:

- **Creation**: Functions to create and initialize `fossil_tofu_t` objects.
- **Memorization**: Caching mechanisms to improve performance.
- **Printing and Destruction**: Utility functions for output and memory management.
- **Comparison and Copying**: Utilities for comparing and duplicating `fossil_tofu_t` objects.

## Algorithms and Utilities

ToFu provides a rich set of algorithms and utility functions:

- **Transformation and Accumulation**: Functions for transforming and accumulating data in arrays.
- **Filtering and Searching**: Capabilities for filtering elements and searching with custom predicates.
- **Array Operations**: Includes reversing, swapping, and shuffling array elements.
- **Iterator Support**: Provides iterator functionality for traversing data structures.
- **Memory Management**: Includes custom allocation, reallocation, and free functions.
- **String Operations**: Utility functions like `fossil_tofu_strdup` for string manipulation.

## Prerequisites

To get started with Fossil ToFu, ensure you have the following installed:

- **Meson Build System**: If you don’t have Meson installed, follow the installation instructions on the official [Meson website](https://mesonbuild.com/Getting-meson.html).
- **CMake Build System**: If you don’t have CMake installed, follow the installation instructions on the official [CMake website](https://cmake.org/getting-started/).

### Adding Fossil Tofu Dependency

#### Adding Fossil Tofu Dependency With Meson

1. **Install Meson Build System**:
   Install Meson version `1.3` or newer:
   ```sh
   python -m pip install meson           # To install Meson
   python -m pip install --upgrade meson # To upgrade Meson
   ```

2. **Create a `.wrap` File**:
   Add the `fossil-tofu.wrap` file in your `subprojects` directory and include the following content:

   ```ini
   # ======================
   # Git Wrap package definition
   # ======================
   [wrap-git]
   url = https://github.com/fossillogic/fossil-tofu.git
   revision = v0.1.8

   [provide]
   fossil-tofu = fossil_tofu_dep
   ```

3. **Integrate the Dependency**:
   In your `meson.build` file, integrate Fossil Tofu by adding the following line:
   ```ini
   dep = dependency('fossil-tofu')
   ```

---

#### Adding Fossil Test Dependency With CMake

To use Fossil Tofu with CMake, follow these steps:

1. **Install CMake**:
   Install CMake version `3.13.4` or newer:

   ```sh
   python -m pip install cmake           # To install CMake
   python -m pip install --upgrade cmake # To upgrade CMake
   ```

2. **Find and Integrate Fossil Tofu**:
   After installing CMake, you can integrate Fossil Tofu as a dependency. Add the following lines to your `CMakeLists.txt` file:

   ```cmake
   # Find Fossil Tofu package
   find_package(FossilTofu REQUIRED)

   # Link the Fossil Tofu to your project
   target_link_libraries(your_target FossilTofu)
   ```

3. **Configure Your CMake Project**:
   Make sure to configure your CMake project to include the necessary paths and dependencies for Fossil Tofu. Typically, you’ll want to make sure the `FossilTofu` library is correctly linked in your build configuration.

   This will ensure that Fossil Tofu is included and properly built with your project.

---

**Note**: For the best experience, always use the latest release of Fossil Test. Visit the [Fossil ToFu Releases](https://github.com/fossillogic/fossil-tofu/releases) page for the latest versions.

## Configure Options

ToFu offers configurable options to tailor the build process to your needs:

- **Running Tests**: To enable testing, configure the build with `-Dwith_test=enabled`.

Example:

```sh
meson setup builddir -Dwith_test=enabled
```

## Contributing and Support

For those interested in contributing, reporting issues, or seeking support, please open an issue on the project repository or visit the [Fossil Logic Docs](https://fossillogic.com/docs) for more information. Your feedback and contributions are always welcome.
