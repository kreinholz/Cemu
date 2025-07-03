--- src/gui/GraphicPacksWindow2.cpp.orig	2025-06-26 23:05:29 UTC
+++ src/gui/GraphicPacksWindow2.cpp
@@ -12,7 +12,7 @@
 
 #include "wxHelper.h"
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
