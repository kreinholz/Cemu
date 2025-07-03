--- src/Cafe/HW/Latte/Renderer/Vulkan/RendererShaderVk.cpp.orig	2025-06-27 21:29:34 UTC
+++ src/Cafe/HW/Latte/Renderer/Vulkan/RendererShaderVk.cpp
@@ -8,7 +8,7 @@
 
 #include <glslang/Public/ShaderLang.h>
 #include <glslang/SPIRV/GlslangToSpv.h>
-#include <util/helpers/helpers.h>
+#include "util/helpers/helpers.h"
 
 bool s_isLoadingShadersVk{ false };
 class FileCache* s_spirvCache{nullptr};
