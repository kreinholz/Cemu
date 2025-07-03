--- src/Common/unix/platform.cpp.orig	2025-06-22 21:34:41 UTC
+++ src/Common/unix/platform.cpp
@@ -9,6 +9,10 @@ uint32_t GetTickCount()
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
