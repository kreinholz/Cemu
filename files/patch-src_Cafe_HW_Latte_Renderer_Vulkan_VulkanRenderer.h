--- src/Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.h.orig	2025-07-20 11:44:07.956015000 -0700
+++ src/Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.h	2025-07-19 07:43:31.804838000 -0700
@@ -201,7 +201,7 @@
 #if BOOST_OS_WINDOWS
 	static VkSurfaceKHR CreateWinSurface(VkInstance instance, HWND hwindow);
 #endif
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 	static VkSurfaceKHR CreateXlibSurface(VkInstance instance, Display* dpy, Window window);
     static VkSurfaceKHR CreateXcbSurface(VkInstance instance, xcb_connection_t* connection, xcb_window_t window);
 	#ifdef HAS_WAYLAND
