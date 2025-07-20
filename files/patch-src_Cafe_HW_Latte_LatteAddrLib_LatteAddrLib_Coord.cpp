--- src/Cafe/HW/Latte/LatteAddrLib/LatteAddrLib_Coord.cpp.orig	2025-07-20 11:44:07.947701000 -0700
+++ src/Cafe/HW/Latte/LatteAddrLib/LatteAddrLib_Coord.cpp	2025-07-04 08:21:54.529241000 -0700
@@ -7,7 +7,7 @@
 namespace LatteAddrLib
 {
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 	unsigned char _BitScanReverse(uint32* _Index, uint32 _Mask)
 	{
 		if (!_Mask)
@@ -402,4 +402,4 @@
 		return finalMacroTileOffset | pipeOffset | bankOffset;
 	}
 
-};
\ No newline at end of file
+};
