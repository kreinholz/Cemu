--- src/gui/PadViewFrame.cpp.orig	2025-06-27 15:01:48 UTC
+++ src/gui/PadViewFrame.cpp
@@ -13,7 +13,7 @@
 #include "gui/helpers/wxHelpers.h"
 #include "input/InputManager.h"
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 #include "wxHelper.h"
