AC_INIT([hdt], [1.1.3], [pablo.torres.t@gmail.com])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build])
AC_CONFIG_HEADERS([build/config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
#AM_SILENT_RULES([yes])

AC_PROG_CXX
AC_LANG([C++])
AC_PROG_INSTALL
AC_PROG_CPP
AM_PROG_AR
LT_INIT([shared static])

# Checks for libraries
AC_ARG_WITH([libcds-prefix], 
  AS_HELP_STRING([--with-libcds-prefix=DIR],[Enables cds library]), 
  [AC_SUBST(LIBCDS_HDR,"-I$with_libcds_prefix/include")
   AC_SUBST(LIBCDS_LIB,"-L$with_libcds_prefix/lib -lcds")
   AC_SUBST(LIBCDS_CFLAGS,"-DHAVE_CDS")
   AC_DEFINE([HAVE_CDS],[1],[cds available])
   AC_MSG_NOTICE([LIBCDS enabled])])

AC_ARG_WITH([raptor2-prefix],
  AS_HELP_STRING([--with-raptor2-prefix=DIR], [Enables raptor2 library]),
  [AC_SUBST(RAPTOR2_HDR,"-I$with_raptor2_prefix/include")
   AC_SUBST(RAPTOR2_LIB,"-L$with_raptor2_prefix/lib -lraptor2")
   AC_SUBST(RAPTOR2_CFLAGS, "-DHAVE_RAPTOR")
   AC_DEFINE([HAVE_RAPTOR2],[1],[raptor2 available])
   AC_MSG_NOTICE([RAPTOR2 enabled])])

AC_ARG_WITH([serd-prefix],
  AS_HELP_STRING([--with-serd-prefix=DIR], [Enables serd library]),
  [AC_SUBST(SERD_HDR,"-I$with_serd_prefix/include")
   AC_SUBST(SERD_LIB,"-L$with_serd_prefix/lib -lserd-0")
   AC_SUBST(SERD_CFLAGS, "-DHAVE_SERD")
   AC_DEFINE([HAVE_SERD],[1],[serd available])
   AC_MSG_NOTICE([SERD enabled])])

AC_ARG_WITH([zlib],
  AS_HELP_STRING([--with-zlib], [Enables z library]),
  [PKG_CHECK_MODULES([zlib],[zlib],
   AC_SUBST(ZLIB_LIB,"-lz")
   AC_SUBST(HAVE_ZLIB,"-DHAVE_LIBZ"))
   AC_MSG_NOTICE([ZLIB enabled])])

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h sys/time.h])

# Check for typedefs, structures, and compiler characteristics
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

AC_CONFIG_FILES([
  Makefile
  hdt-lib/Makefile
])
AC_OUTPUT
