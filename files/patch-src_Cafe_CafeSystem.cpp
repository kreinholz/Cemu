--- src/Cafe/CafeSystem.cpp.orig	2025-06-22 21:34:41 UTC
+++ src/Cafe/CafeSystem.cpp
@@ -72,7 +72,7 @@
 
 #if BOOST_OS_LINUX
 #include <sys/sysinfo.h>
-#elif BOOST_OS_MACOS
+#elif BOOST_OS_MACOS || BOOST_OS_BSD
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -478,6 +478,12 @@ namespace CafeSystem
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
 
@@ -526,6 +532,16 @@ namespace CafeSystem
 			platform = "Linux";
 		#elif BOOST_OS_MACOS
 		platform = "MacOS";
+		#elif BOOST_OS_BSD
+		#if defined(__FreeBSD__)
+		platform = "FreeBSD";
+		#elif defined(__OpenBSD__)
+		platform = "OpenBSD"
+		#elif defined(__NetBSD__)
+		platform = "NetBSD"
+		#else
+		platform = "Unknown BSD"
+		#endif
 		#endif
 		cemuLog_log(LogType::Force, "Platform: {}", platform);
 	}
