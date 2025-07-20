--- src/Cafe/HW/Latte/Renderer/OpenGL/OpenGLRenderer.cpp.orig	2025-07-20 11:44:07.950865000 -0700
+++ src/Cafe/HW/Latte/Renderer/OpenGL/OpenGLRenderer.cpp	2025-07-19 07:43:31.800275000 -0700
@@ -241,7 +241,7 @@
 #include "Common/GLInclude/glFunctions.h"
 #undef GLFUNC
 }
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 GL_IMPORT _GetOpenGLFunction(void* hLib, PFNGLXGETPROCADDRESSPROC func, const char* name)
 {
 	GL_IMPORT r = (GL_IMPORT)func((const GLubyte*)name);
@@ -276,7 +276,7 @@
 #undef EGLFUNC
 }
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 // dummy function for all code that is statically linked with cemu and attempts to use eglSwapInterval
 // used to suppress wxWidgets calls to eglSwapInterval
 extern "C"
