--- src/gui/GettingStartedDialog.cpp.orig	2025-06-26 23:04:23 UTC
+++ src/gui/GettingStartedDialog.cpp
@@ -15,7 +15,7 @@
 
 #include "Cafe/TitleList/TitleList.h"
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
