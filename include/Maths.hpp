#pragma once

namespace Maths {

    struct Vector2f {
        float x;
        float y;
    };

    struct Vector3f {
        float x;
        float y;
        float z;
    };

    struct Vector4f {
        float x;
        float y;
        float z;
        float w;
    };

    struct Vector4i {
        int x;
        int y;
        int z;
        int w;
    };

    struct Vector4u {
        unsigned int x;
        unsigned int y;
        unsigned int z;
        unsigned int w;
    };

    template <size_t width, size_t height>
    struct Matrix {
    public:
        Matrix() = default;

        float& At(size_t x, size_t y) { return m_Values[y * width + x]; }
        auto operator*(const Matrix<height, width>& other) const { (void)other; }

        Matrix Invert() const { }

    private:
        float m_Values[width * height];
    };

    //[ s . . . ] [ x ]   [ sx ]
    //| . s . . | | y | = | sy |
    //| . . s . | | z |   | sz |
    //[ . . . 1 ] [ 1 ]   [ 1  ]

    //[ 1 . . dx ] [ x ]   [ x + dx ]
    //| . 1 . dy | | y | = | y + dy |
    //| . . 1 dz | | z |   | z + dz |
    //[ . . . 1  ] [ 1 ]   [   1    ]

    // 3 rotation matrices

    //[ x(3D) ]   [ x / w ]
    //| y(3D) ] = | y / w |
    //[ z(3D) ]   [ z / w ]

    //[ 1 . .  . ] [ x ]   [  x   ]
    //| . 1 .  . | | y | = |  y   |
    //| . . 1  . | | z |   |  z   |
    //[ . . 2  . ] [ 1 ]   [ 2*z  ]

}
