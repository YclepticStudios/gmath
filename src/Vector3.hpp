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
     * Returns the magnitude of a vector.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static double Magnitude(Vector3 v);

    /**
     * Returns a new vector with magnitude of one.
     * @param v: The vector in question.
     * @return: A new vector.
     */
    static Vector3 Normalized(Vector3 v);

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


double Vector3::Magnitude(Vector3 v)
{
    return sqrt(SqrMagnitude(v));
}

Vector3 Vector3::Normalized(Vector3 v)
{
    return v / Magnitude(v);
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
