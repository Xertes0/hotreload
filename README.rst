Hot Reload Demo
===============

This project uses raylib_ to open a simple window with text on it.  You
can then edit ``src/game.c`` to change this text or modify the code
however you like. After saving the changes you can rebuild the project
and the application will automatically hot reload the changed library.

Technical details
-----------------

- ``game.c`` is compiled as a shared library which is then opened with
  ``dlopen(3)``.

- The ``inotify(7)`` kernel subsystem is used for monitoring the
  filesystem changes.

.. _raylib: https://github.com/raysan5/raylib
