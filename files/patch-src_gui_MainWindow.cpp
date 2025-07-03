--- src/gui/MainWindow.cpp.orig	2025-06-22 21:34:41 UTC
+++ src/gui/MainWindow.cpp
@@ -48,11 +48,11 @@
 #define exit(__c) _Exit(__c)
 #endif
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 #include "gui/helpers/wxWayland.h"
 #endif
 
@@ -706,7 +706,7 @@ void MainWindow::OnInstallUpdate(wxCommandEvent& event
 			break;
 		if (modalChoice == wxID_OK)
 		{
-			#if BOOST_OS_LINUX || BOOST_OS_MACOS
+			#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 			fs::path dirPath((const char*)(openDirDialog.GetPath().fn_str()));
 			#else
 			fs::path dirPath(openDirDialog.GetPath().fn_str());
@@ -808,7 +808,7 @@ void MainWindow::TogglePadView()
 
 		m_padView->Show(true);
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 		if (wxWlIsWaylandWindow(m_padView))
 			wxWlSetAppId(m_padView, "info.cemu.Cemu");
 #endif
