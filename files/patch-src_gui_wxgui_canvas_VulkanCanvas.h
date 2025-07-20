--- src/gui/wxgui/canvas/VulkanCanvas.h.orig	2025-07-20 11:44:08.007933000 -0700
+++ src/gui/wxgui/canvas/VulkanCanvas.h	2025-07-19 07:43:31.823052000 -0700
@@ -9,7 +9,7 @@
 
 class VulkanCanvas : public IRenderCanvas, public wxWindow
 {
-#if BOOST_OS_LINUX && HAS_WAYLAND
+#if ( BOOST_OS_LINUX || BOOST_OS_BSD ) && HAS_WAYLAND
 	std::unique_ptr<class wxWlSubsurface> m_subsurface;
 #endif
 public:
