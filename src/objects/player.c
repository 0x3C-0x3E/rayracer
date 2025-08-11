#include "player.h"
#include <math.h>
#include <raylib.h>

void player_init(Player* player, GameContext* context) {
    player->entity = (Entity) {
        .texture = LoadTexture("res/cars/player_blue.png"),
        .texture_rect = (Rectangle) {0, 0, 16, 16},
    };
    
    player->turn_speed = 200.0f;
    player->acceleration = 250.0f;
    player->deceleration = 500.0f;
    player->max_speed = 300.0f;

    player->friction = 0.95f;

    entity_init(&player->entity, context);
    entity_reset_pos(&player->entity);
}

void player_update(Player* player) {
    float dt = player->entity.context->renderer->dt;

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        player->entity.angle -= player->turn_speed * dt; 
    }

    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        player->entity.angle += player->turn_speed * dt; 
    }

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        player->entity.speed += player->acceleration * dt;
    } else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        player->entity.speed -= player->deceleration * dt;
    } else {
        player->entity.speed *= player->friction;
    }

    if (player->entity.speed > player->max_speed) {
        player->entity.speed = player->max_speed;
    } else if (player->entity.speed < -player->max_speed) {
        player->entity.speed = -player->max_speed;
    }

    float angle_rad = (player->entity.angle - 90) * (M_PI / 180);
    player->entity.x_vel = cos(angle_rad) * player->entity.speed;
    player->entity.y_vel = sin(angle_rad) * player->entity.speed;

    entity_update_pos(&player->entity);
}

void player_draw(Player* player) {
    // char buffer[255];
    // sprintf(buffer,"Player: x %f, y %f, angle: %d\n", player->entity.x, player->entity.y, player->entity.angle);
    // renderer_draw_text(player->entity.context->renderer, buffer, 30, 50);
    DrawFPS(30, 30);
    entity_draw(&player->entity);
}
