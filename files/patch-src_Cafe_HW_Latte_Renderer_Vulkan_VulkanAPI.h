--- src/Cafe/HW/Latte/Renderer/Vulkan/VulkanAPI.h.orig	2025-07-20 11:44:07.954222000 -0700
+++ src/Cafe/HW/Latte/Renderer/Vulkan/VulkanAPI.h	2025-07-04 08:25:40.587142000 -0700
@@ -130,7 +130,7 @@
 VKFUNC_DEVICE(vkCmdBindPipeline);
 
 // swapchain
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 VKFUNC_INSTANCE(vkCreateXlibSurfaceKHR);
 VKFUNC_INSTANCE(vkCreateXcbSurfaceKHR);
 #ifdef HAS_WAYLAND
