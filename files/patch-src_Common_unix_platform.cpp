--- src/Common/unix/platform.cpp.orig	2025-07-20 11:44:08.000415000 -0700
+++ src/Common/unix/platform.cpp	2025-07-04 08:44:37.189101000 -0700
@@ -9,6 +9,10 @@
 	return (1000 * ts.tv_sec + ts.tv_nsec / 1000000);
 #elif BOOST_OS_MACOS
 	return clock_gettime_nsec_np(CLOCK_MONOTONIC_RAW) / 1000000;
+#elif BOOST_OS_BSD
+	struct timespec ts;
+	clock_gettime(CLOCK_MONOTONIC, &ts);
+	return (1000 * ts.tv_sec + ts.tv_nsec / 1000000);
 #endif
 
-}
\ No newline at end of file
+}
