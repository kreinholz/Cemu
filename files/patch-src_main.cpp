--- src/main.cpp.orig	2025-07-20 11:44:08.020809000 -0700
+++ src/main.cpp	2025-07-19 07:43:31.841355000 -0700
@@ -36,7 +36,7 @@
 #if BOOST_OS_LINUX
 #define _putenv(__s) putenv((char*)(__s))
 #include <sys/sysinfo.h>
-#elif BOOST_OS_MACOS
+#elif BOOST_OS_MACOS || BOOST_OS_BSD
 #define _putenv(__s) putenv((char*)(__s))
 #include <sys/types.h>
 #include <sys/sysctl.h>
@@ -247,7 +247,7 @@
 
 int main(int argc, char *argv[])
 {
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
     XInitThreads();
 #endif
     if (!LaunchSettings::HandleCommandline(argc, argv))
