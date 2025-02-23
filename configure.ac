AC_INIT([hotreload], [0.1])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_MACRO_DIRS([m4])

CFLAGS="$CFLAGS -std=c11"

AC_PROG_CC
AM_PROG_AR
LT_INIT

AC_SEARCH_LIBS([pthread_create], [pthread], [], [
	AC_MSG_ERROR([Unable to find pthread_create() function.])
])

AC_CHECK_HEADERS([raylib.h], [], [
	AC_MSG_ERROR([Unable to find raylib.h header.])
])
AC_SEARCH_LIBS([InitWindow], [raylib], [], [
	AC_MSG_ERROR([Unable to find InitWindow() function.])
])

AC_CHECK_HEADERS([dlfcn.h], [], [
	AC_MSG_ERROR([Unable to find dlfcn.h header.])
])
AC_SEARCH_LIBS([dlopen], [dl], [], [
	AC_MSG_ERROR([Unable to find dlopen() function.])
])

AC_CONFIG_FILES([
        Makefile
        src/Makefile
])
AC_OUTPUT


