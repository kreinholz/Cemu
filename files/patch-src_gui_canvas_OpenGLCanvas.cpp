--- src/gui/canvas/OpenGLCanvas.cpp.orig	2025-06-27 17:27:36 UTC
+++ src/gui/canvas/OpenGLCanvas.cpp
@@ -70,7 +70,7 @@ class OpenGLCanvas : public IRenderCanvas, public wxGL
 #if BOOST_OS_WINDOWS
 			if(wglSwapIntervalEXT)
 				wglSwapIntervalEXT(configValue); // 1 = enabled, 0 = disabled
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 			if (eglSwapInterval)
 			{
 				if (eglSwapInterval(eglGetCurrentDisplay(), configValue) == EGL_FALSE)
