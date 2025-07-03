--- src/Common/GLInclude/glFunctions.h.orig	2025-06-27 18:30:14 UTC
+++ src/Common/GLInclude/glFunctions.h
@@ -297,7 +297,7 @@ GLFUNC(PFNWGLSWAPINTERVALEXTPROC, wglSwapIntervalEXT)
 
 // x
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 EGLFUNC(PFNEGLSWAPINTERVALPROC, eglSwapInterval)
 EGLFUNC(PFNEGLGETCURRENTDISPLAYPROC, eglGetCurrentDisplay)
 #endif
