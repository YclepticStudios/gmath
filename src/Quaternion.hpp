/**
 *  ============================================================================
 *  MIT License
 *
 *  Copyright (c) 2016 Eric Phillips
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 *  ============================================================================
 *
 *
 *  This file implements a series of math functions for manipulating a
 *  quaternion.
 *
 *  Created by Eric Phillips on October 21, 2016.
 */

#pragma once

#include <math.h>


/**
 * Attempt to include a header file if the file exists.
 * If the file does not exist, create a dummy data structure for that type.
 * If it cannot be determined if it exists, just attempt to include it.
 */
#ifdef __has_include
#   if __has_include("Vector3.hpp")
#       include "Vector3.hpp"
#   else
        struct Vector3
        {
            union
            {
                struct
                {
                    double X;
                    double Y;
                    double Z;
                };
                double data[3];
            };

            inline Vector3() : X(0), Y(0), Z(0) {}
            inline Vector3(double data[]) : X(data[0]), Y(data[1]), Z(data[2])
                {}
            inline Vector3(double value) : X(value), Y(value), Z(value) {}
            inline Vector3(double x, double y) : X(x), Y(y), Z(0) {}
            inline Vector3(double x, double y, double z) : X(x), Y(y), Z(z) {}

            static inline Vector3 Cross(Vector3 lhs, Vector3 rhs)
            {
                double x = lhs.Y * rhs.Z - lhs.Z * rhs.Y;
                double y = lhs.Z * rhs.X - lhs.X * rhs.Z;
                double z = lhs.X * rhs.Y - lhs.Y * rhs.X;
                return Vector3(x, y, z);
            }

            static inline double Dot(Vector3 lhs, Vector3 rhs)
            {
                return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
            }

            static inline Vector3 Normalized(Vector3 v)
            {
                double mag = sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
                return Vector3(v.X / mag, v.Y / mag, v.Z / mag);
            }

            static inline Vector3 Orthogonal(Vector3 v)
            {
                return v.Z < v.X ?
                    Vector3(v.Y, -v.X, 0) : Vector3(0, -v.Z, v.Y);
            }

            static inline double SqrMagnitude(Vector3 v)
            {
                return v.X * v.X + v.Y * v.Y + v.Z * v.Z;
            }
        };


        inline Vector3 operator+(Vector3 lhs, const Vector3 rhs)
        {
            return Vector3(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z);
        }

        inline Vector3 operator*(Vector3 lhs, const double rhs)
        {
            return Vector3(lhs.X * rhs, lhs.Y * rhs, lhs.Z * rhs);
        }
#   endif
#else
#   include "Vector3.hpp"
#endif


struct Quaternion
{
    union
    {
        struct
        {
            double X;
            double Y;
            double Z;
            double W;
        };
        double data[4];
    };


    /**
     * Constructors.
     */
    inline Quaternion();
    inline Quaternion(double data[]);
    inline Quaternion(Vector3 vector, double scalar);
    inline Quaternion(double x, double y, double z, double w);


    /**
     * Constants for common quaternions.
     */
    static inline Quaternion Identity();

    /**
     * Returns the angle between two quaternions.
     * @param a: The first quaternion.
     * @param b: The second quaternion.
     * @return: A scalar value.
     */
    static inline double Angle(Quaternion a, Quaternion b);

    /**
     * Returns the conjugate of a quaternion.
     * @param rotation: The quaternion in question.
     * @return: A new quaternion.
     */
    static inline Quaternion Conjugate(Quaternion rotation);

    /**
     * Returns the dot product of two quaternions.
     * @param lhs: The left side of the multiplication.
     * @param rhs: The right side of the multiplication.
     * @return: A scalar value.
     */
    static inline double Dot(Quaternion lhs, Quaternion rhs);

    /**
     * Creates a new quaternion from the angle-axis representation of
     * a rotation.
     * @param angle: The rotation angle in radians.
     * @param axis: The vector about which the rotation occurs.
     * @return: A new quaternion.
     */
    static inline Quaternion FromAngleAxis(double angle, Vector3 axis);

