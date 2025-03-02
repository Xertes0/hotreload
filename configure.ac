AC_INIT([hotreload], [0.1])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_MACRO_DIRS([m4])

dnl Usually this feature would be opt-in.
dnl Since this is a demo, it's enabled by default.
AC_ARG_ENABLE([hotreload],
        AS_HELP_STRING([--disable-hotreload],
                       [Disable the hotreload feature]))

CFLAGS="$CFLAGS -std=c11"

AC_PROG_CC
LT_INIT

AS_IF([test "x$enable_hotreload" != "xno"], [
	AM_PROG_AR
])

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

AM_CONDITIONAL([HOTRELOAD], [test "x$enable_hotreload" != "xno"])

AC_CONFIG_FILES([
        Makefile
        src/Makefile
])
AC_OUTPUT


