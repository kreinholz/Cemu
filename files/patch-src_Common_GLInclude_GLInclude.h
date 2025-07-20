--- src/Common/GLInclude/GLInclude.h.orig	2025-07-20 11:44:07.994127000 -0700
+++ src/Common/GLInclude/GLInclude.h	2025-07-04 08:36:57.433239000 -0700
@@ -6,7 +6,7 @@
 #include "wglext.h"
 #endif
 
-#if BOOST_OS_LINUX > 0
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) > 0
 
 // from Xlib
 #define Bool int
