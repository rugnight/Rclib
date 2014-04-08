/*
 * matrix4.h
 * 2012年 2月18日 土曜日 16時51分24秒 JST
 */

#ifndef _RC_MATRIX4_H_
#define _RC_MATRIX4_H_

#include "Rclib/Core/core.h"
#include "vector4.h"

namespace rc {
namespace math {

/* ================================================== */
class Matrix4
/* ================================================== */
{
public:
    static const Matrix4 ZERO;  // ゼロ行列
    static const Matrix4 UNIT;  // 単位行列

public:
    Matrix4();
    Matrix4(float _n);
    Matrix4(float _n00, float _n01, float _n02, float _n03, float _n10,
            float _n11, float _n12, float _n13, float _n20, float _n21,
            float _n22, float _n23, float _n30, float _n31, float _n32,
            float _n33);
    ~Matrix4();

    // -------------------------
    // 演算子オーバーロード
public:
    // -------------------------
    // =
    Matrix4 &operator=(const Matrix4 &rhs)
    {
        Matrix4::copy(this, rhs);
        return *this;
    }

    // -------------------------
    // +
    Matrix4 operator+(const Matrix4 &rhs)
    {
        Matrix4 ret;
        Matrix4::add(&ret, *this, rhs);
        return ret;
    }

    // -------------------------
    // -
    Matrix4 operator-(const Matrix4 &rhs)
    {
        Matrix4 ret;
        Matrix4::sub(&ret, *this, rhs);
        return ret;
    }

    // -------------------------
    // *
    Matrix4 operator*(const Matrix4 &rhs)
    {
        Matrix4 ret;
        Matrix4::mul(&ret, *this, rhs);
        return ret;
    }

public:
    static void add(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1);
    static void sub(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1);
    static void mul(Matrix4 *dst, const Matrix4 &src0, const Matrix4 &src1);

    static void inverse(Matrix4 *dst, const Matrix4 &src);

    static void copy(Matrix4 *dst, const Matrix4 &src);

public:
    union {
        struct {
            float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23,
                m30, m31, m32, m33;
        };
        float v[16];
        float vv[4][4];
    };
};

}  // namespace math
}  // namespace rc

#endif  //_RC_MATRIX4_H_
