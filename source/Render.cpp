#include "Render.hpp"
#include <algorithm>

std::uint32_t *colour_buffer{nullptr};
SDL_Texture *colour_buffer_texture{nullptr};

auto ClearColourBuffer(const std::uint32_t colour, std::uint16_t window_width,
                              const std::uint16_t window_height) -> void {
    std::fill_n(colour_buffer, static_cast<size_t>(window_width) * static_cast<size_t>(window_height), colour);
}

auto RenderColourBuffer(SDL_Renderer *renderer, SDL_Texture *texture, const std::uint32_t *buffer,
                               const std::uint16_t width) -> void {
    SDL_UpdateTexture(texture, nullptr, buffer, static_cast<int>(width) * static_cast<int>(sizeof(std::uint32_t)));
    SDL_RenderTexture(renderer, texture, nullptr, nullptr);
}

auto DrawGrid(std::span<std::uint32_t> buffer, const std::uint16_t width, const std::uint16_t height,
                     std::uint8_t grid_pitch, const std::uint32_t colour) -> void {
    for (std::uint16_t y = 0; y < height; ++y) {
        for (std::uint16_t x = 0; x < width; ++x) {
            if (x % grid_pitch == 0 || y % grid_pitch == 0) {
                buffer[y * width + x] = colour;
            }
        }
    }
}

auto DrawPixel(std::span<std::uint32_t> buffer, const std::uint16_t width, const std::uint16_t height,
               const std::uint16_t x, const std::uint16_t y, const std::uint32_t colour) -> void {
    if (x >= width || y >= height) {
        return;
    }
    buffer[y * width + x] = colour;
}

auto DrawRectangle(std::span<std::uint32_t> buffer, const std::uint16_t width, const std::uint16_t height,
                   const std::uint16_t x, const std::uint16_t y, const std::uint16_t w, const std::uint16_t h,
                   const std::uint32_t colour) -> void {
    if (x >= width || y >= height || x + w > width || y + h > height) {
        return;
    }
    for (std::uint16_t y_pos = y; y_pos < y + h; ++y_pos) {
        for (std::uint16_t x_pos = x; x_pos < x + w; ++x_pos) {
            buffer[y_pos * width + x_pos] = colour;
        }
    }
}
