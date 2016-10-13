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
 *  3D vector.
 *
 *  Created by Eric Phillips on October 8, 2016.
 */

#pragma once

#include <math.h>


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


    /**
     * Static constants.
     */
    static const Vector3 Zero;
    static const Vector3 One;
    static const Vector3 Right;
    static const Vector3 Left;
    static const Vector3 Up;
    static const Vector3 Down;
    static const Vector3 Forward;
    static const Vector3 Backward;


    /**
     * Constructors.
     */
    Vector3();
    Vector3(double data[]);
    Vector3(double value);
    Vector3(double x, double y);
    Vector3(double x, double y, double z);


    /**
     * Returns the angle between two vectors in radians.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A scalar value.
     */
    static double Angle(Vector3 a, Vector3 b);

    /**
     * Returns a vector with its magnitude clamped to maxLength.
     * @param vector: The target vector.
     * @param maxLength: The maximum length of the return vector.
     * @return: A new vector.
     */
    static Vector3 ClampMagnitude(Vector3 vector, double maxLength);

    /**
     * Returns the component of a in the direction of b (scalar projection).
     * @param a: The target vector.
     * @param b: The vector being compared against.
     * @return: A scalar value.
     */
    static double Component(Vector3 a, Vector3 b);

    /**
     * Returns the cross product of two vectors.
     * @param lhs: The left side of the multiplication.
     * @param rhs: The right side of the multiplication.
     * @return: A new vector.
     */
    static Vector3 Cross(Vector3 lhs, Vector3 rhs);

    /**
     * Returns the distance between a and b.
     * @param a: The first point.
     * @param b: The second point.
     * @return: A scalar value.
     */
    static double Distance(Vector3 a, Vector3 b);

    /**
     * Returns the dot product of two vectors.
     * @param lhs: The left side of the multiplication.
     * @param rhs: The right side of the multiplication.
     * @return: A scalar value.
     */
    static double Dot(Vector3 lhs, Vector3 rhs);

    /**
     * Returns a vector linearly interpolated between a and b, moving along
     * a straight line. The vector is clamped to never go beyond the end points.
     * @param a: The starting point.
     * @param b: The ending point.
     * @param t: The interpolation value [0-1].
     * @return: A new vector.
     */
    static Vector3 Lerp(Vector3 a, Vector3 b, double t);

    /**
     * Returns a vector linearly interpolated between a and b, moving along
     * a straight line.
     * @param a: The starting point.
     * @param b: The ending point.
     * @param t: The interpolation value [0-1] (no actual bounds).
     * @return: A new vector.
     */
    static Vector3 LerpUnclamped(Vector3 a, Vector3 b, double t);

    /**
     * Returns the magnitude of a vector.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static double Magnitude(Vector3 v);

    /**
     * Returns a vector made from the largest components of two other vectors.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A new vector.
     */
    static Vector3 Max(Vector3 a, Vector3 b);

    /**
     * Returns a vector made from the smallest components of two other vectors.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A new vector.
     */
    static Vector3 Min(Vector3 a, Vector3 b);

    /**
     * Returns a vector "maxDistanceDelta" units closer to the target. This
     * interpolation is in a straight line, and will not overshoot.
     * @param current: The current position.
     * @param target: The destination position.
     * @param maxDistanceDelta: The maximum distance to move.
     * @return: A new vector.
     */
    static Vector3 MoveTowards(Vector3 current, Vector3 target,
                               double maxDistanceDelta);

    /**
     * Returns a new vector with magnitude of one.
     * @param v: The vector in question.
     * @return: A new vector.
     */
    static Vector3 Normalized(Vector3 v);

    /**
     * Creates a new coordinate system out of the three vectors.
     * Normalizes "normal", normalizes "tangent" and makes it orthogonal to
     * "normal" and normalizes "binormal" and makes it orthogonal to both
     * "normal" and "tangent".
     * @param normal: A reference to the first axis vector.
     * @param tangent: A reference to the second axis vector.
     * @param binormal: A reference to the third axis vector.
     */
    static void OrthoNormalize(Vector3 &normal, Vector3 &tangent,
                               Vector3 &binormal);

    /**
     * Returns the vector projection of a onto b.
     * @param a: The target vector.
     * @param b: The vector being projected onto.
     * @return: A new vector.
     */
    static Vector3 Project(Vector3 a, Vector3 b);

    /**
     * Returns a vector projected onto a plane orthogonal to "planeNormal".
     * This can be visualized as the shadow of the vector onto the plane, if
     * the light source were in the direction of the plane normal.
     * @param vector: The vector to project.
     * @param planeNormal: The normal of the plane onto which to project.
     * @param: A new vector.
     */
    static Vector3 ProjectOnPlane(Vector3 vector, Vector3 planeNormal);

    /**
     * Returns a vector reflected off the plane orthogonal to the normal.
     * The input vector is pointed inward, at the plane, and the return vector
     * is pointed outward from the plane, like a beam of light hitting and then
     * reflecting off a mirror.
     * @param vector: The vector traveling inward at the plane.
     * @param planeNormal: The normal of the plane off of which to reflect.
     * @return: A new vector pointing outward from the plane.
     */
    static Vector3 Reflect(Vector3 vector, Vector3 planeNormal);

    /**
     * Returns the vector rejection of a on b.
     * @param a: The target vector.
     * @param b: The vector being projected onto.
     * @return: A new vector.
     */
    static Vector3 Reject(Vector3 a, Vector3 b);

    /**
     * Multiplies two vectors component-wise.
     * @param a: The lhs of the multiplication.
     * @param b: The rhs of the multiplication.
     * @return: A new vector.
     */
    static Vector3 Scale(Vector3 a, Vector3 b);

    /**
     * Returns the squared magnitude of a vector.
     * This is useful when comparing relative lengths, where the exact length
     * is not important, and much time can be saved by not calculating the
     * square root.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static double SqrMagnitude(Vector3 v);


    /**
     * Operator overloading.
     */
    struct Vector3& operator+=(const double& rhs);
    struct Vector3& operator-=(const double& rhs);
    struct Vector3& operator*=(const double& rhs);
    struct Vector3& operator/=(const double& rhs);
    struct Vector3& operator+=(const Vector3& rhs);
    struct Vector3& operator-=(const Vector3& rhs);
};

