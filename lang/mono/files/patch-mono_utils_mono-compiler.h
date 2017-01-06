--- mono/utils/mono-compiler.h.orig	2017-01-06 21:30:42.356910000 +0000
+++ mono/utils/mono-compiler.h	2017-01-06 21:30:48.723004000 +0000
@@ -54,7 +54,7 @@
    For now we will disable this. */
 #define MONO_TLS_FAST
 #else
-#define MONO_TLS_FAST __attribute__((tls_model("local-dynamic")))
+#define MONO_TLS_FAST __attribute__((visibility("protected"), tls_model("local-dynamic")))
 #endif
 #endif
 
