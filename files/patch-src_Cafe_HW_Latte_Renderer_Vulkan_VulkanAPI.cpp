--- src/Cafe/HW/Latte/Renderer/Vulkan/VulkanAPI.cpp.orig	2025-06-27 17:29:57 UTC
+++ src/Cafe/HW/Latte/Renderer/Vulkan/VulkanAPI.cpp
@@ -3,7 +3,7 @@
 #include "Cafe/HW/Latte/Renderer/Vulkan/VulkanAPI.h"
 #include <numeric> // for std::iota
 
-#if BOOST_OS_LINUX || BOOST_OS_MACOS
+#if BOOST_OS_LINUX || BOOST_OS_MACOS || BOOST_OS_BSD
 #include <dlfcn.h>
 #endif
 
@@ -138,7 +138,7 @@ void* dlopen_vulkan_loader()
 
 void* dlopen_vulkan_loader()
 {
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 	void* vulkan_so = dlopen("libvulkan.so", RTLD_NOW);
 	if(!vulkan_so)
 		vulkan_so = dlopen("libvulkan.so.1", RTLD_NOW);
