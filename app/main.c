#include "../core/game.h"
#include <stdio.h> // For printf

// main is the entry point of the program.
// For now, it will just initialize the game and run a placeholder loop.
int main() {
    GameState game;
    
    // Initialize the game state.
    game_init(&game);
    
    printf("Tetris game initialized. Starting main loop (placeholder).\n");
    
    // The main game loop. It will run as long as the game is not over.
    while (!game_is_over(&game)) {
        // --- In the future, this loop will contain: ---
        
        // TODO: 1. Get user input (non-blocking).
        // int input = get_input(); 
        
        // TODO: 2. Update the game state based on input and time.
        // game_update(&game, input);
        
        // TODO: 3. Render the game state to the console.
        // render_game(&game);
        
        // TODO: 4. Wait for a short duration to control game speed.
        // sleep_ms(500);
    }
    
    // This will be printed when the game loop ends.
    printf("Game Over!\n");
    printf("Final Score: %d\n", game.score);
    
    return 0;
}
