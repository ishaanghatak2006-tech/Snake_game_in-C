# Snake Game in C (Windows Console)

A simple **Snake Game implemented in C** that runs in the **Windows console**.
The game uses `conio.h` for real-time keyboard input and `windows.h` for cursor positioning and timing.

---

## Features

* Classic Snake gameplay in the console
* Real-time movement using **W A S D controls**
* Snake grows when eating fruit
* Score system
* **High score saved to a file (`Score.txt`)**
* Snake dies if:

  * It hits the wall
  * It collides with itself

---

## Requirements

This program **only runs on Windows** because it uses:

* `conio.h`
* `windows.h`
* `SetConsoleCursorPosition`

Recommended compiler:

* **MinGW (GCC for Windows)**
* **MSVC (Visual Studio)**

---

## File Structure

```
snake-game/
│
├── snake.h        # Header file containing declarations and structures
├── snake.c        # Main game implementation
├── Score.txt      # Automatically created to store high score
└── README.md
```

---

## How to Compile

### Using GCC (MinGW)

Open terminal in the project folder and run:

```
gcc snake.c -o snake.exe
```

---

### Using Visual Studio Developer Command Prompt

```
cl snake.c
```

---

## How to Run

After compilation, run:

```
snake.exe
```

---

## Controls

| Key   | Action     |
| ----- | ---------- |
| **W** | Move Up    |
| **S** | Move Down  |
| **A** | Move Left  |
| **D** | Move Right |
| **X** | Exit Game  |

---

## Game Rules

1. The snake **cannot move in the opposite direction immediately**.
2. Each fruit (`@`) gives **10 points**.
3. The snake dies if:

   * It **hits the wall**
   * It **hits its own body**.

---

## Notes

* This program **will not run on Linux or macOS** because it depends on Windows-specific libraries.
* The high score is stored in a file named **`Score.txt`** in the same directory.
* The console must support ANSI escape sequences for colored output.

---

## Future Improvements

Possible improvements for the project:

* Cross-platform support (replace `conio.h`)
* Smooth rendering without flickering
* Difficulty levels
* Better graphics using a game library

---

## Author

Created as a **learning project for understanding arrays, structures, and console manipulation in C**.
