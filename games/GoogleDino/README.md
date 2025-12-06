GoogleDino

A console Dino/Chrome offline-style game written in C++.

Keep:
- `main.cpp` — main loop
- `game.cpp`, `func.cpp`, `func.h` — game logic

Build (Windows, MinGW/g++):
```powershell
g++ main.cpp game.cpp func.cpp -o dino.exe
./dino.exe
```

Note: Executables and build artifacts are excluded by `.gitignore`.