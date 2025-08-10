#include "entity.h"


void entity_draw(Entity* entity) {
    RenderInfo render_info = {
        .angle = 0,
        .texture = entity->texture_ptr,
        .texture_rect = entity->texture_rect,
        .x = entity->x,
        .y = entity->y,
    };

    renderer_draw(entity->context->renderer, &render_info);
}
