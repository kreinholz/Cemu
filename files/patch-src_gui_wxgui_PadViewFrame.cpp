--- src/gui/wxgui/PadViewFrame.cpp.orig	2025-07-20 11:44:08.007295000 -0700
+++ src/gui/wxgui/PadViewFrame.cpp	2025-07-19 07:43:31.821457000 -0700
@@ -13,7 +13,7 @@
 #include "wxgui/helpers/wxHelpers.h"
 #include "input/InputManager.h"
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 #include "wxHelper.h"
