--- src/Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.cpp.orig	2025-07-20 11:44:07.955749000 -0700
+++ src/Cafe/HW/Latte/Renderer/Vulkan/VulkanRenderer.cpp	2025-07-19 14:58:13.340393000 -0700
@@ -110,7 +110,7 @@
 	requiredExtensions.emplace_back(VK_KHR_SURFACE_EXTENSION_NAME);
 	#if BOOST_OS_WINDOWS
 	requiredExtensions.emplace_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
-	#elif BOOST_OS_LINUX
+	#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	auto backend = WindowSystem::GetWindowInfo().window_main.backend;
 	if(backend == WindowSystem::WindowHandleInfo::Backend::X11)
 		requiredExtensions.emplace_back(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
@@ -1307,7 +1307,7 @@
 	requiredInstanceExtensions.emplace_back(VK_KHR_SURFACE_EXTENSION_NAME);
 	#if BOOST_OS_WINDOWS
 	requiredInstanceExtensions.emplace_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
-	#elif BOOST_OS_LINUX
+	#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	auto backend = WindowSystem::GetWindowInfo().window_main.backend;
 	if(backend == WindowSystem::WindowHandleInfo::Backend::X11)
 		requiredInstanceExtensions.emplace_back(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
@@ -1394,7 +1394,7 @@
 }
 #endif
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 VkSurfaceKHR VulkanRenderer::CreateXlibSurface(VkInstance instance, Display* dpy, Window window)
 {
     VkXlibSurfaceCreateInfoKHR sci{};
@@ -1458,8 +1458,7 @@
 {
 #if BOOST_OS_WINDOWS
 	return CreateWinSurface(instance, static_cast<HWND>(windowInfo.surface));
-#elif BOOST_OS_LINUX
-	
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 	if(windowInfo.backend == WindowSystem::WindowHandleInfo::Backend::X11)
 		return CreateXlibSurface(instance, static_cast<Display*>(windowInfo.display), reinterpret_cast<Window>(windowInfo.surface));
 	#ifdef HAS_WAYLAND
