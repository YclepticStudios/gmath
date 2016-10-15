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
