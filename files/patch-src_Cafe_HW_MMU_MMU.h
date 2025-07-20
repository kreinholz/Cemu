--- src/Cafe/HW/MMU/MMU.h.orig	2025-07-20 11:44:07.957736000 -0700
+++ src/Cafe/HW/MMU/MMU.h	2025-07-04 08:41:56.779889000 -0700
@@ -184,6 +184,16 @@
 #define CPU_swapEndianU64(_v) OSSwapInt64((uint64)(_v))
 #define CPU_swapEndianU32(_v) OSSwapInt32((uint32)(_v))
 #define CPU_swapEndianU16(_v) OSSwapInt16((uint16)(_v))
+#elif BOOST_OS_BSD
+#ifdef __OpenBSD__
+#define CPU_swapEndianU64(_v) swap64((uint64)(_v))
+#define CPU_swapEndianU32(_v) swap32((uint32)(_v))
+#define CPU_swapEndianU16(_v) swap16((uint16)(_v))
+#else // FreeBSD and NetBSD
+#define CPU_swapEndianU64(_v) bswap64((uint64)(_v))
+#define CPU_swapEndianU32(_v) bswap32((uint32)(_v))
+#define CPU_swapEndianU16(_v) bswap16((uint16)(_v))
+#endif
 #endif
 
 // C-style memory access, deprecated. Use memory_read<> and memory_write<> templates instead
@@ -266,4 +276,4 @@
 
 }
 
-#define MMU_IsInPPCMemorySpace(__ptr) ((const uint8*)(__ptr) >= memory_base && (const uint8*)(__ptr) < (memory_base + 0x100000000))
\ No newline at end of file
+#define MMU_IsInPPCMemorySpace(__ptr) ((const uint8*)(__ptr) >= memory_base && (const uint8*)(__ptr) < (memory_base + 0x100000000))
