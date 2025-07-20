--- src/gui/wxgui/input/InputSettings2.cpp.orig	2025-07-20 11:44:08.011965000 -0700
+++ src/gui/wxgui/input/InputSettings2.cpp	2025-07-19 07:43:31.833153000 -0700
@@ -149,7 +149,7 @@
 		auto* profiles = new wxComboBox(page, wxID_ANY, kDefaultProfileName);
 		sizer->Add(profiles, wxGBPosition(0, 1), wxDefaultSpan, wxALIGN_CENTER_VERTICAL | wxALL | wxEXPAND, 5);
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 		// We rely on the wxEVT_COMBOBOX_DROPDOWN event to trigger filling the profile list,
 		// but on wxGTK the dropdown button cannot be clicked if the list is empty
 		// so as a quick and dirty workaround we fill the list here