Vector3 operator+(Vector3 lhs, const double rhs);
Vector3 operator-(Vector3 lhs, const double rhs);
Vector3 operator*(Vector3 lhs, const double rhs);
Vector3 operator/(Vector3 lhs, const double rhs);
Vector3 operator+(const double lhs, Vector3 rhs);
Vector3 operator-(const double lhs, Vector3 rhs);
Vector3 operator*(const double lhs, Vector3 rhs);
Vector3 operator/(const double lhs, Vector3 rhs);
Vector3 operator+(Vector3 lhs, const Vector3 &rhs);
Vector3 operator-(Vector3 lhs, const Vector3 &rhs);
bool operator==(const Vector3 &lhs, const Vector3 &rhs);
bool operator!=(const Vector3 &lhs, const Vector3 &rhs);



/*******************************************************************************
 * Implementation
 */

const Vector3 Vector3::Zero = Vector3(0, 0, 0);
const Vector3 Vector3::One = Vector3(1, 1, 1);
const Vector3 Vector3::Right = Vector3(1, 0, 0);
const Vector3 Vector3::Left = Vector3(-1, 0, 0);
const Vector3 Vector3::Up = Vector3(0, 1, 0);
const Vector3 Vector3::Down = Vector3(0, -1, 0);
const Vector3 Vector3::Forward = Vector3(0, 0, 1);
const Vector3 Vector3::Backward = Vector3(0, 0, -1);


Vector3::Vector3() : X(0), Y(0), Z(0) {}
Vector3::Vector3(double data[]) : X(data[0]), Y(data[1]), Z(data[2]) {}
Vector3::Vector3(double value) : X(value), Y(value), Z(value) {}
Vector3::Vector3(double x, double y) : X(x), Y(y), Z(0) {}
Vector3::Vector3(double x, double y, double z) : X(x), Y(y), Z(z) {}


double Vector3::Angle(Vector3 a, Vector3 b)
{
    return acos(Dot(a, b) / (Magnitude(a) * Magnitude(b)));
}

Vector3 Vector3::ClampMagnitude(Vector3 vector, double maxLength)
{
    double length = Magnitude(vector);
    if (length > maxLength)
        vector *= maxLength / length;
    return vector;
}

double Vector3::Component(Vector3 a, Vector3 b)
{
    return Dot(a, b) / Magnitude(b);
}

Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs)
{
    double x = lhs.Y * rhs.Z - lhs.Z * rhs.Y;
    double y = lhs.Z * rhs.X - lhs.X * rhs.Z;
    double z = lhs.X * rhs.Y - lhs.Y * rhs.X;
    return Vector3(x, y, z);
}

double Vector3::Distance(Vector3 a, Vector3 b)
{
    return Vector3::Magnitude(a - b);
}

double Vector3::Dot(Vector3 lhs, Vector3 rhs)
{
    return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
}

Vector3 Vector3::Lerp(Vector3 a, Vector3 b, double t)
{
    if (t < 0) t = 0;
    else if (t > 1) t = 1;
    return LerpUnclamped(a, b, t);
}

