#include "tetromino.h"
#include <stdlib.h> // For rand()

// This file implements the logic related to Tetris pieces (tetrominoes).

// --- Predefined Tetromino Shapes ---
// Each shape is defined in a 4x4 grid. The integer value represents the color index.
// There are 7 types of tetrominoes.

// Shape I
const int TETROMINO_I[TETROMINO_SIZE][TETROMINO_SIZE] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

// Shape O
const int TETROMINO_O[TETROMINO_SIZE][TETROMINO_SIZE] = {
    {0, 0, 0, 0},
    {0, 2, 2, 0},
    {0, 2, 2, 0},
    {0, 0, 0, 0}
};

// Shape T
const int TETROMINO_T[TETROMINO_SIZE][TETROMINO_SIZE] = {
    {0, 0, 0, 0},
    {0, 3, 0, 0},
    {3, 3, 3, 0},
    {0, 0, 0, 0}
};

// Shape L
const int TETROMINO_L[TETROMINO_SIZE][TETROMINO_SIZE] = {
    {0, 0, 0, 0},
    {0, 0, 4, 0},
    {4, 4, 4, 0},
    {0, 0, 0, 0}
};

// Shape J
const int TETROMINO_J[TETROMINO_SIZE][TETROMINO_SIZE] = {
    {0, 0, 0, 0},
    {5, 0, 0, 0},
    {5, 5, 5, 0},
    {0, 0, 0, 0}
};

// Shape S
const int TETROMINO_S[TETROMINO_SIZE][TETROMINO_SIZE] = {
    {0, 0, 0, 0},
    {0, 6, 6, 0},
    {6, 6, 0, 0},
    {0, 0, 0, 0}
};

// Shape Z
const int TETROMINO_Z[TETROMINO_SIZE][TETROMINO_SIZE] = {
    {0, 0, 0, 0},
    {7, 7, 0, 0},
    {0, 7, 7, 0},
    {0, 0, 0, 0}
};

// An array of pointers to all the shape definitions for easy random access.
const int (*TETROMINO_SHAPES[7])[TETROMINO_SIZE][TETROMINO_SIZE] = {
    &TETROMINO_I, &TETROMINO_O, &TETROMINO_T, &TETROMINO_L, &TETROMINO_J, &TETROMINO_S, &TETROMINO_Z
};

// --- Function Implementations ---

/**
 * @brief Creates a new tetromino of a random shape.
 * * @return A Tetromino struct initialized with a random shape and color.
 */
Tetromino tetromino_create_random() {
    Tetromino piece;
    int shape_index = rand() % 7; // Get a random index from 0 to 6.
    piece.color = shape_index + 1; // Color index is shape index + 1 (0 is empty).

    // Copy the selected shape into the new tetromino.
    for (int y = 0; y < TETROMINO_SIZE; ++y) {
        for (int x = 0; x < TETROMINO_SIZE; ++x) {
            // Fill with the color index where there's a block, otherwise 0.
            piece.shape[y][x] = (*TETROMINO_SHAPES[shape_index])[y][x] ? piece.color : 0;
        }
    }
    return piece;
}

/**
 * @brief Rotates a tetromino 90 degrees clockwise.
 * The rotation is performed in-place on the piece's shape grid.
 * * @param piece Pointer to the tetromino to be rotated.
 */
void tetromino_rotate(Tetromino *piece) {
    int temp[TETROMINO_SIZE][TETROMINO_SIZE] = {0};

    // Perform the rotation into a temporary grid.
    // The logic for clockwise rotation is: new_shape[x][y] = old_shape[size-1-y][x]
    for (int y = 0; y < TETROMINO_SIZE; ++y) {
        for (int x = 0; x < TETROMINO_SIZE; ++x) {
            temp[x][y] = piece->shape[TETROMINO_SIZE - 1 - y][x];
        }
    }

    // Copy the rotated shape back to the original tetromino.
    for (int y = 0; y < TETROMINO_SIZE; ++y) {
        for (int x = 0; x < TETROMINO_SIZE; ++x) {
            piece->shape[y][x] = temp[y][x];
        }
    }
}
