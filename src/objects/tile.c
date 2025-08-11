#include "tile.h"
#include <raylib.h>

void tile_init(Tile* tile, GameContext* context) {
    tile->entity = (Entity) {
        .texture = context->tileset,
        .texture_rect = (Rectangle) {32, 0, 16, 16}
    };

    entity_init(&tile->entity, context);
    entity_reset_pos(&tile->entity);
}

void tile_update(Tile* tile) {
}

void tile_draw(Tile* tile) {
    entity_draw(&tile->entity);
}
