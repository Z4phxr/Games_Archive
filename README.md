# Console Games Collection

These projects come from a phase where I practiced game development by implementing mechanics entirely in ASCII. It was a great way to focus on logic, data structures, and gameplay without worrying about real graphics. My GPU has never been so bored.

## About

A collection of console-based games written in C/C++ as a passion project in 2023. These games run directly in the Windows terminal using the Console API for rendering and input handling.

## Games

- **Blackjack** - Classic card game where you try to beat the dealer
- **FloppyBirds** - Navigate a bird through obstacles
- **GoogleDino** - The Chrome dinosaur runner game recreated in terminal
- **LabiryntSolver** - Watch an algorithm solve a maze in real-time
- **Snake** - The legendary Nokia classic
- **SpaceGame** - Shoot enemies in space

## Project Structure

```
SpaceGame/
├── game_lib/           # some functions I was using a lot
│   ├── game_lib.cpp
│   ├── game_lib.h
│   └── main.cpp
├── games/
│   ├── Blackjack/
│   ├── FloppyBirds/
│   ├── GoogleDino/
│   ├── LabiryntSolver/
│   ├── Snake/
│   └── SpaceGame/
└── README.md
```

## What I Learned

Working on these projects taught me several practical C++ concepts:

- **Bitwise Operations for Input Handling**: Using bit flags (`1 << 0`, `1 << 1`, etc.) to handle simultaneous key presses, allowing diagonal movement with clean, efficient code
- **Dynamic Memory Management**: Implementing 2D arrays with `malloc` for game boards, understanding pointer arithmetic and manual memory allocation
- **Windows Console API**: Using `SetConsoleCursorPosition` for cursor control, `_kbhit()` and `_getch()` for non-blocking input
- **Game Loop Architecture**: Creating smooth game loops with proper timing using `Sleep()`, separating input/update/render phases
- **Collision Detection**: Building point-based and object-based collision systems for game interactions
- **Pathfinding Basics**: Implementing a simple follow/chase algorithm for enemy AI in the game library, probably the most fun one.
- **Code Reusability**: Creating a shared library (`game_lib`) with common game functions like board management, drawing, and movement

The `game_lib` folder contains experimental reusable components I built while working on these games, a 2D board system, point/obstacle classes, collision detection, and a simple enemy AI that follows the player.

## Requirements

- Windows OS
- MinGW GCC/G++ compiler

## How to Compile & Run

**Note:** If you experience rendering issues or glitches, try maximizing your terminal window or switching to fullscreen mode for the best experience.

### Blackjack
```powershell
g++ games/Blackjack/blackjack.c games/Blackjack/karty.c games/Blackjack/main.c -o blackjack.exe
.\blackjack.exe
```

### FloppyBirds
```powershell
g++ games/FloppyBirds/main.cpp games/FloppyBirds/func.cpp -o floppybird.exe
.\floppybird.exe
```

### GoogleDino
```powershell
g++ games/GoogleDino/main.cpp games/GoogleDino/game.cpp games/GoogleDino/func.cpp -o dino.exe
.\dino.exe
```

### LabiryntSolver
```powershell
g++ games/LabiryntSolver/main.cpp games/LabiryntSolver/game_lib.cpp -o labirynt.exe
.\labirynt.exe
```

### Snake
```powershell
g++ games/Snake/snake.cpp -o snake.exe
.\snake.exe
```

### SpaceGame
```powershell
g++ games/SpaceGame/SpaceGame.cpp games/SpaceGame/func.cpp -o spacegame.exe
.\spacegame.exe
```

Made with C++ in 2023
