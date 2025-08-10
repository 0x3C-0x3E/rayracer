#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "game_context.h"

typedef struct {
    GameContext context; 
} Game;

void game_init(Game* game, Renderer* renderer);

void game_update(Game* game);

void game_draw(Game* game);
