--- src/util/highresolutiontimer/HighResolutionTimer.cpp.orig	2025-06-22 21:34:41 UTC
+++ src/util/highresolutiontimer/HighResolutionTimer.cpp
@@ -14,6 +14,11 @@ HighResolutionTimer HighResolutionTimer::now()
     return HighResolutionTimer(nsec);
 #elif BOOST_OS_MACOS
 	return HighResolutionTimer(clock_gettime_nsec_np(CLOCK_MONOTONIC_RAW));
+#elif BOOST_OS_BSD
+    timespec pc;
+    clock_gettime(CLOCK_MONOTONIC, &pc);
+    uint64 nsec = (uint64)pc.tv_sec * (uint64)1000000000 + (uint64)pc.tv_nsec;
+    return HighResolutionTimer(nsec);
 #endif
 }
 
@@ -29,6 +34,10 @@ uint64 HighResolutionTimer::m_freq = []() -> uint64 {
 	return (uint64)(freq.QuadPart);
 #elif BOOST_OS_MACOS
 	return 1000000000;
+#elif BOOST_OS_BSD
+	timespec pc;
+	clock_getres(CLOCK_MONOTONIC, &pc);
+	return (uint64)1000000000 / (uint64)pc.tv_nsec;
 #else
     timespec pc;
     clock_getres(CLOCK_MONOTONIC_RAW, &pc);
