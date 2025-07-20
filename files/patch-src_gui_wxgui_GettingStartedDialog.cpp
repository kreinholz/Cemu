--- src/gui/wxgui/GettingStartedDialog.cpp.orig	2025-07-20 11:44:08.006009000 -0700
+++ src/gui/wxgui/GettingStartedDialog.cpp	2025-07-19 07:43:31.818431000 -0700
@@ -17,7 +17,7 @@
 
 #include "Cafe/TitleList/TitleList.h"
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
