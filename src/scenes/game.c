#include "game.h"

void game_init(Game* game, Renderer* renderer) {
    game->context = (GameContext) {
        .renderer = renderer,
    };

    player_init(&game->player, &game->context);
}

void game_update(Game* game) {
    player_update(&game->player);
}

void game_draw(Game* game) {
    player_draw(&game->player);
}
