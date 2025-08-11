#include "entity.h"

void entity_init(Entity* entity, GameContext* context) {
    entity->context = context;
}

void entity_reset_pos(Entity* entity) {
    entity->x     = 0;
    entity->y     = 0;
    entity->x_vel = 0;
    entity->y_vel = 0;
    entity->x_acc = 0;
    entity->y_acc = 0;
    entity->speed = 0;
}

void entity_update_pos(Entity* entity) {
    entity->x_vel += entity->x_acc * entity->context->renderer->dt;
    entity->y_vel += entity->y_acc * entity->context->renderer->dt;

    entity->x += entity->x_vel * entity->context->renderer->dt;
    entity->y += entity->y_vel * entity->context->renderer->dt;
}

void entity_draw(Entity* entity) {
    RenderInfo render_info = {
        .angle = entity->angle,
        .texture = entity->texture,
        .texture_rect = entity->texture_rect,
        .x = entity->x,
        .y = entity->y,
    };

    renderer_draw(entity->context->renderer, &render_info);
}

