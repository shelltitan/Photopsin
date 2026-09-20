#pragma once
#include <SDL3/SDL.h>
#include <cstdint>
#include <span>

#if !defined(__has_cpp_attribute)
#define LIFETIMEBOUND
#elif __has_cpp_attribute(clang::lifetimebound)
#define LIFETIMEBOUND [[clang::lifetimebound]]
#elif __has_cpp_attribute(msvc::lifetimebound)
#define LIFETIMEBOUND [[msvc::lifetimebound]]
#else
#define LIFETIMEBOUND
#endif

class Render {
  public:
    Render(const std::uint16_t window_width, const std::uint16_t window_height,
           std::uint32_t *colour_buffer LIFETIMEBOUND, SDL_Texture *colour_buffer_texture LIFETIMEBOUND)
        : m_window_width(window_width), m_window_height(window_height), m_colour_buffer(colour_buffer),
          m_colour_buffer_texture(colour_buffer_texture) {}

    auto ClearColourBuffer(const std::uint32_t colour = 0x00000000, std::uint16_t window_width = 0,
                           const std::uint16_t window_height = 0) -> void;

    auto RenderColourBuffer(SDL_Renderer *renderer, SDL_Texture *texture, const std::uint32_t *buffer,
                            const std::uint16_t width) -> void;

    auto DrawGrid(std::span<std::uint32_t> buffer, const std::uint16_t width, const std::uint16_t height,
                  std::uint8_t grid_pitch, const std::uint32_t colour = 0xFFFFFFFF) -> void;

    auto DrawPixel(std::span<std::uint32_t> buffer, const std::uint16_t width, const std::uint16_t height,
                   const std::uint16_t x, const std::uint16_t y, const std::uint32_t colour = 0xFFFFFFFF) -> void;

    auto DrawRectangle(std::span<std::uint32_t> buffer, const std::uint16_t x, const std::uint16_t y,
                       const std::uint16_t w, const std::uint16_t h, const std::uint32_t colour = 0xFFFFFFFF) -> void;

  private:
    std::uint16_t m_window_width;
    std::uint16_t m_window_height;
    std::uint32_t *m_colour_buffer;
    SDL_Texture *m_colour_buffer_texture;
};
