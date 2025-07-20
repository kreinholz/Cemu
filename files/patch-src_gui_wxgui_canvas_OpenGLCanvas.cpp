--- src/gui/wxgui/canvas/OpenGLCanvas.cpp.orig	2025-07-20 11:44:08.007802000 -0700
+++ src/gui/wxgui/canvas/OpenGLCanvas.cpp	2025-07-19 07:43:31.822597000 -0700
@@ -124,7 +124,7 @@
 #if BOOST_OS_WINDOWS
 			if(wglSwapIntervalEXT)
 				wglSwapIntervalEXT(configValue); // 1 = enabled, 0 = disabled
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 			if (eglSwapInterval)
 			{
 				if (eglSwapInterval(eglGetCurrentDisplay(), configValue) == EGL_FALSE)
