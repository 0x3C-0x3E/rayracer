#pragma once
#include "../renderer/renderer.h"
#include <raylib.h>

typedef struct {
    Renderer* renderer;
    Texture tileset;
} GameContext;
