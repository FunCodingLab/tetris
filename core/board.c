#include "board.h"
#include <string.h> // For memset

// This file implements the logic for managing the game board.

/**
 * @brief Initializes the board, setting all cells to empty (0).
 * * @param board Pointer to the Board struct to initialize.
 */
void board_init(Board *board) {
    // memset is a C standard library function that fills a block of memory
    // with a particular value. Here, we set the entire grid to 0.
    memset(board->grid, 0, sizeof(board->grid));
}

/**
 * @brief Checks if a given tetromino's position is valid on the board.
 * A position is valid if the piece is within the board boundaries and does
 * not overlap with any existing blocks on the grid.
 * * @param board Pointer to the game board.
 * @param piece Pointer to the tetromino to check.
 * @return true if the position is valid, false otherwise.
 */
bool board_is_valid_position(const Board *board, const Tetromino *piece) {
    for (int y = 0; y < TETROMINO_SIZE; ++y) {
        for (int x = 0; x < TETROMINO_SIZE; ++x) {
            // We only care about the solid parts of the tetromino.
            if (piece->shape[y][x] != 0) {
                // Calculate the actual coordinates on the board grid.
                int board_x = piece->position.x + x;
                int board_y = piece->position.y + y;

                // 1. Check if it's outside the left, right, or bottom boundaries.
                if (board_x < 0 || board_x >= BOARD_WIDTH || board_y >= BOARD_HEIGHT) {
                    return false;
                }

                // 2. Check if it's above the top of the board (which is valid).
                if (board_y < 0) {
                    continue; // Part of the shape is off-screen at the top, ignore.
                }

                // 3. Check for collision with existing blocks on the board.
                if (board->grid[board_y][board_x] != 0) {
                    return false;
                }
            }
        }
    }
    return true; // No collisions found.
}

/**
 * @brief Places (or "locks") a tetromino onto the board grid.
 * This function copies the tetromino's shape onto the board's grid at its
 * current position.
 * * @param board Pointer to the game board.
 * @param piece Pointer to the tetromino to place.
 */
void board_place_tetromino(Board *board, const Tetromino *piece) {
    for (int y = 0; y < TETROMINO_SIZE; ++y) {
        for (int x = 0; x < TETROMINO_SIZE; ++x) {
            if (piece->shape[y][x] != 0) {
                int board_x = piece->position.x + x;
                int board_y = piece->position.y + y;
                // Only place parts of the piece that are on the board.
                if (board_y >= 0 && board_y < BOARD_HEIGHT && board_x >= 0 && board_x < BOARD_WIDTH) {
                    board->grid[board_y][board_x] = piece->color;
                }
            }
        }
    }
}

/**
 * @brief Checks for and clears any completed lines on the board.
 * It shifts down the rows above any cleared lines and returns the
 * number of lines that were cleared.
 * * @param board Pointer to the game board.
 * @return The number of lines cleared.
 */
int board_clear_lines(Board *board) {
    int lines_cleared = 0;
    // Iterate over rows from the top down.
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        bool line_is_full = true;
        // Check if the current line is full.
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            if (board->grid[y][x] == 0) {
                line_is_full = false;
                break;
            }
        }

        if (line_is_full) {
            lines_cleared++;
            // Move all rows above this one down by one.
            for (int k = y; k > 0; --k) {
                for (int x = 0; x < BOARD_WIDTH; ++x) {
                    board->grid[k][x] = board->grid[k - 1][x];
                }
            }
            // Clear the top row.
            for (int x = 0; x < BOARD_WIDTH; ++x) {
                board->grid[0][x] = 0;
            }
        }
    }
    return lines_cleared;
}
