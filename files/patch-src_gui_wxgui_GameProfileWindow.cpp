--- src/gui/wxgui/GameProfileWindow.cpp.orig	2025-07-20 11:44:08.005125000 -0700
+++ src/gui/wxgui/GameProfileWindow.cpp	2025-07-19 07:43:31.816428000 -0700
@@ -11,7 +11,7 @@
 #include "wxgui/helpers/wxHelpers.h"
 #include "input/InputManager.h"
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
@@ -365,4 +365,4 @@
 	slider_event.SetEventObject(slider);
 	slider_event.SetClientData((void*)IsFrozen());
 	wxPostEvent(slider->GetEventHandler(), slider_event);
-}
\ No newline at end of file
+}
