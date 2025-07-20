--- src/gui/wxgui/MainWindow.cpp.orig	2025-07-20 11:44:08.006941000 -0700
+++ src/gui/wxgui/MainWindow.cpp	2025-07-19 08:11:17.642929000 -0700
@@ -51,11 +51,11 @@
 #define exit(__c) _Exit(__c)
 #endif
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 #include "wxgui/helpers/wxWayland.h"
 #endif
 
@@ -710,7 +710,7 @@
 			break;
 		if (modalChoice == wxID_OK)
 		{
-			#if BOOST_OS_LINUX || BOOST_OS_MACOS
+			#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 			fs::path dirPath((const char*)(openDirDialog.GetPath().fn_str()));
 			#else
 			fs::path dirPath(openDirDialog.GetPath().fn_str());
@@ -812,7 +812,7 @@
 
 		m_padView->Show(true);
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 		if (wxWlIsWaylandWindow(m_padView))
 			wxWlSetAppId(m_padView, "info.cemu.Cemu");
 #endif
@@ -2320,6 +2320,8 @@
 	if (!std::getenv("APPIMAGE")) {
 		m_check_update_menu->Enable(false);
 	}
+#elif BOOST_OS_BSD // BSD users must update from source so disable update checks
+	m_check_update_menu->Enable(false);
 #endif
 	helpMenu->AppendSeparator();
 	helpMenu->Append(MAINFRAME_MENU_ID_HELP_ABOUT, _("&About Cemu"));
