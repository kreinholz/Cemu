--- src/gui/wxgui/helpers/wxWayland.h.orig	2025-07-20 11:44:08.011483000 -0700
+++ src/gui/wxgui/helpers/wxWayland.h	2025-07-19 07:43:31.831717000 -0700
@@ -1,6 +1,6 @@
 #pragma once
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 
 #include <gdk/gdk.h>
 #include <gdk/gdkwayland.h>
