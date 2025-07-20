--- src/gui/wxgui/CemuUpdateWindow.cpp.orig	2025-07-20 11:44:08.004265000 -0700
+++ src/gui/wxgui/CemuUpdateWindow.cpp	2025-07-19 08:09:53.649525000 -0700
@@ -110,15 +110,18 @@
 	std::string urlStr("https://cemu.info/api2/version.php?v=");
 	auto* curl = curl_easy_init();
 	urlStr.append(_curlUrlEscape(curl, BUILD_VERSION_STRING));
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD // dummy placeholder on BSD for now
 	urlStr.append("&platform=linux_appimage_x86");
 #elif BOOST_OS_WINDOWS
 	urlStr.append("&platform=windows");
 #elif BOOST_OS_MACOS
 	urlStr.append("&platform=macos_bundle_x86");
-#elif
+#else
 #error Name for current platform is missing
 #endif
+#if BOOST_OS_BSD
+	return false; // BSD users must update from source; no binary available
+#endif
 	const auto& config = GetWxGUIConfig();
 	if(config.receive_untested_updates)
 		urlStr.append("&allowNewUpdates=1");
@@ -417,7 +420,7 @@
 
 #if BOOST_OS_WINDOWS
 				const auto update_file = tmppath / L"update.zip";
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD // dummy placeholder on BSD for now
 				const auto update_file = tmppath / L"Cemu.AppImage";
 #elif BOOST_OS_MACOS
 				const auto update_file = tmppath / L"cemu.dmg";
