--- src/Common/platform.h.orig	2025-06-22 21:34:41 UTC
+++ src/Common/platform.h
@@ -5,8 +5,12 @@
 
 #if BOOST_OS_WINDOWS
 #include "Common/windows/platform.h"
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
+#if BOOST_OS_LINUX
 #include <byteswap.h>
+#elif BOOST_OS_BSD
+#include <endian.h>
+#endif
 #include <X11/Xlib.h>
 #include <X11/extensions/Xrender.h>
 #include <X11/Xutil.h>
