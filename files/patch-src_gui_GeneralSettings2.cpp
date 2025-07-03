--- src/gui/GeneralSettings2.cpp.orig	2025-06-22 21:34:41 UTC
+++ src/gui/GeneralSettings2.cpp
@@ -224,6 +224,8 @@ wxPanel* GeneralSettings2::AddGeneralPage(wxNotebook* 
 			if (!std::getenv("APPIMAGE")) {
 				m_auto_update->Disable();
 			}
+#elif BOOST_OS_BSD
+			m_auto_update->Disable();
 #endif
 
 			box_sizer->Add(second_row, 0, wxEXPAND, 5);
