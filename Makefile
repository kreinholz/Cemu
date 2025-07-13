PORTNAME=	Cemu_Cafe
PORTVERSION=	2.6.d18ecc0
CATEGORIES=	emulators

MAINTAINER=	kreinholz@gmail.com
COMMENT=	Wii U Emulator
WWW=		https://cemu.info

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON= Only Espresso Recompiler backends for aarch64, amd64 

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		rapidjson>0:devel/rapidjson \
		boost-libs>0:devel/boost-libs \
		glm>0:math/glm \
		glslang>0:graphics/glslang \
		spirv-tools>0:graphics/spirv-tools \
		libfmt>0:devel/libfmt \
		png>0:graphics/png

LIB_DEPENDS=	libpugixml.so:textproc/pugixml \
		libcurl.so:ftp/curl \
		libzip.so:archivers/libzip \
		libboost_program_options.so:devel/boost-libs

USES=		cmake compiler:c++20-lang desktop-file-utils gl gnome \
		libtool perl5 pkgconfig sdl ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	kreinholz
GH_PROJECT=	Cemu-upstream
GH_TAGNAME=	d18ecc0
GH_TUPLE?=	mozilla:cubeb:2071354a69aca7ed6df3b4222e305746c2113f60:cubeb/dependencies/cubeb \
		arsenm:sanitizers-cmake:aab6948fa863bc1cbe5d0850bc46b9ef02ed4c1a:sanitizerscmake/dependencies/cubeb/cmake/sanitizers-cmake \
		Exzap:ZArchive:d2c717730092c7bf8cbb033b12fd4001b7c4d932:ZArchive/dependencies/ZArchive \
		ocornut:imgui:f65bcf481ab34cd07d3909aab1479f409fa79f2f:imgui/dependencies/imgui

USE_GL=		gl glut
USE_GNOME=	gtk30
USE_SDL=	sdl2
USE_XORG=	x11
USE_WX=		3.2+
WX_COMPS=	wx

CMAKE_ARGS+=	-DENABLE_BLUEZ:BOOL=OFF \
		-DENABLE_DISCORD_RPC:BOOL=OFF \
		-DENABLE_FERAL_GAMEMODE:BOOL=OFF \
		-DENABLE_HIDAPI:BOOL=OFF \
		-DENABLE_VCPKG:BOOL=OFF

MAKE_ENV+=	DESTDIR="${STAGEDIR}"

LDFLAGS+=	-Wl,--as-needed

DEBUG_CMAKE_ON=	wxWidgets_USE_DEBUG

OPTIONS_DEFINE=		WAYLAND
OPTIONS_DEFAULT=	WAYLAND

WAYLAND_DESC=		Build with Wayland support
WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND
WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland

do-install:
	${INSTALL_KLD} ${WRKSRC}/bin/Cemu_release ${STAGEDIR}${PREFIX}/bin
	${MV} ${STAGEDIR}${PREFIX}/bin/Cemu_release ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_KLD} ${WRKSRC}/dist/linux/info.cemu.Cemu.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_KLD} ${WRKSRC}/dist/linux/info.cemu.Cemu.metainfo.xml ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_KLD} ${WRKSRC}/dist/linux/info.cemu.Cemu.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/gameProfiles/default
	for f in ${WRKSRC}/bin/gameProfiles/default/*;do \
		${CP} $${f} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/gameProfiles/default; \
	done
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/sharedFonts
	${INSTALL_DATA} ${WRKSRC}/bin/resources/sharedFonts/*.ttf ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/sharedFonts
	${INSTALL_DATA} ${WRKSRC}/dist/network_services.xml ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ar
	${INSTALL_DATA} ${WRKSRC}/bin/resources/ar/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ar
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ca
	${INSTALL_DATA} ${WRKSRC}/bin/resources/ca/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ca
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/de
	${INSTALL_DATA} ${WRKSRC}/bin/resources/de/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/de
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/es
	${INSTALL_DATA} ${WRKSRC}/bin/resources/es/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/es
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/fr
	${INSTALL_DATA} ${WRKSRC}/bin/resources/fr/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/fr
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/he
	${INSTALL_DATA} ${WRKSRC}/bin/resources/he/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/he
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/hu
	${INSTALL_DATA} ${WRKSRC}/bin/resources/hu/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/hu
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/it
	${INSTALL_DATA} ${WRKSRC}/bin/resources/it/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/it
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ja
	${INSTALL_DATA} ${WRKSRC}/bin/resources/ja/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ja
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ko
	${INSTALL_DATA} ${WRKSRC}/bin/resources/ko/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ko
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/nb
	${INSTALL_DATA} ${WRKSRC}/bin/resources/nb/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/nb
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/nl
	${INSTALL_DATA} ${WRKSRC}/bin/resources/nl/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/nl
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/pl
	${INSTALL_DATA} ${WRKSRC}/bin/resources/pl/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/pl
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/pt
	${INSTALL_DATA} ${WRKSRC}/bin/resources/pt/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/pt
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ru
	${INSTALL_DATA} ${WRKSRC}/bin/resources/ru/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/ru
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/sv
	${INSTALL_DATA} ${WRKSRC}/bin/resources/sv/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/sv
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/tr
	${INSTALL_DATA} ${WRKSRC}/bin/resources/tr/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/tr
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/uk
	${INSTALL_DATA} ${WRKSRC}/bin/resources/uk/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/uk
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/zh
	${INSTALL_DATA} ${WRKSRC}/bin/resources/zh/* ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources/zh

post-install:
.if exists(/usr/bin/elfctl)
	${ELFCTL} -e +wxneeded ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif

.include <bsd.port.mk>
