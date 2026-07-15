#pragma once
#include "Window.hpp"


class Application {
public:
    Application();
    ~Application();

    void Run();
private:
    void ProcessEvents();
    void Update();
    void Render();


    std::uint16_t window_width;
    std::uint16_t window_height;
    
    Window window;
};
