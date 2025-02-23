AM_CFLAGS = -Wall -Wextra -Werror -pedantic

lib_LTLIBRARIES = libgame.la
libgame_la_SOURCES = game.c
libgame_la_LDFLAGS = -module -shared -export-dynamic
# is include_HEADERS needed?
include_HEADERS = game.h

bin_PROGRAMS = game
game_SOURCES = main.c hotreload.c
