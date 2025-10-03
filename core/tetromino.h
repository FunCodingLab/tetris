#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdbool.h>

// All tetrominoes are defined within a 4x4 grid.
#define TETROMINO_SIZE 4

// A simple structure to represent a point or coordinate.
typedef struct {
    int x;
    int y;
} Point;

// Represents a single Tetris piece (tetromino).
typedef struct {
    // The 2D array defining the shape of the piece. 1 for a block, 0 for empty.
    int shape[TETROMINO_SIZE][TETROMINO_SIZE];
    
    // The top-left position of the tetromino's 4x4 grid on the game board.
    Point position;
    
    // An identifier for the color, to be used by the renderer.
    int color;

} Tetromino;

#endif // TETROMINO_H
