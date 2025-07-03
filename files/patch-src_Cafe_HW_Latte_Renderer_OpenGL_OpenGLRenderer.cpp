--- src/Cafe/HW/Latte/Renderer/OpenGL/OpenGLRenderer.cpp.orig	2025-06-27 17:18:46 UTC
+++ src/Cafe/HW/Latte/Renderer/OpenGL/OpenGLRenderer.cpp
@@ -210,7 +210,7 @@ void LoadOpenGLImports()
 #include "Common/GLInclude/glFunctions.h"
 #undef GLFUNC
 }
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD
 GL_IMPORT _GetOpenGLFunction(void* hLib, PFNGLXGETPROCADDRESSPROC func, const char* name)
 {
 	GL_IMPORT r = (GL_IMPORT)func((const GLubyte*)name);
@@ -245,7 +245,7 @@ void LoadOpenGLImports()
 #undef EGLFUNC
 }
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 // dummy function for all code that is statically linked with cemu and attempts to use eglSwapInterval
 // used to suppress wxWidgets calls to eglSwapInterval
 extern "C"
