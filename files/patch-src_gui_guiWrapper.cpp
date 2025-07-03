--- src/gui/guiWrapper.cpp.orig	2025-06-27 18:03:57 UTC
+++ src/gui/guiWrapper.cpp
@@ -1,4 +1,4 @@
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 #include <gtk/gtk.h>
 #include <gdk/gdk.h>
 #include <gdk/gdkwindow.h>
@@ -191,7 +191,7 @@ bool gui_isPadWindowOpen()
 	return g_window_info.pad_open;
 }
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 std::string gui_gtkRawKeyCodeToString(uint32 keyCode)
 {
 	return gdk_keyval_name(keyCode);
@@ -202,7 +202,7 @@ void gui_initHandleContextFromWxWidgetsWindow(WindowHa
 {
 #if BOOST_OS_WINDOWS
 	handleInfoOut.hwnd = wxw->GetHWND();
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
     GtkWidget* gtkWidget = (GtkWidget*)wxw->GetHandle(); // returns GtkWidget
     gtk_widget_realize(gtkWidget);
     GdkWindow* gdkWindow = gtk_widget_get_window(gtkWidget);
