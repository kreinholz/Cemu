--- src/gui/wxgui/helpers/wxWayland.cpp.orig	2025-07-20 11:44:08.011428000 -0700
+++ src/gui/wxgui/helpers/wxWayland.cpp	2025-07-19 07:43:31.831200000 -0700
@@ -1,6 +1,6 @@
 #include "wxgui/helpers/wxWayland.h"
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 
 #include <dlfcn.h>
 
