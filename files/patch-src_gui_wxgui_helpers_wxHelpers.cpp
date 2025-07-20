--- src/gui/wxgui/helpers/wxHelpers.cpp.orig	2025-07-20 11:44:08.011287000 -0700
+++ src/gui/wxgui/helpers/wxHelpers.cpp	2025-07-19 15:23:34.809598000 -0700
@@ -5,7 +5,7 @@
 #include <wx/slider.h>
 #include <wx/dirdlg.h>
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 #include <gtk/gtk.h>
 #include <gdk/gdk.h>
 #include <gdk/gdkwindow.h>
@@ -81,7 +81,7 @@
 #if BOOST_OS_WINDOWS
 	handleInfo.backend = WindowSystem::WindowHandleInfo::Backend::Windows;
 	handleInfo.surface = reinterpret_cast<void*>(wxw->GetHWND());
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	GtkWidget* gtkWidget = (GtkWidget*)wxw->GetHandle(); // returns GtkWidget
 	gtk_widget_realize(gtkWidget);
 	GdkWindow* gdkWindow = gtk_widget_get_window(gtkWidget);
