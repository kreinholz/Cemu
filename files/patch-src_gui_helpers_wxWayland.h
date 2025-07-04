--- src/gui/helpers/wxWayland.h.orig	2025-07-03 23:50:22 UTC
+++ src/gui/helpers/wxWayland.h
@@ -1,6 +1,6 @@
 #pragma once
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 
 #include <gdk/gdk.h>
 #include <gdk/gdkwayland.h>
@@ -90,4 +90,4 @@ void wxWlSetAppId(wxFrame* frame, const char* applicat
 bool wxWlIsWaylandWindow(wxWindow* window);
 void wxWlSetAppId(wxFrame* frame, const char* application_id);
 
-#endif	// BOOST_OS_LINUX && HAS_WAYLAND
+#endif	// ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
