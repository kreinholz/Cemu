--- src/Cafe/CafeSystem.cpp.orig	2025-07-20 11:44:07.924600000 -0700
+++ src/Cafe/CafeSystem.cpp	2025-07-19 07:43:31.795751000 -0700
@@ -69,7 +69,7 @@
 
 #if BOOST_OS_LINUX
 #include <sys/sysinfo.h>
-#elif BOOST_OS_MACOS
+#elif BOOST_OS_MACOS || BOOST_OS_BSD
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -475,6 +475,12 @@
 		int result = sysctlbyname("hw.memsize", &totalRam, &size, NULL, 0);
 		if (result == 0)
 			cemuLog_log(LogType::Force, "RAM: {}MB", (totalRam / 1024LL / 1024LL));
+		#elif BOOST_OS_BSD
+		int64_t totalRam;
+		size_t size = sizeof(totalRam);
+		int result = sysctlbyname("hw.physmem", &totalRam, &size, NULL, 0);
+		if (result == 0)
+			cemuLog_log(LogType::Force, "RAM: {}MB", (totalRam / 1024LL / 1024LL));
 		#endif
 	}
 
@@ -523,6 +529,16 @@
 			platform = "Linux";
 		#elif BOOST_OS_MACOS
 		platform = "MacOS";
+		#elif BOOST_OS_BSD
+		#if defined(__FreeBSD__)
+		platform = "FreeBSD";
+		#elif defined(__OpenBSD__)
+		platform = "OpenBSD";
+		#elif defined(__NetBSD__)
+		platform = "NetBSD";
+		#else
+		platform = "Unknown BSD";
+		#endif
 		#endif
 		cemuLog_log(LogType::Force, "Platform: {}", platform);
 	}
