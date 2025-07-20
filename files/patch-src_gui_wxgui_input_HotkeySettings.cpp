--- src/gui/wxgui/input/HotkeySettings.cpp.orig	2025-07-20 11:44:08.011625000 -0700
+++ src/gui/wxgui/input/HotkeySettings.cpp	2025-07-19 13:14:03.384621000 -0700
@@ -11,7 +11,7 @@
 #include <ole2.h>
 #endif
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
