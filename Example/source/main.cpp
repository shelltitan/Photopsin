#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>
#include <atomic>

static std::atomic_flag is_running{};

static SDL_Window *window;
static SDL_Renderer *renderer;
static std::uint32_t *colour_buffer;
static std::uint16_t window_width = 800;
static std::uint16_t window_height = 600;


auto main() -> int {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != true) {
        //pdlog::info("Unable to initialise SDL! SDL error: {}", SDL_GetError());
        return -1;
    }

    if (window = SDL_CreateWindow("Software renderer app", static_cast<int>(window_width), 
    static_cast<int>(window_height), SDL_WINDOW_BORDERLESS | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS 
    | SDL_WINDOW_HIGH_PIXEL_DENSITY); window == nullptr) {
        //spdlog::info("Window could not be created! SDL error: {}", SDL_GetError());
        return -1;
    }

    if (renderer = SDL_CreateRenderer(window, nullptr); renderer == nullptr) {
        return -1;
    }
    
    colour_buffer = new std::uint32_t[static_cast<size_t>(window_width) * static_cast<size_t>(window_height)];

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
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        SDL_RenderPresent(renderer);
    }

    delete[] colour_buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
