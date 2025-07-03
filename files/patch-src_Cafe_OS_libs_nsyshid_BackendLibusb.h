--- src/Cafe/OS/libs/nsyshid/BackendLibusb.h.orig	2025-06-22 21:34:41 UTC
+++ src/Cafe/OS/libs/nsyshid/BackendLibusb.h
@@ -1,6 +1,10 @@
 #include "nsyshid.h"
 
+#if BOOST_OS_BSD
+#include <libusb.h>
+#else
 #include <libusb-1.0/libusb.h>
+#endif
 #include "Backend.h"
 
 namespace nsyshid::backend::libusb
