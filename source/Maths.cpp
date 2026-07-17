#include "Maths.hpp"

namespace Maths {

    Mat4x4f Mat4x4f::operator*(const Mat4x4f& other) const {
        Mat4x4f result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result(i, j) = 0.0f;
                for (int k = 0; k < 4; ++k) {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }
        return result;
    }

    Vector4f Mat4x4f::operator*(const Vector4f& other) const {
        Vector4f result;
        result.x = m[0][0] * other.x + m[0][1] * other.y + m[0][2] * other.z + m[0][3] * other.w;
        result.y = m[1][0] * other.x + m[1][1] * other.y + m[1][2] * other.z + m[1][3] * other.w;
        result.z = m[2][0] * other.x + m[2][1] * other.y + m[2][2] * other.z + m[2][3] * other.w;
        result.w = m[3][0] * other.x + m[3][1] * other.y + m[3][2] * other.z + m[3][3] * other.w;
        return result;
    }

    Vector3f Mat4x4f::operator*(const Vector3f& other) const {
        Vector3f result;
        result.x = m[0][0] * other.x + m[0][1] * other.y + m[0][2] * other.z + m[0][3];
        result.y = m[1][0] * other.x + m[1][1] * other.y + m[1][2] * other.z + m[1][3];
        result.z = m[2][0] * other.x + m[2][1] * other.y + m[2][2] * other.z + m[2][3];
        return result;
    }

}