# FreeBSD port of Cemu - Wii U emulator

This is an unofficial FreeBSD port of Cemu, a Wii U emulator (https://cemu.info). On this branch, I build Cemu against my fork of the upstream Cemu repository, so no patches are necessary to get it to build on FreeBSD.

Cemu can be built with or without wayland support. I haven't tested it under wayland, only X11.

This FreeBSD build of Cemu is capable of running both commercial and homebrew Wii U games. Both the Vulkan and OpenGL backends work on my NVIDIA GPU. Sound works as well.
