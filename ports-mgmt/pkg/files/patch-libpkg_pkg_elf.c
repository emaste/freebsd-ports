diff --git a/libpkg/pkg_elf.c b/libpkg/pkg_elf.c
index f8c43e15e..20c766bed 100644
--- libpkg/pkg_elf.c
+++ libpkg/pkg_elf.c
@@ -256,6 +256,7 @@ analyse_elf(struct pkg *pkg, const char *fpath)
 	size_t dynidx;
 	const char *myarch;
 	const char *shlib;
+	char *rpath = NULL;
 
 	bool is_shlib = false;
 
@@ -398,13 +399,12 @@ analyse_elf(struct pkg *pkg, const char *fpath)
 				pkg_addshlib_provided(pkg, shlib);
 		}
 
-		if (dyn->d_tag != DT_RPATH && dyn->d_tag != DT_RUNPATH)
-			continue;
-		
-		shlib_list_from_rpath(elf_strptr(e, sh_link, dyn->d_un.d_val),
-				      bsd_dirname(fpath));
-		break;
+		if ((dyn->d_tag == DT_RPATH || dyn->d_tag == DT_RUNPATH) &&
+		    rpath == NULL)
+			rpath = elf_strptr(e, sh_link, dyn->d_un.d_val);
 	}
+	if (rpath != NULL)
+		shlib_list_from_rpath(rpath, bsd_dirname(fpath));
 
 	/* Now find all of the NEEDED shared libraries. */
 
