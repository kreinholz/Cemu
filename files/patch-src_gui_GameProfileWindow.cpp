--- src/gui/GameProfileWindow.cpp.orig	2025-06-26 23:01:05 UTC
+++ src/gui/GameProfileWindow.cpp
@@ -11,7 +11,7 @@
 #include "gui/helpers/wxHelpers.h"
 #include "input/InputManager.h"
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include "resource/embedded/resources.h"
 #endif
 
@@ -365,4 +365,4 @@ void GameProfileWindow::SetSliderValue(wxSlider* slide
 	slider_event.SetEventObject(slider);
 	slider_event.SetClientData((void*)IsFrozen());
 	wxPostEvent(slider->GetEventHandler(), slider_event);
-}
\ No newline at end of file
+}
