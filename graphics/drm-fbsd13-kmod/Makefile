# Created by: Johannes Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drm-fbsd13-kmod
PORTVERSION=	5.4.62.emaste.g20210131
PORTREVISION=	
CATEGORIES=	graphics kld

MAINTAINER=	emaste@FreeBSD.org
COMMENT=	DRM modules for the linuxkpi-based KMS components w/ emaste test patch

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64, i386, aarch64 and powerpc64

RUN_DEPENDS=	gpu-firmware-kmod>=g20200914:graphics/gpu-firmware-kmod

OPTIONS_DEFINE=	DEBUG SOURCE

OPTIONS_DEFAULT=	SOURCE

SOURCE_DESC=	Install kernel module sources

OPTIONS_SUB=	yes

USES=		kmod uidfix compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	emaste
GH_PROJECT=	drm-kmod
GH_TAGNAME=	b57b441102e9989f5a7d4c9f3c7f29c3790c53f0

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} < 1300136 || ${OSVERSION} >= 1400000)
IGNORE=		only supported on FreeBSD 13.
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD (missing linuxkpi functionality)
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMDGPU=""
PLIST_SUB+=	I915=""
.elif ${ARCH} == "i386"
PLIST_SUB+=	AMDGPU="@comment "
PLIST_SUB+=	I915=""
.elif ${ARCH} == "aarch64" || ${ARCH:Mpowerpc*}
PLIST_SUB+=	AMDGPU=""
PLIST_SUB+=	I915="@comment "
.else
PLIST_SUB+=	AMDGPU="@comment "
PLIST_SUB+=	I915="@comment "
.endif

KMODSRC=	${STAGEDIR}${PREFIX}/sys/modules/${PORTNAME}
SRCDIRS=	amd drivers drm i915 include linuxkpi radeon ttm

PLIST_SUB+=	KMODSRC="sys/modules/${PORTNAME}"

MAKE_ENV+=	MAKEOBJDIRPREFIX=${WRKSRC}/obj

pre-build:
		${MKDIR} ${WRKSRC}/obj
		(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} obj)

post-install-SOURCE-on:
		${MKDIR} ${KMODSRC}
		${INSTALL_DATA} ${WRKSRC}/Makefile ${KMODSRC}
		${INSTALL_DATA} ${WRKSRC}/kconfig.mk ${KMODSRC}
.for dir in ${SRCDIRS}
		cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${KMODSRC}
.endfor

.include <bsd.port.mk>
