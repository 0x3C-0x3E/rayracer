#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "render_info.h"

typedef struct {
    int window_width;
    int window_height;
    int fps;

    float dt;
    
    int font_size;

    float scale;
    int camera_x, camera_y;
    Camera2D camera;
} Renderer;

void renderer_init(Renderer* renderer);

void renderer_start_drawing_scene(Renderer* renderer);

void renderer_draw(Renderer* renderer, RenderInfo* render_info);

void renderer_draw_text(Renderer* renderer, const char* text, int x, int y);

void renderer_end_drawing_scene(Renderer* renderer);

