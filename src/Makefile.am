sanitizers = -fsanitize=address,leak,undefined

AM_CFLAGS = -Wall -Wextra -Werror -pedantic -ggdb -Og $(sanitizers)
AM_LDFLAGS = $(sanitizers)

bin_PROGRAMS = game
game_SOURCES = main.c
# https://www.gnu.org/savannah-checkouts/gnu/automake/manual/html_node/Objects-created-both-with-libtool-and-without.html
game_CFLAGS = $(AM_CFLAGS)

hotreload_sources = game.c

if HOTRELOAD
game_SOURCES += hotreload.c
game_CFLAGS += -DHOTRELOAD

lib_LTLIBRARIES = libgame.la
libgame_la_SOURCES = $(hotreload_sources)
libgame_la_LDFLAGS = -module -shared -export-dynamic
# is include_HEADERS needed?
include_HEADERS = game.h
else
game_SOURCES += $(hotreload_sources)
endif
