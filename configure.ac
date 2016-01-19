AC_INIT([hdt], [1.1.2], [email@someone.com])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
LT_INIT
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
#AM_SILENT_RULES([yes])

EXTERNAL_CFLAGS="$CFLAGS"
AC_PROG_CXX
AC_ARG_WITH([libcds-prefix], 
  AS_HELP_STRING([--with-libcds-prefix=DIR],[Enables cds library]), 
  [AC_SUBST(LIBCDS_HDR,"-I$with_libcds_prefix/include")
   AC_SUBST(LIBCDS_LIB,"-L$with_libcds_prefix/lib -lcds")
   AC_SUBST(LIBCDS_CFLAGS,"-DHAVE_CDS")
   AC_DEFINE([HAVE_CDS],[1],[cds available])
   AC_MSG_NOTICE([LIBCDS enabled])])
AC_CONFIG_FILES([
  Makefile
  hdt-lib/Makefile
])
AC_OUTPUT
