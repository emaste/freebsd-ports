--- config/programs.m4.orig	2023-04-15 11:08:24.762548000 -0400
+++ config/programs.m4	2023-04-15 11:08:43.899166000 -0400
@@ -309,7 +309,7 @@
 
   AC_MSG_CHECKING([whether it is possible to strip libraries])
   if test x"$STRIP" != x"" && "$STRIP" -V 2>&1 | grep "GNU strip" >/dev/null; then
-    STRIP_STATIC_LIB="$STRIP -x"
+    STRIP_STATIC_LIB="$STRIP --strip-unneeded"
     STRIP_SHARED_LIB="$STRIP --strip-unneeded"
     AC_MSG_RESULT(yes)
   else
