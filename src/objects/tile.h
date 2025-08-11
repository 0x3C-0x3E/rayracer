#pragma once
#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../entity/entity.h"
#include "../util/utils.h"

typedef struct {
    Entity entity;
} Tile;

void tile_init(Tile* tile, GameContext* context);

void tile_update(Tile* tile);

void tile_draw(Tile* tile);
