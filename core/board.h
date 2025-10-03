#ifndef BOARD_H
#define BOARD_H

#include "tetromino.h"

// Standard Tetris board dimensions.
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

// Represents the game board.
typedef struct {
    // The grid stores the state of each cell. 0 means empty,
    // a non-zero value can represent the color of a placed block.
    int grid[BOARD_HEIGHT][BOARD_WIDTH];
} Board;

#endif // BOARD_H
