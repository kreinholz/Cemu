--- src/Common/precompiled.h.orig	2025-06-22 21:34:41 UTC
+++ src/Common/precompiled.h
@@ -143,6 +143,12 @@ inline uint64 _swapEndianU64(uint64 v)
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
@@ -152,6 +158,12 @@ inline uint32 _swapEndianU32(uint32 v)
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
@@ -161,6 +173,12 @@ inline sint32 _swapEndianS32(sint32 v)
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
@@ -452,6 +470,11 @@ bool match_any_of(T1&& value, Types&&... others)
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
 