    /**
     * Create a new quaternion from the euler angle representation of
     * a rotation. The z, x and y values represent rotations about those
     * axis in that respective order.
     * @param x: The rotation about the x-axis in radians.
     * @param y: The rotation about the y-axis in radians.
     * @param z: The rotation about the z-axis in radians.
     * @return: A new quaternion.
     */
    static inline Quaternion FromEuler(Vector3 rotation);
    static inline Quaternion FromEuler(double x, double y, double z);

    /**
     * Create a quaternion rotation which rotates "fromVector" to "toVector".
     * @param fromVector: The vector from which to start the rotation.
     * @param toVector: The vector at which to end the rotation.
     * @return: A new quaternion.
     */
    static inline Quaternion FromToRotation(Vector3 fromVector, Vector3 toVector);

    /**
     * Returns the inverse of a rotation.
     * @param rotation: The quaternion in question.
     * @return: A new quaternion.
     */
    static inline Quaternion Inverse(Quaternion rotation);

    /**
     * Returns the norm of a quaternion.
     * @param rotation: The quaternion in question.
     * @return: A scalar value.
     */
    static inline double Norm(Quaternion rotation);

    /**
     * Returns a quaternion with identical rotation and a norm of one.
     * @param rotation: The quaternion in question.
     * @return: A new quaternion.
     */
    static inline Quaternion Normalized(Quaternion rotation);

    /**
     * Returns the Euler angle representation of a rotation. The resulting
     * vector contains the rotations about the z, x and y axis, in that order.
     * @param rotation: The quaternion to convert.
     * @return: A new vector.
     */
    static inline Vector3 ToEuler(Quaternion rotation);

    /**
     * Operator overloading.
     */
    inline struct Quaternion& operator+=(const double rhs);
    inline struct Quaternion& operator-=(const double rhs);
    inline struct Quaternion& operator*=(const double rhs);
    inline struct Quaternion& operator/=(const double rhs);
    inline struct Quaternion& operator+=(const Quaternion rhs);
    inline struct Quaternion& operator-=(const Quaternion rhs);
    inline struct Quaternion& operator*=(const Quaternion rhs);
};

inline Quaternion operator-(Quaternion rhs);
inline Quaternion operator+(Quaternion lhs, const double rhs);
inline Quaternion operator-(Quaternion lhs, const double rhs);
inline Quaternion operator*(Quaternion lhs, const double rhs);
inline Quaternion operator/(Quaternion lhs, const double rhs);
inline Quaternion operator+(const double lhs, Quaternion rhs);
inline Quaternion operator-(const double lhs, Quaternion rhs);
inline Quaternion operator*(const double lhs, Quaternion rhs);
inline Quaternion operator/(const double lhs, Quaternion rhs);
inline Quaternion operator+(Quaternion lhs, const Quaternion rhs);
inline Quaternion operator-(Quaternion lhs, const Quaternion rhs);
inline Quaternion operator*(Quaternion lhs, const Quaternion rhs);
inline Vector3 operator*(Quaternion lhs, const Vector3 rhs);
inline bool operator==(const Quaternion lhs, const Quaternion rhs);
inline bool operator!=(const Quaternion lhs, const Quaternion rhs);



/*******************************************************************************
 * Implementation
 */

Quaternion::Quaternion() : X(0), Y(0), Z(0), W(1) {}
Quaternion::Quaternion(double data[]) : X(data[0]), Y(data[1]), Z(data[2]),
    W(data[3]) {}
Quaternion::Quaternion(Vector3 vector, double scalar) : X(vector.X),
    Y(vector.Y), Z(vector.Z), W(scalar) {}
Quaternion::Quaternion(double x, double y, double z, double w) : X(x), Y(y),
    Z(z), W(w) {}


Quaternion Quaternion::Identity() { return Quaternion(0, 0, 0, 1); }


