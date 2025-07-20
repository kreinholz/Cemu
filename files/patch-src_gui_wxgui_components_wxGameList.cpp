--- src/gui/wxgui/components/wxGameList.cpp.orig	2025-07-20 11:44:08.008737000 -0700
+++ src/gui/wxgui/components/wxGameList.cpp	2025-07-19 07:43:31.824955000 -0700
@@ -1373,7 +1373,7 @@
 	m_name_cache.clear();
 }
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 void wxGameList::CreateShortcut(GameInfo2& gameInfo)
 {
 	const auto titleId = gameInfo.GetBaseTitleId();
