#pragma once
#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../entity/entity.h"

typedef struct {
    Entity entity;    
} Player;

void player_init(Player* player, GameContext* context);

void player_update(Player* player);

void player_draw(Player* player);
