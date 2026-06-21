#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>

SDL_Window *m_window{nullptr};

int main() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != true) {
        spdlog::error("Unable to initialise SDL! SDL error: {}", SDL_GetError());
        return -1;
    }



    return 0;
}