double Quaternion::Angle(Quaternion a, Quaternion b)
{
    double v = (b * Inverse(a)).W;
    v = fmax(v, -1.0);
    v = fmin(v, 1.0);
    double angle = acos(v) * 2.0;
    if (angle > M_PI)
        angle = 2.0 * M_PI - angle;
    return angle;
}

Quaternion Quaternion::Conjugate(Quaternion rotation)
{
    return Quaternion(-rotation.X, -rotation.Y, -rotation.Z, rotation.W);
}

double Quaternion::Dot(Quaternion lhs, Quaternion rhs)
{
    return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z + lhs.W * rhs.W;
}

Quaternion Quaternion::FromAngleAxis(double angle, Vector3 axis)
{
    Quaternion q;
    double m = sqrt(axis.X * axis.X + axis.Y * axis.Y + axis.Z * axis.Z);
    double s = sin(angle / 2) / m;
    q.X = axis.X * s;
    q.Y = axis.Y * s;
    q.Z = axis.Z * s;
    q.W = cos(angle / 2);
    return q;
}

Quaternion Quaternion::FromEuler(Vector3 rotation)
{
    return FromEuler(rotation.X, rotation.Y, rotation.Z);
}

Quaternion Quaternion::FromEuler(double x, double y, double z)
{
    double cx = cos(x * 0.5);
	double cy = cos(y * 0.5);
	double cz = cos(z * 0.5);
	double sx = sin(x * 0.5);
	double sy = sin(y * 0.5);
	double sz = sin(z * 0.5);
    Quaternion q;
	q.X = cx * sy * sz + cy * cz * sx;
	q.Y = cx * cz * sy - cy * sx * sz;
	q.Z = cx * cy * sz - cz * sx * sy;
	q.W = sx * sy * sz + cx * cy * cz;
    return q;
}

Quaternion Quaternion::FromToRotation(Vector3 fromVector, Vector3 toVector)
{
    double dot = Vector3::Dot(fromVector, toVector);
    double k = sqrt(Vector3::SqrMagnitude(fromVector) *
        Vector3::SqrMagnitude(toVector));
    if (fabs(dot / k + 1) < 0.00001)
    {
        Vector3 ortho = Vector3::Orthogonal(fromVector);
        return Quaternion(Vector3::Normalized(ortho), 0);
    }
    Vector3 cross = Vector3::Cross(fromVector, toVector);
    return Normalized(Quaternion(cross, dot + k));
}

Quaternion Quaternion::Inverse(Quaternion rotation)
{
    double n = Norm(rotation);
    return Conjugate(rotation) / (n * n);
}

double Quaternion::Norm(Quaternion rotation)
{
    return sqrt(rotation.X * rotation.X +
        rotation.Y * rotation.Y +
        rotation.Z * rotation.Z +
        rotation.W * rotation.W);
}

Quaternion Quaternion::Normalized(Quaternion rotation)
{
    return rotation / Norm(rotation);
}

Vector3 Quaternion::ToEuler(Quaternion rotation)
{
    float sqw = rotation.W * rotation.W;
    float sqx = rotation.X * rotation.X;
    float sqy = rotation.Y * rotation.Y;
    float sqz = rotation.Z * rotation.Z;
    // If normalized is one, otherwise is correction factor
    float unit = sqx + sqy + sqz + sqw;
    float test = rotation.X * rotation.W - rotation.Y * rotation.Z;
    Vector3 v;
    // Singularity at north pole
    if (test > 0.4995f * unit)
    {
        v.Y = 2 * atan2(rotation.Y, rotation.X);
        v.X = M_PI_2;
        v.Z = 0;
        return v;
    }
    // Singularity at south pole
    if (test < -0.4995f * unit)
    {
        v.Y = -2 * atan2(rotation.Y, rotation.X);
        v.X = -M_PI_2;
        v.Z = 0;
        return v;
    }
    // Yaw
    v.Y = atan2(2 * rotation.W * rotation.Y + 2 * rotation.Z * rotation.X,
        1 - 2 * (rotation.X * rotation.X + rotation.Y * rotation.Y));
    // Pitch
    v.X = asin(2 * (rotation.W * rotation.X - rotation.Y * rotation.Z));
    // Roll
    v.Z = atan2(2 * rotation.W * rotation.Z + 2 * rotation.X * rotation.Y,
        1 - 2 * (rotation.Z * rotation.Z + rotation.X * rotation.X));
    return v;
}

