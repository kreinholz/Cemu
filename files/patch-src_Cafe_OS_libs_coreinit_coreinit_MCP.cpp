--- src/Cafe/OS/libs/coreinit/coreinit_MCP.cpp.orig	2025-07-20 11:44:07.967013000 -0700
+++ src/Cafe/OS/libs/coreinit/coreinit_MCP.cpp	2025-07-04 08:31:51.222700000 -0700
@@ -466,7 +466,7 @@
 
 static_assert(sizeof(UCParamStruct_t) == 0x54); // unsure
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #define _strcmpi strcasecmp
 #endif
 
