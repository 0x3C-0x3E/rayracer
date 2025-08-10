#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../renderer/renderer.h"
#include "../scenes/game.h"

typedef struct {
    bool running;
    Renderer renderer;
    
    Game game;
} App;

void app_init_raylib(App* app);

void app_init(App* app);

void app_run(App* app);
