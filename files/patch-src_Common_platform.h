--- src/Common/platform.h.orig	2025-07-20 11:44:07.998517000 -0700
+++ src/Common/platform.h	2025-07-04 08:38:05.033715000 -0700
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