Vector3 Vector3::LerpUnclamped(Vector3 a, Vector3 b, double t)
{
    return (b - a) * t + a;
}

double Vector3::Magnitude(Vector3 v)
{
    return sqrt(SqrMagnitude(v));
}

Vector3 Vector3::Max(Vector3 a, Vector3 b)
{
    double x = a.X > b.X ? a.X : b.X;
    double y = a.Y > b.Y ? a.Y : b.Y;
    double z = a.Z > b.Z ? a.Z : b.Z;
    return Vector3(x, y, z);
}

Vector3 Vector3::Min(Vector3 a, Vector3 b)
{
    double x = a.X > b.X ? b.X : a.X;
    double y = a.Y > b.Y ? b.Y : a.Y;
    double z = a.Z > b.Z ? b.Z : a.Z;
    return Vector3(x, y, z);
}

Vector3 Vector3::MoveTowards(Vector3 current, Vector3 target,
                             double maxDistanceDelta)
{
    Vector3 d = target - current;
    double m = Magnitude(d);
    if (m < maxDistanceDelta || m == 0)
        return target;
    return current + (d * maxDistanceDelta / m);
}

Vector3 Vector3::Normalized(Vector3 v)
{
    return v / Magnitude(v);
}

void Vector3::OrthoNormalize(Vector3 &normal, Vector3 &tangent,
                             Vector3 &binormal)
{
    normal = Normalized(normal);
    tangent = ProjectOnPlane(tangent, normal);
    tangent = Normalized(tangent);
    binormal = ProjectOnPlane(binormal, tangent);
    binormal = ProjectOnPlane(binormal, normal);
    binormal = Normalized(binormal);
}

Vector3 Vector3::Project(Vector3 a, Vector3 b)
{
    double m = Magnitude(b);
    return Dot(a, b) / (m * m) * b;
}

Vector3 Vector3::ProjectOnPlane(Vector3 vector, Vector3 planeNormal)
{
    return Reject(vector, planeNormal);
}

Vector3 Vector3::Reflect(Vector3 vector, Vector3 planeNormal)
{
    return vector - 2 * Project(vector, planeNormal);
}

Vector3 Vector3::Reject(Vector3 a, Vector3 b)
{
    return a - Project(a, b);
}

Vector3 Vector3::Scale(Vector3 a, Vector3 b)
{
    return Vector3(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
}

double Vector3::SqrMagnitude(Vector3 v)
{
    return v.X * v.X + v.Y * v.Y + v.Z * v.Z;
}


struct Vector3& Vector3::operator+=(const double &rhs)
{
    X += rhs;
    Y += rhs;
    Z += rhs;
    return *this;
}

struct Vector3& Vector3::operator-=(const double &rhs)
{
    X -= rhs;
    Y -= rhs;
    Z -= rhs;
    return *this;
}

struct Vector3& Vector3::operator*=(const double &rhs)
{
    X *= rhs;
    Y *= rhs;
    Z *= rhs;
    return *this;
}

struct Vector3& Vector3::operator/=(const double &rhs)
{
    X /= rhs;
    Y /= rhs;
    Z /= rhs;
    return *this;
}

struct Vector3& Vector3::operator+=(const Vector3 &rhs)
{
    X += rhs.X;
    Y += rhs.Y;
    Z += rhs.Z;
    return *this;
}

struct Vector3& Vector3::operator-=(const Vector3 &rhs)
{
    X -= rhs.X;
    Y -= rhs.Y;
    Z -= rhs.Z;
    return *this;
}

Vector3 operator+(Vector3 lhs, const double rhs) { return lhs += rhs; }
Vector3 operator-(Vector3 lhs, const double rhs) { return lhs -= rhs; }
Vector3 operator*(Vector3 lhs, const double rhs) { return lhs *= rhs; }
Vector3 operator/(Vector3 lhs, const double rhs) { return lhs /= rhs; }
Vector3 operator+(const double lhs, Vector3 rhs) { return rhs += lhs; }
Vector3 operator-(const double lhs, Vector3 rhs) { return rhs -= lhs; }
Vector3 operator*(const double lhs, Vector3 rhs) { return rhs *= lhs; }
Vector3 operator/(const double lhs, Vector3 rhs) { return rhs /= lhs; }
Vector3 operator+(Vector3 lhs, const Vector3 &rhs) { return lhs += rhs; }
Vector3 operator-(Vector3 lhs, const Vector3 &rhs) { return lhs -= rhs; }

bool operator==(const Vector3 &lhs, const Vector3 &rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;
}

bool operator!=(const Vector3 &lhs, const Vector3 &rhs)
{
    return !(lhs == rhs);
}
