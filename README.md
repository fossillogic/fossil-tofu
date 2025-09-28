# ***ToFu Data Structures and Algorithms Library by Fossil Logic***

ToFu is a versatile, platform-independent library offering a comprehensive suite of data structures, algorithms, and a generic Tofu type, all designed to facilitate high-performance and reliable software development. Written in both C and C++, ToFu is engineered to deliver optimal performance across a wide range of operating systems. The library employs the Meson build system, ensuring a streamlined development and deployment process.

## Key Features

1. **Cross-Platform Compatibility**: Ensures consistent performance and functionality across major operating systems, including Windows, macOS, and Linux.
2. **Modular Design**: Provides a suite of modular components that can be easily integrated and customized to suit specific project needs.
3. **Efficient Build System**: Utilizes the Meson build system for its C and C++ components, known for fast build times and a user-friendly syntax.
4. **High Performance**: Implemented in C and C++ to maximize performance and resource efficiency, suitable for both desktop and embedded applications.
5. **Extensive Documentation and Examples**: Includes comprehensive documentation and example code to help developers get started quickly and effectively.

## ***Prerequisites***

To get started, ensure you have the following installed:

- **Meson Build System**: If you don’t have Meson `1.8.0` or newer installed, follow the installation instructions on the official [Meson website](https://mesonbuild.com/Getting-meson.html).

### Adding Dependency

#### Adding via Meson Git Wrap

To add a git-wrap, place a `.wrap` file in `subprojects` with the Git repo URL and revision, then use `dependency('fossil-tofu')` in `meson.build` so Meson can fetch and build it automatically.

#### Integrate the Dependency:

Add the `fossil-tofu.wrap` file in your `subprojects` directory and include the following content:

```ini
[wrap-git]
url = https://github.com/fossillogic/fossil-tofu.git
revision = v0.2.4

[provide]
dependency_names = fossil-tofu
```

**Note**: For the best experience, always use the latest releases. Visit the [releases](https://github.com/fossillogic/fossil-tofu/releases) page for the latest versions.

## Configure Options

ToFu offers configurable options to tailor the build process to your needs:

- **Running Tests**: To enable testing, configure the build with `-Dwith_test=enabled`.

Example:

```sh
meson setup builddir -Dwith_test=enabled
```

### Tests Double as Samples

The project is designed so that **test cases serve two purposes**:

- ✅ **Unit Tests** – validate the framework’s correctness.  
- 📖 **Usage Samples** – demonstrate how to use these libraries through test cases.  

This approach keeps the codebase compact and avoids redundant “hello world” style examples.  
Instead, the same code that proves correctness also teaches usage.  

This mirrors the **Meson build system** itself, which tests its own functionality by using Meson to test Meson.  
In the same way, Fossil Logic validates itself by demonstrating real-world usage in its own tests via Fossil Test.  

```bash
meson test -C builddir -v
```

Running the test suite gives you both verification and practical examples you can learn from.

## Contributing and Support

For those interested in contributing, reporting issues, or seeking support, please open an issue on the project repository or visit the [Fossil Logic Docs](https://fossillogic.com/docs) for more information. Your feedback and contributions are always welcome.
