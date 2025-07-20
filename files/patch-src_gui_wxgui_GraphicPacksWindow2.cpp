--- src/gui/wxgui/GraphicPacksWindow2.cpp.orig	2025-07-20 11:44:08.006238000 -0700
+++ src/gui/wxgui/GraphicPacksWindow2.cpp	2025-07-19 07:43:31.819017000 -0700
@@ -12,7 +12,7 @@
 
 #include "wxHelper.h"
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
