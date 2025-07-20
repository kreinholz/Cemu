--- BUILD.md.orig	2025-07-20 11:44:07.638650000 -0700
+++ BUILD.md	2025-07-20 10:18:33.770451000 -0700
@@ -20,6 +20,9 @@
    - [Installing Tool Dependencies](#installing-tool-dependencies)
    - [Installing Library Dependencies](#installing-library-dependencies)
    - [Build Cemu using CMake](#build-cemu-using-cmake)
+- [FreeBSD](#freebsd)
+	- [Dependencies](#dependencies)
+	- [Build Cemu](#build-cemu)
 - [Updating Cemu and source code](#updating-cemu-and-source-code)
 
 ## Windows
@@ -184,6 +187,33 @@
 
 #### Troubleshooting steps
 - If step 3 gives you an error about not being able to find ninja, try appending `-DCMAKE_MAKE_PROGRAM=/usr/local/bin/ninja` to the command and running it again.
+
+## FreeBSD
+
+The following instructions to build Cemu on FreeBSD are experimental. Some features available on other platforms are not available on FreeBSD (discord rich presence, bluetooth/support for actual Wii U controllers, auto-updates, etc.)
+
+To compile Cemu, a recent enough compiler and STL with C++20 support is required! Clang-15 or higher is what we recommend. Any version of FreeBSD 13.3-RELEASE or higher comes bundled with LLVM > version 15 as part of the base system. However, if for whatever reason your system lacks a recent version of LLVM you can install one by executing:
+
+`sudo pkg install llvm15`
+
+Or a higher version as desired.
+
+### Dependencies
+
+`sudo pkg install boost-libs cmake-core curl glslang gtk3 ninja png pkgconf rapidjson wayland wayland-protocols wx32-gtk3 xorg zstd`
+
+### Build Cemu
+
+```
+git clone --recursive https://github.com/cemu-project/Cemu
+cd Cemu
+cmake -B build -DCMAKE_BUILD_TYPE=release -DENABLE_BLUEZ=OFF -DENABLE_DISCORD_RPC=OFF -DENABLE_FERAL_GAMEMODE=OFF -DENABLE_HIDAPI=OFF -DENABLE_VCPKG=OFF -G Ninja
+cmake --build build
+
+cd build && ninja install
+```
+
+You should now have a Cemu executable file in the /bin folder, which you can run using `./bin/Cemu_release`.
 
 ## Updating Cemu and source code
 1. To update your Cemu local repository, use the command `git pull --recurse-submodules` (run this command on the Cemu root).
