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
 *  2D vector.
 *
 *  Created by Eric Phillips on October 15, 2016.
 */

#pragma once

#include <math.h>


struct Vector2
{
    union
    {
        struct
        {
            double X;
            double Y;
        };
        double data[2];
    };


    /**
     * Static constants.
     */
    static const Vector2 Zero;
    static const Vector2 One;
    static const Vector2 Right;
    static const Vector2 Left;
    static const Vector2 Up;
    static const Vector2 Down;


    /**
     * Constructors.
     */
    Vector2();
    Vector2(double data[]);
    Vector2(double value);
    Vector2(double x, double y);


    /**
     * Returns a vector with its magnitude clamped to maxLength.
     * @param vector: The target vector.
     * @param maxLength: The maximum length of the return vector.
     * @return: A new vector.
     */
    static Vector2 ClampMagnitude(Vector2 vector, double maxLength);

    /**
     * Returns the distance between a and b.
     * @param a: The first point.
     * @param b: The second point.
     * @return: A scalar value.
     */
    static double Distance(Vector2 a, Vector2 b);

    /**
     * Returns the dot product of two vectors.
     * @param lhs: The left side of the multiplication.
     * @param rhs: The right side of the multiplication.
     * @return: A scalar value.
     */
    static double Dot(Vector2 lhs, Vector2 rhs);

    /**
     * Returns the magnitude of a vector.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static double Magnitude(Vector2 v);

    /**
     * Returns a vector made from the largest components of two other vectors.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A new vector.
     */
    static Vector2 Max(Vector2 a, Vector2 b);

    /**
     * Returns a vector made from the smallest components of two other vectors.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A new vector.
     */
    static Vector2 Min(Vector2 a, Vector2 b);

    /**
     * Returns a new vector with magnitude of one.
     * @param v: The vector in question.
     * @return: A new vector.
     */
    static Vector2 Normalized(Vector2 v);

    /**
     * Multiplies two vectors component-wise.
     * @param a: The lhs of the multiplication.
     * @param b: The rhs of the multiplication.
     * @return: A new vector.
     */
    static Vector2 Scale(Vector2 a, Vector2 b);

    /**
     * Returns the squared magnitude of a vector.
     * This is useful when comparing relative lengths, where the exact length
     * is not important, and much time can be saved by not calculating the
     * square root.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static double SqrMagnitude(Vector2 v);


    /**
     * Operator overloading.
     */
    struct Vector2& operator+=(const double& rhs);
    struct Vector2& operator-=(const double& rhs);
    struct Vector2& operator*=(const double& rhs);
    struct Vector2& operator/=(const double& rhs);
    struct Vector2& operator+=(const Vector2& rhs);
    struct Vector2& operator-=(const Vector2& rhs);
};

Vector2 operator-(Vector2 rhs);
Vector2 operator+(Vector2 lhs, const double rhs);
Vector2 operator-(Vector2 lhs, const double rhs);
Vector2 operator*(Vector2 lhs, const double rhs);
Vector2 operator/(Vector2 lhs, const double rhs);
Vector2 operator+(const double lhs, Vector2 rhs);
Vector2 operator-(const double lhs, Vector2 rhs);
Vector2 operator*(const double lhs, Vector2 rhs);
Vector2 operator/(const double lhs, Vector2 rhs);
Vector2 operator+(Vector2 lhs, const Vector2 &rhs);
Vector2 operator-(Vector2 lhs, const Vector2 &rhs);
bool operator==(const Vector2 &lhs, const Vector2 &rhs);
bool operator!=(const Vector2 &lhs, const Vector2 &rhs);



/*******************************************************************************
 * Implementation
 */

const Vector2 Vector2::Zero = Vector2(0, 0);
const Vector2 Vector2::One = Vector2(1, 1);
const Vector2 Vector2::Right = Vector2(1, 0);
const Vector2 Vector2::Left = Vector2(-1, 0);
const Vector2 Vector2::Up = Vector2(0, 1);
const Vector2 Vector2::Down = Vector2(0, -1);


