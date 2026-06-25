#pragma once
#include <SDL3/SDL.h>
#include <stdint.h>
#include <string_view>

class Window {
public:
    Window(std::string_view title = "Software renderer app");

    ~Window();

    SDL_Renderer *GetRenderer() const { return renderer; }
    SDL_Window *GetWindow() const { return window; }
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};
