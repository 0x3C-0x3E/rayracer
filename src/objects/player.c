#include "player.h"
#include <raylib.h>

void player_init(Player* player, GameContext* context) {
    player->entity = (Entity) {
        .texture = LoadTexture("res/cars/player_blue.png"),
        .texture_rect = (Rectangle) {0, 0, 16, 16},
    };


    entity_init(&player->entity, context);
    entity_reset_pos(&player->entity);
}

void player_update(Player* player) {
    entity_update_pos(&player->entity);
}

void player_draw(Player* player) {
    char buffer[255];
    sprintf(buffer,"Player: x %f, y %f\n", player->entity.x, player->entity.y);
    renderer_draw_text(player->entity.context->renderer, buffer, 30, 50);
    entity_draw(&player->entity);
}
