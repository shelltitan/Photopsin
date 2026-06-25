#include <atomic>
#include <algorithm>
#include "Window.hpp"

static std::atomic_flag is_running{};

static std::uint32_t *colour_buffer;
static SDL_Texture * colour_buffer_texture;

static void ClearColourBuffer(std::uint32_t colour = 0x00000000, std::uint16_t window_width = 0, std::uint16_t window_height = 0) {
    std::fill_n(colour_buffer, static_cast<size_t>(window_width) * static_cast<size_t>(window_height), colour);
}
static void RenderColourBuffer(SDL_Renderer *renderer, SDL_Texture *texture, std::uint32_t *buffer, std::uint16_t width) {
    SDL_UpdateTexture(texture, nullptr, buffer, static_cast<int>(width) * static_cast<int>(sizeof(std::uint32_t)));
    SDL_RenderTexture(renderer, texture, nullptr, nullptr);
}


auto main() -> int {
    Window window;
    
    std::uint16_t window_width;
    std::uint16_t window_height;

    {
        int w, h;
        SDL_GetWindowSize(window.GetWindow(), &w, &h);
        window_width = static_cast<std::uint16_t>(w);
        window_height = static_cast<std::uint16_t>(h);
    }
    // TODO check if this throws
    colour_buffer = new std::uint32_t[static_cast<size_t>(window_width) * static_cast<size_t>(window_height)];
    
    // Create a texture for the colour buffer
    colour_buffer_texture = SDL_CreateTexture(window.GetRenderer(), SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, window_width, window_height);

    is_running.test_and_set();

    while (is_running.test()) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                is_running.clear();
            }
            else if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_ESCAPE) {
                    is_running.clear();
                }
            }
        }

        //Update()
        //Render()
        SDL_Renderer *renderer = window.GetRenderer();
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        RenderColourBuffer(renderer, colour_buffer_texture, colour_buffer, window_width);
        // clear our colour buffer to black
        ClearColourBuffer(0xFF000000, window_width, window_height);
        
        SDL_RenderPresent(renderer);
    }

    delete[] colour_buffer;
    SDL_DestroyTexture(colour_buffer_texture);

    return 0;
}
