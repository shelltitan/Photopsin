#include "Maths.hpp"

namespace Maths {

Mat4x4f Mat4x4f::operator*(const Mat4x4f &other) const {
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

Vector4f Mat4x4f::operator*(const Vector4f &other) const {
    Vector4f result;
    result.x = matrix[0][0] * other.x + matrix[0][1] * other.y + matrix[0][2] * other.z + matrix[0][3] * other.w;
    result.y = matrix[1][0] * other.x + matrix[1][1] * other.y + matrix[1][2] * other.z + matrix[1][3] * other.w;
    result.z = matrix[2][0] * other.x + matrix[2][1] * other.y + matrix[2][2] * other.z + matrix[2][3] * other.w;
    result.w = matrix[3][0] * other.x + matrix[3][1] * other.y + matrix[3][2] * other.z + matrix[3][3] * other.w;
    return result;
}

Vector3f Mat4x4f::operator*(const Vector3f &other) const {
    Vector3f result;
    result.x = matrix[0][0] * other.x + matrix[0][1] * other.y + matrix[0][2] * other.z + matrix[0][3];
    result.y = matrix[1][0] * other.x + matrix[1][1] * other.y + matrix[1][2] * other.z + matrix[1][3];
    result.z = matrix[2][0] * other.x + matrix[2][1] * other.y + matrix[2][2] * other.z + matrix[2][3];
    return result;
}

} // namespace Maths
