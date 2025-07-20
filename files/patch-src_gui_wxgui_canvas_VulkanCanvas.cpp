--- src/gui/wxgui/canvas/VulkanCanvas.cpp.orig	2025-07-20 11:44:08.007890000 -0700
+++ src/gui/wxgui/canvas/VulkanCanvas.cpp	2025-07-19 08:13:52.091739000 -0700
@@ -1,7 +1,7 @@
 #include "wxgui/canvas/VulkanCanvas.h"
 #include "Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.h"
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 #include "wxgui/helpers/wxWayland.h"
 #endif
 
@@ -16,7 +16,7 @@
 
 	auto& canvas = is_main_window ? WindowSystem::GetWindowInfo().canvas_main : WindowSystem::GetWindowInfo().canvas_pad;
 	canvas = initHandleContextFromWxWidgetsWindow(this);
-	#if BOOST_OS_LINUX && HAS_WAYLAND
+	#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 	if (canvas.backend == WindowSystem::WindowHandleInfo::Backend::Wayland)
 	{
 		m_subsurface = std::make_unique<wxWlSubsurface>(this);
@@ -69,7 +69,7 @@
 	if (size.GetWidth() == 0 || size.GetHeight() == 0)
 		return;
 
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 	if(m_subsurface)
 	{
 		auto sRect = GetScreenRect();
