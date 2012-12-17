From avg@freebsd.org

Without this patch any waits for periods shorter than a single tick return
immediately leading to a lot of unnecessary spinning.  For example, I observe that
my guest's idle loop does a lot of sleeps with periods slightly shorter than 1 ms
(1/hz), e.g. 900us.  All that waiting turns into pure spinning and VirtualBox eats
100% of a core.

--- src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h.orig     2012-12-12 20:09:29.675203802 +0200
+++ src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h  2012-12-12 20:11:53.604203131 +0200
@@ -82,6 +82,8 @@
     uint64_t cTicks = ASMMultU64ByU32DivByU32(uTimeout, hz, UINT32_C(1000000000));
     if (cTicks >= INT_MAX)
         return RTSEMWAIT_FLAGS_INDEFINITE;
+    else if (cTicks == 0 && uTimeout > 0)
+        pWait->iTimeout     = 1;
     else
         pWait->iTimeout     = (int)cTicks;
 #endif
