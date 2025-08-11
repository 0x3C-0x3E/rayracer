#include "app.h"
#include <raylib.h>

void app_init_raylib(App* app) {
    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
}

void app_init(App* app) {
    app_init_raylib(app);

    app->renderer = (Renderer) {
        .fps = 165,
        .scale = 3,
        .font_size = 20,

        .camera_x = 0,
        .camera_y = 0,

        .window_width = 800,
        .window_height = 600,
    };

    renderer_init(&app->renderer);
    
    game_init(&app->game, &app->renderer);
}

void app_run(App* app) {
    
    while (!WindowShouldClose()) {
        renderer_start_drawing_scene(&app->renderer);

        game_update(&app->game);
        game_draw(&app->game);

        renderer_end_drawing_scene(&app->renderer);
    }
}
