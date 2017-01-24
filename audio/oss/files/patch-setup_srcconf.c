--- setup/srcconf.c.orig	2017-01-24 14:09:01.712959000 +0000
+++ setup/srcconf.c	2017-01-24 14:24:49.735800000 +0000
@@ -93,7 +93,7 @@
 static int do_warning_checks=1;
 
 static char *shlib_cflags = "-shared -fPIC";
-static char *shlib_ldflags = "-shared -fPIC";
+static char *shlib_ldflags = "-shared";
 
 static char *extra_libraries = "";
 
@@ -195,7 +195,7 @@
 	{
 	  parms = "";
 	  if (getenv ("OGG_SUPPORT") != NULL)
-	    parms = "-DOGG_SUPPORT";
+	    parms = "-DOGG_SUPPORT -I%%LOCALBASE%%/include";
 	}
 
       if (strcmp (line, "project") == 0)
@@ -913,7 +913,7 @@ printf("Symlink %s -> %s\n", source, tar
   if (config_phpmake)
      fprintf (f, "<?php require getenv(\"PHPMAKE_LIBPATH\") . \"library.php\"; phpmake_makefile_top_rules(); ?>\n");
 
-  fprintf (f, "CC=%s\n", conf.ccomp);
+  fprintf (f, "CC=%s\n", targetcc);
   // fprintf (f, "LD=ld\n");
   fprintf (f, "HOSTCC=%s\n", hostcc);
   fprintf (f, "CPLUSPLUS=%s\n", conf.cplusplus);
