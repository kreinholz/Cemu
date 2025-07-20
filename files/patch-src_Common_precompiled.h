--- src/Common/precompiled.h.orig	2025-07-20 11:44:07.998697000 -0700
+++ src/Common/precompiled.h	2025-07-19 07:43:31.810152000 -0700
@@ -184,6 +184,12 @@
 {
 #if BOOST_OS_MACOS
     return OSSwapInt64(v);
+#elif BOOST_OS_BSD
+#ifdef __OpenBSD__
+    return swap64(v);
+#else // FreeBSD and NetBSD
+    return bswap64(v);
+#endif
 #else
     return bswap_64(v);
 #endif
@@ -193,6 +199,12 @@
 {
 #if BOOST_OS_MACOS
     return OSSwapInt32(v);
+#elif BOOST_OS_BSD
+#ifdef __OpenBSD__
+    return swap32(v);
+#else // FreeBSD and NetBSD
+    return bswap32(v);
+#endif
 #else
     return bswap_32(v);
 #endif
@@ -202,6 +214,12 @@
 {
 #if BOOST_OS_MACOS
     return (sint32)OSSwapInt32((uint32)v);
+#elif BOOST_OS_BSD
+#ifdef __OpenBSD__
+    return (sint32)swap32((uint32)v);
+#else // FreeBSD and NetBSD
+    return (sint32)bswap32((uint32)v);
+#endif
 #else
     return (sint32)bswap_32((uint32)v);
 #endif
@@ -493,6 +511,11 @@
 #elif BOOST_OS_MACOS
 	return std::chrono::steady_clock::time_point(
 		std::chrono::nanoseconds(clock_gettime_nsec_np(CLOCK_MONOTONIC_RAW)));
+#elif BOOST_OS_BSD
+	struct timespec tp;
+	clock_gettime(CLOCK_MONOTONIC, &tp);
+	return std::chrono::steady_clock::time_point(
+		std::chrono::seconds(tp.tv_sec) + std::chrono::nanoseconds(tp.tv_nsec));
 #endif
 }
 
