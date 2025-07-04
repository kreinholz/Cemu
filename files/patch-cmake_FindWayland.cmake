--- cmake/FindWayland.cmake.orig	2025-07-04 04:26:47 UTC
+++ cmake/FindWayland.cmake
@@ -117,6 +117,9 @@ find_package_handle_standard_args(Wayland
     HANDLE_COMPONENTS
 )
 
+file(COPY ${Wayland_INCLUDE_DIRS}/wayland-client.h DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
+file(COPY ${Wayland_INCLUDE_DIRS}/wayland-util.h DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
+
 pkg_get_variable(Wayland_DATADIR wayland-scanner pkgdatadir)
 if (CMAKE_CROSSCOMPILING AND (NOT EXISTS "${Wayland_DATADIR}/wayland.xml"))
     # PKG_CONFIG_SYSROOT_DIR only applies to -I and -L flags, so pkg-config
