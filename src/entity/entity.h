#pragma once
#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../scenes/game_context.h"
#include "../renderer/render_info.h"
#include "../renderer/renderer.h"

typedef struct {
    float x;
    float y;

    float x_vel, y_vel, x_acc, y_acc;
    
    Rectangle texture_rect;
    Texture texture;
    
    GameContext* context;

} Entity;

void entity_init(Entity* entity, GameContext* context);

void entity_reset_pos(Entity* entity);

void entity_update_pos(Entity* entity);

void entity_draw(Entity* entity);
