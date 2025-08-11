#include "game.h"
#include <raylib.h>

void game_init(Game* game, Renderer* renderer) {
    game->context = (GameContext) {
        .renderer = renderer,
        .tileset = LoadTexture("res/levels/desert_tileset.png"),
    };

    player_init(&game->player, &game->context);

    game->tiles_array = camp_array_new(sizeof(Tile));
    for (size_t i = 0; i < 10; ++i) {
        Tile t = {0};
        tile_init(&t, &game->context);
        t.entity.x = i * 16;
        camp_array_append(game->tiles_array, &t);
    }
}

void game_update(Game* game) {
    for (size_t i = 0; i < camp_array_get_size(game->tiles_array); ++i) {
        tile_update(camp_array_get(game->tiles_array, i));
    }

    player_update(&game->player);
}

void game_draw(Game* game) {
    for (size_t i = 0; i < camp_array_get_size(game->tiles_array); ++i) {
        tile_draw(camp_array_get(game->tiles_array, i));
    }
    player_draw(&game->player);
}
