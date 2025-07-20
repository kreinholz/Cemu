--- src/gui/wxgui/input/InputAPIAddWindow.cpp.orig	2025-07-20 11:44:08.011759000 -0700
+++ src/gui/wxgui/input/InputAPIAddWindow.cpp	2025-07-19 07:43:31.832550000 -0700
@@ -190,7 +190,7 @@
 	}
     else
     {
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
         // We rely on the wxEVT_COMBOBOX_DROPDOWN event to trigger filling the controller list,
         // but on wxGTK the dropdown button cannot be clicked if the list is empty
         // so as a quick and dirty workaround we fill the list here
