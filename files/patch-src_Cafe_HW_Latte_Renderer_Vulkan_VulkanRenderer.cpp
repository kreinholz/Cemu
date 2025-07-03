--- src/Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.cpp.orig	2025-06-27 18:31:22 UTC
+++ src/Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.cpp
@@ -112,7 +112,7 @@ std::vector<VulkanRenderer::DeviceInfo> VulkanRenderer
 	requiredExtensions.emplace_back(VK_KHR_SURFACE_EXTENSION_NAME);
 	#if BOOST_OS_WINDOWS
 	requiredExtensions.emplace_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
-	#elif BOOST_OS_LINUX
+	#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	auto backend = gui_getWindowInfo().window_main.backend;
 	if(backend == WindowHandleInfo::Backend::X11)
 		requiredExtensions.emplace_back(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
@@ -1310,7 +1310,7 @@ std::vector<const char*> VulkanRenderer::CheckInstance
 	requiredInstanceExtensions.emplace_back(VK_KHR_SURFACE_EXTENSION_NAME);
 	#if BOOST_OS_WINDOWS
 	requiredInstanceExtensions.emplace_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
-	#elif BOOST_OS_LINUX
+	#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	auto backend = gui_getWindowInfo().window_main.backend;
 	if(backend == WindowHandleInfo::Backend::X11)
 		requiredInstanceExtensions.emplace_back(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
@@ -1397,7 +1397,7 @@ VkSurfaceKHR VulkanRenderer::CreateWinSurface(VkInstan
 }
 #endif
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 VkSurfaceKHR VulkanRenderer::CreateXlibSurface(VkInstance instance, Display* dpy, Window window)
 {
     VkXlibSurfaceCreateInfoKHR sci{};
@@ -1461,7 +1461,7 @@ VkSurfaceKHR VulkanRenderer::CreateFramebufferSurface(
 {
 #if BOOST_OS_WINDOWS
 	return CreateWinSurface(instance, windowInfo.hwnd);
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	if(windowInfo.backend == WindowHandleInfo::Backend::X11)
 		return CreateXlibSurface(instance, windowInfo.xlib_display, windowInfo.xlib_window);
 	#ifdef HAS_WAYLAND
