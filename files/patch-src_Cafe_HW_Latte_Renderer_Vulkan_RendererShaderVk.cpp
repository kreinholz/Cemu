--- src/Cafe/HW/Latte/Renderer/Vulkan/RendererShaderVk.cpp.orig	2025-07-20 11:44:07.953079000 -0700
+++ src/Cafe/HW/Latte/Renderer/Vulkan/RendererShaderVk.cpp	2025-07-04 08:24:20.146660000 -0700
@@ -8,7 +8,7 @@
 
 #include <glslang/Public/ShaderLang.h>
 #include <glslang/SPIRV/GlslangToSpv.h>
-#include <util/helpers/helpers.h>
+#include "util/helpers/helpers.h"
 
 bool s_isLoadingShadersVk{ false };
 class FileCache* s_spirvCache{nullptr};
