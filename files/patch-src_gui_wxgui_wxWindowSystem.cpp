--- src/gui/wxgui/wxWindowSystem.cpp.orig	2025-07-20 11:44:08.013667000 -0700
+++ src/gui/wxgui/wxWindowSystem.cpp	2025-07-19 13:23:21.149828000 -0700
@@ -3,7 +3,7 @@
 
 #include "helpers/wxHelpers.h"
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtk.h>
 #include <gdk/gdk.h>
@@ -231,7 +231,7 @@
 	case PlatformKeyCodes::ESCAPE:
 		key = VK_ESCAPE;
 		break;
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	case PlatformKeyCodes::LCONTROL:
 		key = GDK_KEY_Control_L;
 		break;
@@ -300,7 +300,7 @@
 		return key_name;
 	else
 		return fmt::format("key_{}", button);
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	return gdk_keyval_name(button);
 #else
 	return fmt::format("key_{}", button);
