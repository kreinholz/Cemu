--- src/Cafe/OS/libs/coreinit/coreinit_MCP.cpp.orig	2025-06-27 17:29:01 UTC
+++ src/Cafe/OS/libs/coreinit/coreinit_MCP.cpp
@@ -466,7 +466,7 @@ static_assert(sizeof(UCParamStruct_t) == 0x54); // uns
 
 static_assert(sizeof(UCParamStruct_t) == 0x54); // unsure
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #define _strcmpi strcasecmp
 #endif
 
