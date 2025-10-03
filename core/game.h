#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "tetromino.h"
#include <stdbool.h>

// Encapsulates the entire state of the game.
typedef struct {
    Board board;
    Tetromino current_piece;
    Tetromino next_piece;
    
    int score;
    int level;
    int lines_cleared;
    
    bool game_over;
} GameState;

// --- Function Prototypes for Game Logic ---

// Initializes the game state for a new game.
void game_init(GameState *game);

// Updates the game by one tick, processing user input and game physics.
// The input parameter will represent a user action (e.g., move left, rotate).
void game_update(GameState *game, int input);

// Checks if the game is over.
bool game_is_over(const GameState *game);

#endif // GAME_H
