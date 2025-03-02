#ifndef HOTRELOAD_GAME_H
#define HOTRELOAD_GAME_H

#if defined HOTRELOAD_DO_DEFINE || !defined HOTRELOAD
#define PTR(X) X
#else
#define PTR(X) (*X)
#endif

#if defined HOTRELOAD_NO_EXTERN || !defined HOTRELOAD
#define EXT
#else
#define EXT extern
#endif

struct game_state {
	int counter;
};

#ifndef HOTRELOAD
extern
#endif
EXT struct game_state PTR(*state_g);

EXT void PTR(game_tick)();

#undef PTR
#undef EXT

#endif // HOTRELOAD_GAME_H
