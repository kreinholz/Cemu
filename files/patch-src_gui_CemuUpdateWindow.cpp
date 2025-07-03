--- src/gui/CemuUpdateWindow.cpp.orig	2025-06-22 21:34:41 UTC
+++ src/gui/CemuUpdateWindow.cpp
@@ -109,15 +109,18 @@ bool CemuUpdateWindow::QueryUpdateInfo(std::string& do
 	std::string urlStr("https://cemu.info/api2/version.php?v=");
 	auto* curl = curl_easy_init();
 	urlStr.append(_curlUrlEscape(curl, BUILD_VERSION_STRING));
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD // works on Linux; dummy placeholder on BSD
 	urlStr.append("&platform=linux_appimage_x86");
 #elif BOOST_OS_WINDOWS
 	urlStr.append("&platform=windows");
 #elif BOOST_OS_MACOS
 	urlStr.append("&platform=macos_bundle_x86");
-#elif
+#else
 #error Name for current platform is missing
 #endif
+#if BOOST_OS_BSD // always report no update on BSD since we must build from source or use package repos
+	return false;
+#endif
 	const auto& config = GetConfig();
 	if(config.receive_untested_updates)
 		urlStr.append("&allowNewUpdates=1");
@@ -416,7 +419,7 @@ void CemuUpdateWindow::WorkerThread()
 
 #if BOOST_OS_WINDOWS
 				const auto update_file = tmppath / L"update.zip";
-#elif BOOST_OS_LINUX
+#elif BOOST_OS_LINUX || BOOST_OS_BSD // works on Linux; dummy placeholder on BSD
 				const auto update_file = tmppath / L"Cemu.AppImage";
 #elif BOOST_OS_MACOS
 				const auto update_file = tmppath / L"cemu.dmg";
