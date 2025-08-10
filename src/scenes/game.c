#include "game.h"

void game_init(Game* game, Renderer* renderer) {
    game->context = (GameContext) {
        .renderer = renderer,
    };
}

void game_update(Game* game) {

}

void game_draw(Game* game) {
    renderer_draw_text(game->context.renderer, "Hello from the game scene", 30, 30);
}
