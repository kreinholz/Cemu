--- src/gui/wxgui/GeneralSettings2.cpp.orig	2025-07-20 11:44:08.005754000 -0700
+++ src/gui/wxgui/GeneralSettings2.cpp	2025-07-19 07:43:31.817971000 -0700
@@ -225,6 +225,8 @@
 			if (!std::getenv("APPIMAGE")) {
 				m_auto_update->Disable();
 			}
+#elif BOOST_OS_BSD // BSD users must update from source so disable auto updates
+			m_auto_update->Disable();
 #endif
 
 			box_sizer->Add(second_row, 0, wxEXPAND, 5);
