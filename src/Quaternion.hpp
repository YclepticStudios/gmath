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
     * Static constants.
     */
    static const Quaternion Identity;


    /**
     * Constructors.
     */
    Quaternion();
    Quaternion(double data[]);
    Quaternion(double x, double y, double z, double w);


    /**
     * Returns the angle between two quaternions.
     * @param a: The first quaternion.
     * @param b: The second quaternion.
     * @return: A scalar value.
     */
    static double Angle(Quaternion a, Quaternion b);

    /**
     * Returns the conjugate of a quaternion.
     * @param rotation: The quaternion in question.
     * @return: A new quaternion.
     */
    static Quaternion Conjugate(Quaternion rotation);

    /**
     * Returns the inverse of a rotation.
     * @param rotation: The quaternion in question.
     * @return: A new quaternion.
     */
    static Quaternion Inverse(Quaternion rotation);

    /**
     * Returns the norm of a quaternion.
     * @param rotation: The quaternion in question.
     * @return: A scalar value.
     */
    static double Norm(Quaternion rotation);

    /**
     * Returns a quaternion with identical rotation and a norm of one.
     * @param rotation: The quaternion in question.
     * @return: A new quaternion.
     */
    static Quaternion Normalized(Quaternion rotation);


    /**
     * Operator overloading.
     */
    struct Quaternion& operator+=(const double& rhs);
    struct Quaternion& operator-=(const double& rhs);
    struct Quaternion& operator*=(const double &rhs);
    struct Quaternion& operator/=(const double &rhs);
    struct Quaternion& operator+=(const Quaternion& rhs);
    struct Quaternion& operator-=(const Quaternion& rhs);
    struct Quaternion& operator*=(const Quaternion &rhs);
};

Quaternion operator-(Quaternion rhs);
Quaternion operator+(Quaternion lhs, const double rhs);
Quaternion operator-(Quaternion lhs, const double rhs);
Quaternion operator*(Quaternion lhs, const double rhs);
Quaternion operator/(Quaternion lhs, const double rhs);
Quaternion operator+(const double lhs, Quaternion rhs);
Quaternion operator-(const double lhs, Quaternion rhs);
Quaternion operator*(const double lhs, Quaternion rhs);
Quaternion operator/(const double lhs, Quaternion rhs);
Quaternion operator+(Quaternion lhs, const Quaternion &rhs);
Quaternion operator-(Quaternion lhs, const Quaternion &rhs);
Quaternion operator*(Quaternion lhs, const Quaternion &rhs);
bool operator==(const Quaternion &lhs, const Quaternion &rhs);
bool operator!=(const Quaternion &lhs, const Quaternion &rhs);



/*******************************************************************************
 * Implementation
 */

const Quaternion Quaternion::Identity = Quaternion(0, 0, 0, 1);


Quaternion::Quaternion() : X(0), Y(0), Z(0), W(1) {}
Quaternion::Quaternion(double data[]) : X(data[0]), Y(data[1]), Z(data[2]),
    W(data[3]) {}
Quaternion::Quaternion(double x, double y, double z, double w) : X(x), Y(y),
    Z(z), W(w) {}


double Quaternion::Angle(Quaternion a, Quaternion b)
{
    double angle = acos((b * Inverse(a)).W) * 2.0;
    if (angle > M_PI)
        angle = 2.0 * M_PI - angle;
    return angle;
}

Quaternion Quaternion::Conjugate(Quaternion rotation)
{
    return Quaternion(-rotation.X, -rotation.Y, -rotation.Z, rotation.W);
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
        rotation.Z  * rotation.Z +
        rotation.W * rotation.W);
}

Quaternion Quaternion::Normalized(Quaternion rotation)
{
    return rotation / Norm(rotation);
}


struct Quaternion& Quaternion::operator+=(const double &rhs)
{
    X += rhs;
    Y += rhs;
    Z += rhs;
    W += rhs;
    return *this;
}

struct Quaternion& Quaternion::operator-=(const double &rhs)
{
    X -= rhs;
    Y -= rhs;
    Z -= rhs;
    W -= rhs;
    return *this;
}

struct Quaternion& Quaternion::operator*=(const double &rhs)
{
    X *= rhs;
    Y *= rhs;
    Z *= rhs;
    W *= rhs;
    return *this;
}

struct Quaternion& Quaternion::operator/=(const double &rhs)
{
    X /= rhs;
    Y /= rhs;
    Z /= rhs;
    W /= rhs;
    return *this;
}

struct Quaternion& Quaternion::operator+=(const Quaternion &rhs)
{
    X += rhs.X;
    Y += rhs.Y;
    Z += rhs.Z;
    W += rhs.W;
    return *this;
}

struct Quaternion& Quaternion::operator-=(const Quaternion &rhs)
{
    X -= rhs.X;
    Y -= rhs.Y;
    Z -= rhs.Z;
    W -= rhs.W;
    return *this;
}

struct Quaternion& Quaternion::operator*=(const Quaternion &rhs)
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
Quaternion operator+(Quaternion lhs, const Quaternion &rhs)
{
    return lhs += rhs;
}
Quaternion operator-(Quaternion lhs, const Quaternion &rhs)
{
    return lhs -= rhs;
}
Quaternion operator*(Quaternion lhs, const Quaternion &rhs)
{
    return lhs *= rhs;
}

bool operator==(const Quaternion &lhs, const Quaternion &rhs)
{
    return lhs.X == rhs.X &&
        lhs.Y == rhs.Y &&
        lhs.Z == rhs.Z &&
        lhs.W == rhs.W;
}

bool operator!=(const Quaternion &lhs, const Quaternion &rhs)
{
    return !(lhs == rhs);
}
