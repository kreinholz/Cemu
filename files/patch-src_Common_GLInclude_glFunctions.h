--- src/Common/GLInclude/glFunctions.h.orig	2025-07-20 11:44:07.994342000 -0700
+++ src/Common/GLInclude/glFunctions.h	2025-07-04 08:36:21.208941000 -0700
@@ -297,7 +297,7 @@
 
 // x
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 EGLFUNC(PFNEGLSWAPINTERVALPROC, eglSwapInterval)
 EGLFUNC(PFNEGLGETCURRENTDISPLAYPROC, eglGetCurrentDisplay)
 #endif
