AC_INIT([hdt], [1.1.2], [pablo.torres@insight-centre.com])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build])
AC_CONFIG_HEADERS([build/config.h])
LT_INIT([shared static])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_SILENT_RULES([yes])

AC_PROG_CXX
AC_LANG([C++])
AC_PROG_INSTALL
AC_PROG_CPP

# Checks for libraries
AC_ARG_WITH([libcds-prefix], 
  AS_HELP_STRING([--with-libcds-prefix=DIR],[Enables cds library]), 
  [AC_SUBST(LIBCDS_HDR,"-I$with_libcds_prefix/include")
   AC_SUBST(LIBCDS_LIB,"-L$with_libcds_prefix/lib -lcds")
   AC_SUBST(LIBCDS_CFLAGS,"-DHAVE_CDS")
   AC_DEFINE([HAVE_CDS],[1],[cds available])
   AC_MSG_NOTICE([LIBCDS enabled])])

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
