AC_PREREQ([2.69])
AC_INIT([ustaticserver], [0.1])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CHECK_LIB(pthread, pthread_create)
AC_CHECK_HEADERS([pthread.h])

AC_PROG_CC_STDC

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile include/Makefile])

AC_OUTPUT
