--- src/gui/input/InputSettings2.cpp.orig	2025-06-27 17:21:44 UTC
+++ src/gui/input/InputSettings2.cpp
@@ -149,7 +149,7 @@ wxWindow* InputSettings2::initialize_page(size_t index
 		auto* profiles = new wxComboBox(page, wxID_ANY, kDefaultProfileName);
 		sizer->Add(profiles, wxGBPosition(0, 1), wxDefaultSpan, wxALIGN_CENTER_VERTICAL | wxALL | wxEXPAND, 5);
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 		// We rely on the wxEVT_COMBOBOX_DROPDOWN event to trigger filling the profile list,
 		// but on wxGTK the dropdown button cannot be clicked if the list is empty
 		// so as a quick and dirty workaround we fill the list here
