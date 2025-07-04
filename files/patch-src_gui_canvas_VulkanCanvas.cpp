--- src/gui/canvas/VulkanCanvas.cpp.orig	2025-07-03 23:44:45 UTC
+++ src/gui/canvas/VulkanCanvas.cpp
@@ -2,7 +2,7 @@
 #include "Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.h"
 #include "gui/guiWrapper.h"
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 #include "gui/helpers/wxWayland.h"
 #endif
 
@@ -17,7 +17,7 @@ VulkanCanvas::VulkanCanvas(wxWindow* parent, const wxS
 
 	WindowHandleInfo& canvas = is_main_window ? gui_getWindowInfo().canvas_main : gui_getWindowInfo().canvas_pad;
 	gui_initHandleContextFromWxWidgetsWindow(canvas, this);
-	#if BOOST_OS_LINUX && HAS_WAYLAND
+	#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 	if (canvas.backend == WindowHandleInfo::Backend::WAYLAND)
 	{
 		m_subsurface = std::make_unique<wxWlSubsurface>(this);
@@ -70,7 +70,7 @@ void VulkanCanvas::OnResize(wxSizeEvent& event)
 	if (size.GetWidth() == 0 || size.GetHeight() == 0)
 		return;
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 	if(m_subsurface)
 	{
 		auto sRect = GetScreenRect();
