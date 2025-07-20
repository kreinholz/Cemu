--- src/gui/wxgui/CemuApp.cpp.orig	2025-07-20 11:44:08.004042000 -0700
+++ src/gui/wxgui/CemuApp.cpp	2025-07-19 08:07:40.696805000 -0700
@@ -14,7 +14,7 @@
 #include "wxgui/input/HotkeySettings.h"
 #include <wx/language.h>
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 #include "wxgui/helpers/wxWayland.h"
 #endif
 #if __WXGTK__
@@ -117,7 +117,7 @@
 }
 #endif
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 void CemuApp::DeterminePaths(std::set<fs::path>& failedWriteAccess) // for Linux
 {
 	std::error_code ec;
@@ -347,7 +347,7 @@
 	SetTopWindow(m_mainFrame);
 	m_mainFrame->Show();
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 	if (wxWlIsWaylandWindow(m_mainFrame))
 		wxWlSetAppId(m_mainFrame, "info.cemu.Cemu");
 #endif
