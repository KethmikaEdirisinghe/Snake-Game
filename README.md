# Snake Game (C, Windows)

Simple interactive console snake written in C. Supports non-blocking keyboard input with `conio.h` on Windows.

## Features
- Grid-based snake movement with WASD
- Immediate key handling (no Enter required)
- Clear screen redraw each frame

## Build (Windows)
Open a developer shell in the repo root (e.g., PowerShell with MinGW in PATH):

```powershell
gcc -std=c99 -Wall -Wextra -o snake.exe main.c logic.c render.c input.c
```

MSVC (Developer Command Prompt):

```bat
cl /std:c11 /W4 main.c logic.c render.c input.c user32.lib
```

## Run
PowerShell:
```powershell
PS> .\snake.exe
```
cmd.exe:
```bat
C:\path\to\repo> snake.exe
```

## Controls
- `W` `A` `S` `D` — move
- `Q` — quit

## How it works
- `logic.c` updates position and detects wall collisions.
- `input.c` polls keys non-blocking with `_kbhit` / `_getch`.
- `render.c` draws the grid and clears the console (`system("cls")`).

## Notes
- If you want the snake to move slower, increase the `Sleep` delay in `main.c`.
- If you prefer ANSI clear instead of `cls`, replace `system("cls")` in `render.c` with `printf("\x1b[2J\x1b[H");` and enable Virtual Terminal Processing in your console.
