# FreeBSD port of Cemu - Wii U emulator

This is an unofficial FreeBSD port of Cemu, a Wii U emulator (https://cemu.info). Currently it requires a large number of patches to build on FreeBSD. As I refine this port, I may submit patches to upstream in the hope of promoting FreeBSD to a more easily buildable target.

In its current state, I disabled Wayland in order to get around build errors. This FreeBSD build of Cemu is capable of running both commercial and homebrew Wii U games. Both the Vulkan and OpenGL backends work on my NVIDIA GPU. Sound works as well.
