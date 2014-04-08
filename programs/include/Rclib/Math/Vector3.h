/*
 *  vector3.h
 *  2012年 2月 16日 木曜日 23:00:13
 */

#ifndef _RC_VECTOR3_H_
#define _RC_VECTOR3_H_

namespace rc {
namespace math {

class Vector3 {
public:
    static const Vector3 ZERO;  // ゼロ
    static const Vector3 UNIT;  // 単位

public:
    // -------------------------
    // constructor
    Vector3();
    Vector3(float _n);
    Vector3(float _x, float _y, float _z);
    Vector3(const Vector3 &src);

    // -------------------------
    // destructor
    ~Vector3();

    // -------------------------
    // 演算子オーバーロード
public:
    // -------------------------
    // =
    Vector3 &operator=(const Vector3 &rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        return *this;
    }

    // -------------------------
    // +
    Vector3 operator+(const Vector3 &rhs)
    {
        Vector3 ret;
        Vector3::add(&ret, *this, rhs);
        return ret;
    }

    // -------------------------
    // -
    Vector3 operator-(const Vector3 &rhs)
    {
        Vector3 ret;
        Vector3::sub(&ret, *this, rhs);
        return ret;
    }

    // -------------------------
    // *
    Vector3 operator*(const float &rhs)
    {
        Vector3 ret;
        Vector3::scale(&ret, *this, rhs);
        return ret;
    }

    // -------------------------
    // *=
    Vector3 operator*=(const float &rhs)
    {
        Vector3::scale(this, *this, rhs);
        return *this;
    }

    // +Vector3
    Vector3 operator+() { return *this; }
    // -Vector3
    Vector3 operator-() { return Vector3(-x, -y, -z); }

    // -------------------------
    // static function
public:
    // ベクトル同士の和
    static void add(Vector3 *dst, const Vector3 &src0, const Vector3 &src1);
    // ベクトル同士の差
    static void sub(Vector3 *dst, const Vector3 &src0, const Vector3 &src1);
    // ベクトル同士の内積
    static void dot(float *dst, const Vector3 &src0, const Vector3 &src1);
    // ベクトル同士の外積
    static void cross(Vector3 *dst, const Vector3 &src0, const Vector3 &src1);

    // ベクトルの定数倍
    static void scale(Vector3 *dst, const Vector3 &src0, const float &src1);

public:
    union {
        struct {
            float x, y, z;
        };
        float v[3];
    };
};

}  // math
}  // rc

#endif  //_RC_VECTOR3_H_
