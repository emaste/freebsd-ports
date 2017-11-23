From 5ec572c4a5ff3569c2ff95ae2945758cd8a876be Mon Sep 17 00:00:00 2001
From: Ed Maste <emaste@freebsd.org>
Date: Thu, 23 Nov 2017 08:57:33 -0500
Subject: [PATCH] Use sys/capsicum.h instead of sys/capability.h

FreeBSD moved the Capsicum header to sys/capsicum.h in r263232, because
the original name conflicts with the draft POSIX.1e capability.h used on
some systems (e.g., Linux).  The new header exists in all versions of
FreeBSD from 10.1 on.
---
 configure.ac   | 1 -
 libpkg/ssh.c   | 2 +-
 src/audit.c    | 2 +-
 src/clean.c    | 2 +-
 src/event.c    | 2 +-
 src/info.c     | 2 +-
 src/ssh.c      | 2 +-
 src/updating.c | 2 +-
 src/upgrade.c  | 2 +-
 9 files changed, 8 insertions(+), 9 deletions(-)

diff --git a/configure.ac b/configure.ac
index 68b7eaf6d..87b60f3bf 100644
--- configure.ac
+++ configure.ac
@@ -138,7 +138,6 @@ AC_CHECK_HEADERS_ONCE([netinet/in6.h])
 AC_CHECK_HEADERS_ONCE([sys/statfs.h])
 AC_CHECK_HEADERS_ONCE([sys/statvfs.h])
 AC_CHECK_HEADERS_ONCE([dirent.h], [sys/ndir.h], [sys/dir.h], [ndir.h])
-AC_CHECK_HEADERS_ONCE([sys/capability.h])
 AC_CHECK_HEADERS_ONCE([sys/capsicum.h])
 AC_CHECK_HEADERS_ONCE([bsd/stdlib.h])
 AC_CHECK_HEADERS_ONCE([bsd/string.h])
diff --git a/libpkg/ssh.c b/libpkg/ssh.c
index e9fcd306c..ac52a4fab 100644
--- libpkg/ssh.c
+++ libpkg/ssh.c
@@ -29,7 +29,7 @@
 #include "pkg_config.h"
 #endif
 #ifdef HAVE_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 #include <sys/types.h>
 #include <sys/param.h>
diff --git a/src/audit.c b/src/audit.c
index 81dff665e..df523ac86 100644
--- src/audit.c
+++ src/audit.c
@@ -52,7 +52,7 @@
 #endif
 
 #ifdef HAVE_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 
 #include <pkg.h>
diff --git a/src/clean.c b/src/clean.c
index b0cb4f1f1..8e3a8a17a 100644
--- src/clean.c
+++ src/clean.c
@@ -36,7 +36,7 @@
 #include <sys/param.h>
 
 #ifdef HAVE_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 
 #include <assert.h>
diff --git a/src/event.c b/src/event.c
index 60d6f98ef..9320d89c6 100644
--- src/event.c
+++ src/event.c
@@ -40,7 +40,7 @@
 #include <sys/socket.h>
 
 #ifdef HAVE_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 
 #include <err.h>
diff --git a/src/info.c b/src/info.c
index 6b41feca5..7cbb40387 100644
--- src/info.c
+++ src/info.c
@@ -33,7 +33,7 @@
 #endif
 
 #ifdef HAVE_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 
 #include <err.h>
diff --git a/src/ssh.c b/src/ssh.c
index 4699ef100..95ffb7759 100644
--- src/ssh.c
+++ src/ssh.c
@@ -29,7 +29,7 @@
 #endif
 
 #ifdef HAVE_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 
 #include <sysexits.h>
diff --git a/src/updating.c b/src/updating.c
index 5f08fa26e..8c5dbfd53 100644
--- src/updating.c
+++ src/updating.c
@@ -30,7 +30,7 @@
 #endif
 
 #ifdef HAVE_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 
 #include <sys/queue.h>
diff --git a/src/upgrade.c b/src/upgrade.c
index 99715c005..820d2b902 100644
--- src/upgrade.c
+++ src/upgrade.c
@@ -48,7 +48,7 @@
 #endif
 
 #ifdef HAVE_CAPSICUM
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 #endif
 #include "pkgcli.h"
 
