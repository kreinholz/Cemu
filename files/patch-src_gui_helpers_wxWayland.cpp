--- src/gui/helpers/wxWayland.cpp.orig	2025-06-27 17:47:18 UTC
+++ src/gui/helpers/wxWayland.cpp
@@ -1,6 +1,6 @@
 #include "gui/helpers/wxWayland.h"
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 
 #include <dlfcn.h>
 
