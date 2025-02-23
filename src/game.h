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

EXT void PTR(main_loop)();

#undef PTR
#undef EXT

#endif // HOTRELOAD_GAME_H
