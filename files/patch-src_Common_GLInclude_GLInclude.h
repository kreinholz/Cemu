--- src/Common/GLInclude/GLInclude.h.orig	2025-06-27 17:53:02 UTC
+++ src/Common/GLInclude/GLInclude.h
@@ -6,7 +6,7 @@
 #include "wglext.h"
 #endif
 
-#if BOOST_OS_LINUX > 0
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) > 0
 
 // from Xlib
 #define Bool int
