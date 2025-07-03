--- src/main.cpp.orig	2025-06-22 21:34:41 UTC
+++ src/main.cpp
@@ -40,7 +40,7 @@
 #if BOOST_OS_LINUX
 #define _putenv(__s) putenv((char*)(__s))
 #include <sys/sysinfo.h>
-#elif BOOST_OS_MACOS
+#elif BOOST_OS_MACOS || BOOST_OS_BSD
 #define _putenv(__s) putenv((char*)(__s))
 #include <sys/types.h>
 #include <sys/sysctl.h>
@@ -251,7 +251,7 @@ int main(int argc, char *argv[])
 
 int main(int argc, char *argv[])
 {
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
     XInitThreads();
 #endif
     if (!LaunchSettings::HandleCommandline(argc, argv))
