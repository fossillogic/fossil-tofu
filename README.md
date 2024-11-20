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

Before using ToFu, ensure you have the following installed:

- **Meson Build System**: This project requires Meson. If it's not already installed, you can follow the [installation instructions on the Meson website](https://mesonbuild.com/Getting-meson.html).

## Adding Dependency

1. **Install Meson Build System**: Ensure that Meson `1.3` or newer is installed on your system. You can install or upgrade it using pip:

   ```sh
   python -m pip install meson           # to install Meson
   python -m pip install --upgrade meson # to upgrade Meson
   ```

2. **Adding Wrap File**: Navigate to the `subprojects` directory and create a `.wrap` file, such as `fossil-tofu.wrap`, with the following content:

   ```ini
   # ======================
   # Git Wrap package definition
   # ======================
   [wrap-git]
   url = https://github.com/fossillogic/fossil-tofu.git
   revision = v0.1.6

   [provide]
   fossil-tofu = fossil_tofu_dep
   ```

3. **Integrate the New Dependency**: To integrate the dependency into your Meson project, add the following line to your `meson.build` file:

   ```ini
   dep = dependency('fossil-tofu')
   ```

   This line imports the `fossil-tofu` dependency, making it available for use in your project.

## Configure Options

ToFu offers configurable options to tailor the build process to your needs:

- **Running Tests**: To enable testing, configure the build with `-Dwith_test=enabled`.

Example:

```sh
meson setup builddir -Dwith_test=enabled
```

## Contributing and Support

For those interested in contributing, reporting issues, or seeking support, please open an issue on the project repository or visit the [Fossil Logic Docs](https://fossillogic.com/docs) for more information. Your feedback and contributions are always welcome.
