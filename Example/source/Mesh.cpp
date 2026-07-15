#include "Mesh.hpp"

Mesh CreateCubeMesh() {
    Mesh cube_mesh;

    cube_mesh.vertices = {
        { -1.0f, -1.0f, -1.0f }, // 0
        {  1.0f, -1.0f, -1.0f }, // 3
        {  1.0f,  1.0f, -1.0f }, // 2
        { -1.0f,  1.0f, -1.0f }, // 1
        { -1.0f, -1.0f,  1.0f }, // 4
        {  1.0f, -1.0f,  1.0f }, // 7
        {  1.0f,  1.0f,  1.0f }, // 6
        { -1.0f,  1.0f,  1.0f }  // 5
    };

    cube_mesh.indices = {
        0, 1, 2, 
        2, 3, 0,
        3, 2, 6,
        6, 7, 3,
        7, 4, 3,
        4, 0, 3,
        4, 1, 0,
        1, 4, 5,
        1, 5, 6,
        6, 2, 1,
        7, 6, 5,
        5, 4, 7
    };

    return cube_mesh;
}