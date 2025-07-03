--- src/gui/CemuApp.cpp.orig	2025-06-22 21:34:41 UTC
+++ src/gui/CemuApp.cpp
@@ -12,7 +12,7 @@
 #include "gui/helpers/wxHelpers.h"
 #include "Cemu/ncrypto/ncrypto.h"
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 #include "gui/helpers/wxWayland.h"
 #endif
 #if __WXGTK__
@@ -115,7 +115,7 @@ void CemuApp::DeterminePaths(std::set<fs::path>& faile
 }
 #endif
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 void CemuApp::DeterminePaths(std::set<fs::path>& failedWriteAccess) // for Linux
 {
 	std::error_code ec;
@@ -334,7 +334,7 @@ bool CemuApp::OnInit()
 	SetTopWindow(m_mainFrame);
 	m_mainFrame->Show();
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 	if (wxWlIsWaylandWindow(m_mainFrame))
 		wxWlSetAppId(m_mainFrame, "info.cemu.Cemu");
 #endif
