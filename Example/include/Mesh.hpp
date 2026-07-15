#pragma once
#include "Maths.hpp"
#include <vector>

struct Mesh {
    std::vector<Maths::Vector3f> vertices;
    std::vector<std::uint16_t> indices;
};

Mesh CreateCubeMesh();