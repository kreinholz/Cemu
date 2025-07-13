# FreeBSD port of Cemu - Wii U emulator

This is an unofficial FreeBSD port of Cemu, a Wii U emulator (https://cemu.info). Currently it requires a large number of patches to build on FreeBSD. As I refine this port, I may submit patches to upstream in the hope of promoting FreeBSD to a more easily buildable target.

Cemu can be built with or without wayland support. I haven't tested it under wayland, only X11.

This FreeBSD build of Cemu is capable of running both commercial and homebrew Wii U games. Both the Vulkan and OpenGL backends work on my NVIDIA GPU. Sound works as well.

To build on FreeBSD (amd64 or aarch64):

Clone this repository:

git clone git@github.com:kreinholz/Cemu.git

cd Cemu

(Optionally: 'git switched forked' or 'git switch main')

sudo make install clean

(Alternatively, run 'make install clean' as root)

Note: the 'forked' branch incorporates my patches into the Cemu sources, matching my pull request to Cemu upstream. The 'main' branch is my original port with patches that apply to upstream Cemu sources at build time.
