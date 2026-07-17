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

    struct alignas(16) Mat4x4f
    {
    public:
        Mat4x4f() = default;
        Mat4x4f(const float* values) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    m[i][j] = values[i * 4 + j];
                }
            }
        }

        float& operator()(int row, int col) {
            return m[row][col];
        }

        const float& operator()(int row, int col) const {
            return m[row][col];
        }

        Mat4x4f operator*(const Mat4x4f& other) const;
        Vector4f operator*(const Vector4f& other) const;
        Vector3f operator*(const Vector3f& other) const;
    private:
        float m[4][4];  // m[row][column]
    };

    static_assert(sizeof(Mat4x4f) == 64);
    static_assert(alignof(Mat4x4f) >= 16);

    struct alignas(16) Mat3x4f
    {
    public:
        Mat3x4f() = default;
        Mat3x4f(const float* values) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 4; ++j) {
                    m[i][j] = values[i * 4 + j];
                }
            }
        }

        float& operator()(int row, int col) {
            return m[row][col];
        }

        const float& operator()(int row, int col) const {
            return m[row][col];
        }

        Vector4f operator*(const Vector4f& other) const;
        Vector3f operator*(const Vector3f& other) const;
    private:
        float m[3][4];  // m[row][column]
    };

    static_assert(sizeof(Mat3x4f) == 48);
    static_assert(alignof(Mat3x4f) >= 16);

    // there is probably 2 ways that this has to be done
    // one optimal for single point transform,
    // one optimal for multiple point transform i.e. batch transform

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
