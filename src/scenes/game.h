#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "game_context.h"
#include "../objects/player.h"
#include "../objects/tile.h"
#include "../util/camp_array/camp_array.h"

typedef struct {
    GameContext context; 
    Player player;

    CampArray* tiles_array;
} Game;

void game_init(Game* game, Renderer* renderer);

void game_update(Game* game);

void game_draw(Game* game);
