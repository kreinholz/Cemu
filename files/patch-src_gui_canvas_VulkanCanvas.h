--- src/gui/canvas/VulkanCanvas.h.orig	2025-06-27 17:24:53 UTC
+++ src/gui/canvas/VulkanCanvas.h
@@ -9,7 +9,7 @@ class VulkanCanvas : public IRenderCanvas, public wxWi
 
 class VulkanCanvas : public IRenderCanvas, public wxWindow
 {
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 	std::unique_ptr<class wxWlSubsurface> m_subsurface;
 #endif
 public:
