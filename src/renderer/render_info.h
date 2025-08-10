#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct {
    Texture* texture;
    Rectangle texture_rect;

    int x, y;
    int angle;
} RenderInfo;
