--- src/gui/components/wxGameList.cpp.orig	2025-06-27 17:16:25 UTC
+++ src/gui/components/wxGameList.cpp
@@ -1372,7 +1372,7 @@ void wxGameList::DeleteCachedStrings() 
 	m_name_cache.clear();
 }
 
-#if BOOST_OS_LINUX
+#if BOOST_OS_LINUX || BOOST_OS_BSD
 void wxGameList::CreateShortcut(GameInfo2& gameInfo)
 {
 	const auto titleId = gameInfo.GetBaseTitleId();
