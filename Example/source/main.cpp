#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>
#include <atomic>

static std::atomic_flag is_running{};

static SDL_Window *window;
static SDL_Renderer *renderer;

auto main() -> int {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != true) {
        //pdlog::info("Unable to initialise SDL! SDL error: {}", SDL_GetError());
        return -1;
    }

    if (window = SDL_CreateWindow("Software renderer app", 800,
    600, SDL_WINDOW_BORDERLESS | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS |
SDL_WINDOW_HIGH_PIXEL_DENSITY);
        window == nullptr) {
        //spdlog::info("Window could not be created! SDL error: {}", SDL_GetError());
        return -1;
    }

    if (renderer = SDL_CreateRenderer(window, nullptr); renderer == nullptr) {
        return -1;
    }

    return 0;
}
