#pragma once
#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../entity/entity.h"
#include "../util/utils.h"

typedef struct {
    Entity entity;    

    int accelerating;

    float turn_speed;
    float acceleration;
    float deceleration;
    float max_speed;

    float friction;
} Player;

void player_init(Player* player, GameContext* context);

void player_update(Player* player);

void player_draw(Player* player);
