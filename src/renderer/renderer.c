#include "renderer.h"
#include <raylib.h>
#include <math.h>

void renderer_init(Renderer* renderer) {
    InitWindow(renderer->window_width, renderer->window_height, "RayRacer");
    SetTargetFPS(renderer->fps);

    renderer->camera = (Camera2D){0};
    renderer->camera.target = (Vector2) {0, 0};
    renderer->camera.offset = (Vector2) {(float) renderer->window_width / 2,(float) renderer->window_height / 2};
    renderer->camera.rotation = 0.0f;
    renderer->camera.zoom = 1.0f;
}

void renderer_start_drawing_scene(Renderer* renderer) {
    BeginDrawing();
    BeginMode2D(renderer->camera);
    
    renderer->window_width  = GetScreenWidth();
    renderer->window_height = GetScreenHeight();
    renderer->camera.offset = (Vector2) {(float) renderer->window_width / 2,(float) renderer->window_height / 2};

    ClearBackground(RAYWHITE);
}

void renderer_draw(Renderer* renderer, RenderInfo* render_info) {
    DrawTexturePro(render_info->texture,
                   render_info->texture_rect,
                   (Rectangle) {
                       render_info->x * renderer->scale,
                       render_info->y * renderer->scale,
                       render_info->texture_rect.width  * renderer->scale,
                       render_info->texture_rect.height * renderer->scale,
                   },
                   (Vector2) {
                       (float) render_info->texture_rect.width  / 2 * renderer->scale,
                       (float) render_info->texture_rect.height / 2 * renderer->scale,
                   },
                   render_info->angle,
                   RAYWHITE
    );
}

void renderer_draw_text(Renderer* renderer, const char* text, int x, int y) {
    DrawText(text, x, y, renderer->font_size, BLACK);
}

void renderer_end_drawing_scene(Renderer* renderer) {
    renderer->dt = GetFrameTime();
    EndMode2D();
    EndDrawing();
}