struct Quaternion& Quaternion::operator+=(const double rhs)
{
    X += rhs;
    Y += rhs;
    Z += rhs;
    W += rhs;
    return *this;
}

struct Quaternion& Quaternion::operator-=(const double rhs)
{
    X -= rhs;
    Y -= rhs;
    Z -= rhs;
    W -= rhs;
    return *this;
}

struct Quaternion& Quaternion::operator*=(const double rhs)
{
    X *= rhs;
    Y *= rhs;
    Z *= rhs;
    W *= rhs;
    return *this;
}

struct Quaternion& Quaternion::operator/=(const double rhs)
{
    X /= rhs;
    Y /= rhs;
    Z /= rhs;
    W /= rhs;
    return *this;
}

struct Quaternion& Quaternion::operator+=(const Quaternion rhs)
{
    X += rhs.X;
    Y += rhs.Y;
    Z += rhs.Z;
    W += rhs.W;
    return *this;
}

struct Quaternion& Quaternion::operator-=(const Quaternion rhs)
{
    X -= rhs.X;
    Y -= rhs.Y;
    Z -= rhs.Z;
    W -= rhs.W;
    return *this;
}

struct Quaternion& Quaternion::operator*=(const Quaternion rhs)
{
    Quaternion q;
    q.W = W * rhs.W - X * rhs.X - Y * rhs.Y - Z * rhs.Z;
    q.X = X * rhs.W + W * rhs.X + Y * rhs.Z - Z * rhs.Y;
    q.Y = W * rhs.Y - X * rhs.Z + Y * rhs.W + Z * rhs.X;
    q.Z = W * rhs.Z + X * rhs.Y - Y * rhs.X + Z * rhs.W;
    *this = q;
    return *this;
}

Quaternion operator-(Quaternion rhs) { return rhs * -1; }
Quaternion operator+(Quaternion lhs, const double rhs) { return lhs += rhs; }
Quaternion operator-(Quaternion lhs, const double rhs) { return lhs -= rhs; }
Quaternion operator*(Quaternion lhs, const double rhs) { return lhs *= rhs; }
Quaternion operator/(Quaternion lhs, const double rhs) { return lhs /= rhs; }
Quaternion operator+(const double lhs, Quaternion rhs) { return rhs += lhs; }
Quaternion operator-(const double lhs, Quaternion rhs) { return rhs -= lhs; }
Quaternion operator*(const double lhs, Quaternion rhs) { return rhs *= lhs; }
Quaternion operator/(const double lhs, Quaternion rhs) { return rhs /= lhs; }
Quaternion operator+(Quaternion lhs, const Quaternion rhs)
{
    return lhs += rhs;
}
Quaternion operator-(Quaternion lhs, const Quaternion rhs)
{
    return lhs -= rhs;
}
Quaternion operator*(Quaternion lhs, const Quaternion rhs)
{
    return lhs *= rhs;
}

Vector3 operator*(Quaternion lhs, const Vector3 rhs)
{
    Vector3 u = Vector3(lhs.X, lhs.Y, lhs.Z);
    float s = lhs.W;
    return u * (Vector3::Dot(u, rhs) * 2)
        + rhs * (s * s - Vector3::Dot(u, u))
        + Vector3::Cross(u, rhs) * (2.0 * s);
}

bool operator==(const Quaternion lhs, const Quaternion rhs)
{
    return lhs.X == rhs.X &&
        lhs.Y == rhs.Y &&
        lhs.Z == rhs.Z &&
        lhs.W == rhs.W;
}

bool operator!=(const Quaternion lhs, const Quaternion rhs)
{
    return !(lhs == rhs);
}
