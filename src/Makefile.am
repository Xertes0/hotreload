sanitizers = -fsanitize=address,leak,undefined

AM_CFLAGS = -Wall -Wextra -Werror -pedantic -ggdb -Og $(sanitizers)
AM_LDFLAGS = $(sanitizers)

lib_LTLIBRARIES = libgame.la
libgame_la_SOURCES = game.c
libgame_la_LDFLAGS = -module -shared -export-dynamic
# is include_HEADERS needed?
include_HEADERS = game.h

bin_PROGRAMS = game
game_SOURCES = main.c hotreload.c
