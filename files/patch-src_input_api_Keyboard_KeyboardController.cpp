--- src/input/api/Keyboard/KeyboardController.cpp.orig	2025-06-27 17:54:16 UTC
+++ src/input/api/Keyboard/KeyboardController.cpp
@@ -38,7 +38,7 @@ std::string KeyboardController::get_button_name(uint64
 		return key_name;
 	else
 		return fmt::format("key_{}", button);
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	return gui_gtkRawKeyCodeToString(button);
 #else
 	return fmt::format("key_{}", button);
