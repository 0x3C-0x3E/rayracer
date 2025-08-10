#include "renderer.h"
#include <raylib.h>

void renderer_init(Renderer* renderer) {
    InitWindow(renderer->window_width, renderer->window_height, "RayRacer");
    SetTargetFPS(renderer->fps);
}

void renderer_start_drawing(Renderer* renderer) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void renderer_draw(Renderer* renderer, RenderInfo* render_info) {
    DrawTexturePro(render_info->texture,
                   render_info->texture_rect,
                   (Rectangle) {
                       render_info->x,
                       render_info->y,
                       render_info->texture_rect.width * renderer->scale,
                       render_info->texture_rect.height * renderer->scale,
                   },
                   (Vector2) {
                       (float) render_info->texture_rect.width  / 2,
                       (float) render_info->texture_rect.height / 2,
                   },
                   render_info->angle,
                   RAYWHITE
    );
}

void renderer_draw_text(Renderer* renderer, const char* text, int x, int y) {
    DrawText(text, x, y, renderer->font_size, BLACK);
}

void renderer_end_drawing(Renderer* renderer) {
    renderer->dt = GetFrameTime();
    EndDrawing();
}
