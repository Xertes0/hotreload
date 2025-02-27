#ifndef HOTRELOAD_GAME_H
#define HOTRELOAD_GAME_H

#ifdef HOTRELOAD_DO_DEFINE
#define PTR(X) X
#else
#define PTR(X) (*X)
#endif

#ifdef HOTRELOAD_NO_EXTERN
#define EXT
#else
#define EXT extern
#endif

struct game_state {
	int counter;
};

EXT struct game_state PTR(*state_g);

EXT void PTR(game_tick)();

#undef PTR
#undef EXT

#endif // HOTRELOAD_GAME_H
