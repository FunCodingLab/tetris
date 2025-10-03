#include "game.h"
#include <stdlib.h> // For srand
#include <time.h>   // For time

// --- Private Function Prototypes ---
// These functions are only used within this file.
static void spawn_new_piece(GameState *game);
static void update_score(GameState *game, int lines_cleared);

// --- Public Function Implementations ---

/**
 * @brief Initializes the game state for a new game.
 * * @param game Pointer to the GameState struct to be initialized.
 */
void game_init(GameState *game) {
    // Seed the random number generator. Only needs to be done once.
    srand(time(NULL));

    board_init(&game->board);
    
    game->score = 0;
    game->level = 1;
    game->lines_cleared = 0;
    game->game_over = false;

    // Create the first two pieces.
    spawn_new_piece(game); // This sets current_piece
    spawn_new_piece(game); // This moves current to next, and gets a new current
}

/**
 * @brief Updates the game state by one frame or tick.
 * This is a placeholder for now. The real logic will involve processing
 * input, moving the piece down, checking for collisions, etc.
 * * @param game Pointer to the GameState to update.
 * @param input The user input action for this frame.
 */
void game_update(GameState *game, int input) {
    // This function will be expanded significantly later.
    // For now, it does nothing to prevent the game from being unplayable
    // before we have input and rendering.
    if (game->game_over) {
        return;
    }
    
    // Example of future logic:
    // handle_input(game, input);
    // if (time_to_fall) {
    //     move_piece_down(game);
    // }
}

/**
 * @brief Checks if the game is over.
 * * @param game Pointer to the game state.
 * @return true if the game is over, false otherwise.
 */
bool game_is_over(const GameState *game) {
    return game->game_over;
}


// --- Private Function Implementations ---

/**
 * @brief Handles the spawning of a new tetromino.
 * It moves the next piece to the current piece, generates a new next piece,
 * and places the current piece at the starting position.
 * If the new piece immediately collides, the game is over.
 * * @param game Pointer to the game state.
 */
static void spawn_new_piece(GameState *game) {
    // The "next" piece becomes the "current" piece.
    game->current_piece = game->next_piece;
    
    // A new "next" piece is generated.
    game->next_piece = tetromino_create_random();

    // Set the starting position for the new current piece (top middle).
    game->current_piece.position.x = BOARD_WIDTH / 2 - TETROMINO_SIZE / 2;
    game->current_piece.position.y = 0; // Start at the top row

    // If the new piece is not in a valid position upon spawning, game over.
    if (!board_is_valid_position(&game->board, &game->current_piece)) {
        game->game_over = true;
    }
}

/**
 * @brief Updates the score and level based on the number of lines cleared.
 * * @param game Pointer to the game state.
 * @param lines_cleared The number of lines cleared in one go.
 */
static void update_score(GameState *game, int lines_cleared) {
    // Scoring model: 1 line: 40, 2 lines: 100, 3 lines: 300, 4 lines (Tetris): 1200
    // The points are multiplied by the current level.
    int points[] = {0, 40, 100, 300, 1200};
    if (lines_cleared > 0 && lines_cleared <= 4) {
        game->score += points[lines_cleared] * game->level;
    }
    
    game->lines_cleared += lines_cleared;

    // Increase level every 10 lines cleared.
    if (game->lines_cleared >= game->level * 10) {
        game->level++;
    }
}
