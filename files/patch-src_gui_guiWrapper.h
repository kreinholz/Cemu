--- src/gui/guiWrapper.h.orig	2025-06-22 21:34:41 UTC
+++ src/gui/guiWrapper.h
@@ -1,7 +1,7 @@
 #pragma once
 
-#if BOOST_OS_LINUX
-#include "xcb/xproto.h"
+#if BOOST_OS_LINUX || BOOST_OS_BSD
+#include <xcb/xproto.h>
 #include <gdk/gdkkeysyms.h>
 #endif
 
@@ -13,7 +13,7 @@ struct WindowHandleInfo
 {
 #if BOOST_OS_WINDOWS
 	std::atomic<HWND> hwnd;
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	enum class Backend
 	{
 		X11,
@@ -42,7 +42,7 @@ enum struct PlatformKeyCodes : uint32
 	RCONTROL = VK_RCONTROL,
 	TAB = VK_TAB,
 	ESCAPE = VK_ESCAPE,
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	LCONTROL = GDK_KEY_Control_L,
 	RCONTROL = GDK_KEY_Control_R,
 	TAB = GDK_KEY_Tab,
@@ -142,7 +142,7 @@ void gui_initHandleContextFromWxWidgetsWindow(WindowHa
 
 void gui_initHandleContextFromWxWidgetsWindow(WindowHandleInfo& handleInfoOut, class wxWindow* wxw);
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 std::string gui_gtkRawKeyCodeToString(uint32 keyCode);
 #endif
 /*
