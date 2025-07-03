--- src/gui/input/InputAPIAddWindow.cpp.orig	2025-06-27 17:49:02 UTC
+++ src/gui/input/InputAPIAddWindow.cpp
@@ -190,7 +190,7 @@ void InputAPIAddWindow::on_api_selected(wxCommandEvent
 	}
     else
     {
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
         // We rely on the wxEVT_COMBOBOX_DROPDOWN event to trigger filling the controller list,
         // but on wxGTK the dropdown button cannot be clicked if the list is empty
         // so as a quick and dirty workaround we fill the list here
