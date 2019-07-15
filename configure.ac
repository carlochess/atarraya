#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([atarraya], [0.0.1], [])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([HTTP], picohttpparser, [], AC_MSG_ERROR([Failed to find picohttpparser]))
# Checks for header files.
AC_HEADER_STDC

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
