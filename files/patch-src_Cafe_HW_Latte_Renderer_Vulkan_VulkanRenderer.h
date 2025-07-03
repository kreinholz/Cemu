--- src/Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.h.orig	2025-06-27 18:33:26 UTC
+++ src/Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.h
@@ -196,7 +196,7 @@ class VulkanRenderer : public Renderer (public)
 #if BOOST_OS_WINDOWS
 	static VkSurfaceKHR CreateWinSurface(VkInstance instance, HWND hwindow);
 #endif
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 	static VkSurfaceKHR CreateXlibSurface(VkInstance instance, Display* dpy, Window window);
     static VkSurfaceKHR CreateXcbSurface(VkInstance instance, xcb_connection_t* connection, xcb_window_t window);
 	#ifdef HAS_WAYLAND