Vector2::Vector2() : X(0), Y(0) {}
Vector2::Vector2(double data[]) : X(data[0]), Y(data[1]) {}
Vector2::Vector2(double value) : X(value), Y(value) {}
Vector2::Vector2(double x, double y) : X(x), Y(y) {}


Vector2 Vector2::ClampMagnitude(Vector2 vector, double maxLength)
{
    double length = Magnitude(vector);
    if (length > maxLength)
        vector *= maxLength / length;
    return vector;
}

double Vector2::Distance(Vector2 a, Vector2 b)
{
    return Vector2::Magnitude(a - b);
}

double Vector2::Dot(Vector2 lhs, Vector2 rhs)
{
    return lhs.X * rhs.X + lhs.Y * rhs.Y;
}

double Vector2::Magnitude(Vector2 v)
{
    return sqrt(SqrMagnitude(v));
}

Vector2 Vector2::Max(Vector2 a, Vector2 b)
{
    double x = a.X > b.X ? a.X : b.X;
    double y = a.Y > b.Y ? a.Y : b.Y;
    return Vector2(x, y);
}

Vector2 Vector2::Min(Vector2 a, Vector2 b)
{
    double x = a.X > b.X ? b.X : a.X;
    double y = a.Y > b.Y ? b.Y : a.Y;
    return Vector2(x, y);
}

Vector2 Vector2::Normalized(Vector2 v)
{
    return v / Magnitude(v);
}

Vector2 Vector2::Scale(Vector2 a, Vector2 b)
{
    return Vector2(a.X * b.X, a.Y * b.Y);
}

double Vector2::SqrMagnitude(Vector2 v)
{
    return v.X * v.X + v.Y * v.Y;
}


struct Vector2& Vector2::operator+=(const double &rhs)
{
    X += rhs;
    Y += rhs;
    return *this;
}

struct Vector2& Vector2::operator-=(const double &rhs)
{
    X -= rhs;
    Y -= rhs;
    return *this;
}

struct Vector2& Vector2::operator*=(const double &rhs)
{
    X *= rhs;
    Y *= rhs;
    return *this;
}

struct Vector2& Vector2::operator/=(const double &rhs)
{
    X /= rhs;
    Y /= rhs;
    return *this;
}

struct Vector2& Vector2::operator+=(const Vector2 &rhs)
{
    X += rhs.X;
    Y += rhs.Y;
    return *this;
}

struct Vector2& Vector2::operator-=(const Vector2 &rhs)
{
    X -= rhs.X;
    Y -= rhs.Y;
    return *this;
}

Vector2 operator-(Vector2 rhs) { return rhs * -1; }
Vector2 operator+(Vector2 lhs, const double rhs) { return lhs += rhs; }
Vector2 operator-(Vector2 lhs, const double rhs) { return lhs -= rhs; }
Vector2 operator*(Vector2 lhs, const double rhs) { return lhs *= rhs; }
Vector2 operator/(Vector2 lhs, const double rhs) { return lhs /= rhs; }
Vector2 operator+(const double lhs, Vector2 rhs) { return rhs += lhs; }
Vector2 operator-(const double lhs, Vector2 rhs) { return rhs -= lhs; }
Vector2 operator*(const double lhs, Vector2 rhs) { return rhs *= lhs; }
Vector2 operator/(const double lhs, Vector2 rhs) { return rhs /= lhs; }
Vector2 operator+(Vector2 lhs, const Vector2 &rhs) { return lhs += rhs; }
Vector2 operator-(Vector2 lhs, const Vector2 &rhs) { return lhs -= rhs; }

bool operator==(const Vector2 &lhs, const Vector2 &rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

bool operator!=(const Vector2 &lhs, const Vector2 &rhs)
{
    return !(lhs == rhs);
}
