--- src/Cafe/OS/libs/nsyshid/BackendLibusb.h.orig	2025-07-20 11:44:07.981986000 -0700
+++ src/Cafe/OS/libs/nsyshid/BackendLibusb.h	2025-07-04 08:32:44.047023000 -0700
@@ -1,6 +1,10 @@
 #include "nsyshid.h"
 
+#if BOOST_OS_BSD
+#include <libusb.h>
+#else
 #include <libusb-1.0/libusb.h>
+#endif
 #include "Backend.h"
 
 namespace nsyshid::backend::libusb
