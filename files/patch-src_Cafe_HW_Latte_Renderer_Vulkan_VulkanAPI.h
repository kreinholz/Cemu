--- src/Cafe/HW/Latte/Renderer/Vulkan/VulkanAPI.h.orig	2025-06-27 17:45:47 UTC
+++ src/Cafe/HW/Latte/Renderer/Vulkan/VulkanAPI.h
@@ -130,7 +130,7 @@ VKFUNC_DEVICE(vkCmdBindPipeline);
 VKFUNC_DEVICE(vkCmdBindPipeline);
 
 // swapchain
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 VKFUNC_INSTANCE(vkCreateXlibSurfaceKHR);
 VKFUNC_INSTANCE(vkCreateXcbSurfaceKHR);
 #ifdef HAS_WAYLAND
