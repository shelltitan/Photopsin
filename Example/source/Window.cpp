#include "Window.hpp"
#include <spdlog/spdlog.h>
#include <format>

Window::Window(std::string_view title) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != true) {
        throw std::runtime_error(std::format("Unable to initialise SDL! SDL error: {}", SDL_GetError()));
    }

    SDL_DisplayID display_id = SDL_GetPrimaryDisplay();
    const SDL_DisplayMode* display_mode = SDL_GetCurrentDisplayMode(display_id);

    if (display_mode == nullptr) {
        SDL_Quit();
        throw std::runtime_error(std::format("Unable to get current display mode! SDL error: {}", SDL_GetError()));
    }

    if (window = SDL_CreateWindow(title.data(), display_mode->w, 
    display_mode->h, SDL_WINDOW_BORDERLESS | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS 
    | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_FULLSCREEN); window == nullptr) {
        SDL_Quit();
        throw std::runtime_error(std::format("Window could not be created! SDL error: {}", SDL_GetError()));
    }

    if (renderer = SDL_CreateRenderer(window, nullptr); renderer == nullptr) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error(std::format("Renderer could not be created! SDL error: {}", SDL_GetError()));
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
