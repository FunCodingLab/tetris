# Console Tetris in C

This is a cross-platform Tetris game that runs entirely in the terminal. The project is written in C with a focus on clean architecture, portability, and good software engineering principles (SOLID, DRY).

It serves as an educational project to demonstrate structuring a C application in a modular and extensible way.

## Project Structure

The codebase is divided into three main layers to separate concerns:

-   `app/`: The main application entry point (`main.c`) that initializes all modules and runs the game loop.
-   `core/`: Contains all platform-independent game logic. This includes managing the board, tetrominoes, game state, score, and rules. This code can be reused with any display framework (e.g., a graphical library).
-   `platform/`: Contains all platform-specific code. This includes rendering to the console and handling user input for different operating systems (Linux, Windows).

## How to Build

### Prerequisites

-   A C compiler, such as `gcc` or `clang`.
-   The `make` build automation tool.
-   On Windows, a development environment like [MinGW-w64](https://www.mingw-w64.org/ "null") or [MSYS2](https://www.msys2.org/ "null") is recommended to provide these tools.
    

### Compilation

To compile the game, simply run the `make` command in the root directory of the project:
```
make
```

This will create an executable file named `tetris` (on Linux/macOS) or `tetris.exe` (on Windows) in the root directory.

To remove all compiled object files and the executable, run:
```
make clean
```

## How to Run

After building the project, you can run the game from your terminal:

-   **On Linux / macOS:**
    ```
    ./tetris
    ```
    -   **On Windows:**
    ```
    .\tetris.exe
    ```