#include "player.h"
#include <math.h>
#include <raylib.h>
#include "../util/utils.h"


static float lerp_angle(float current, float target, float dt, float lerp_speed);

void player_init(Player* player, GameContext* context) {
    player->entity = (Entity) {
        .texture = LoadTexture("res/cars/player_blue.png"),
        .texture_rect = (Rectangle) {0, 0, 16, 16},
    };
    
    player->turn_speed = 100.0f;
    player->acceleration = 500.0f;
    player->deceleration = 500.0f;
    player->max_speed = 300.0f;

    player->friction = 0.99f;

    player->acc_dir = 0;

    entity_init(&player->entity, context);
    entity_reset_pos(&player->entity);
}

void player_update(Player* player) {
    float dt = player->entity.context->renderer->dt;


    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        player->entity.speed += player->acceleration * dt;
        player->acc_dir = 1;
    } else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        player->entity.speed -= player->deceleration * dt;
        player->acc_dir = -1;
    } else {
        player->entity.speed *= player->friction;
        player->acc_dir = 0;
    }

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        player->entity.angle -= (player->acc_dir >= 0) ? player->turn_speed * dt : -player->turn_speed * dt;
    }

    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        player->entity.angle += (player->acc_dir >= 0) ? player->turn_speed * dt : -player->turn_speed * dt; 
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
    player->entity.context->renderer->camera.target = (Vector2) {
        player->entity.x * player->entity.context->renderer->scale,
        player->entity.y * player->entity.context->renderer->scale,
    };
    player->entity.context->renderer->camera.rotation = lerp_angle(
        player->entity.context->renderer->camera.rotation,
        -player->entity.angle,
        player->entity.context->renderer->dt,
        5.0f
    );
    
    renderer_pause_drawing_scene(player->entity.context->renderer);
    // renderer_draw_text(player->entity.context->renderer, "1234567890 - the quick brown fox jumps over the lazy dog", 50, 50);
    DrawFPS(30, 30);
    renderer_resume_drawing_scene(player->entity.context->renderer);

    entity_draw(&player->entity);
}

static float lerp_angle(float current, float target, float dt, float lerp_speed) {
    // Normalize both angles to [0, 360)
    while (current < 0) current += 360.0f;
    while (current >= 360.0f) current -= 360.0f;
    while (target < 0) target += 360.0f;
    while (target >= 360.0f) target -= 360.0f;

    // Find shortest difference (-180 to 180)
    float diff = target - current;
    if (diff > 180.0f)  diff -= 360.0f;
    if (diff < -180.0f) diff += 360.0f;

    // Interpolate by moving toward target
    float change = diff * fminf(dt * lerp_speed, 1.0f);
    return current + change;
}
