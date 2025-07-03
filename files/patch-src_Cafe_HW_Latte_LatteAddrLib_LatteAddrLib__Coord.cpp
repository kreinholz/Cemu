--- src/Cafe/HW/Latte/LatteAddrLib/LatteAddrLib_Coord.cpp.orig	2025-06-27 18:01:14 UTC
+++ src/Cafe/HW/Latte/LatteAddrLib/LatteAddrLib_Coord.cpp
@@ -7,7 +7,7 @@ namespace LatteAddrLib
 namespace LatteAddrLib
 {
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 	unsigned char _BitScanReverse(uint32* _Index, uint32 _Mask)
 	{
 		if (!_Mask)
@@ -402,4 +402,4 @@ namespace LatteAddrLib
 		return finalMacroTileOffset | pipeOffset | bankOffset;
 	}
 
-};
\ No newline at end of file
+};
