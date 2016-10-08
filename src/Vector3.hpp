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
};



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


Vector3::Vector3()
{
    X = 0;
    Y = 0;
    Z = 0;
}

Vector3::Vector3(double data[])
{
    X = data[0];
    Y = data[1];
    Z = data[2];
}

Vector3::Vector3(double value)
{
    X = value;
    Y = value;
    Z = value;
}

Vector3::Vector3(double x, double y)
{
    X = x;
    Y = y;
    Z = 0;
}

Vector3::Vector3(double x, double y, double z)
{
    X = x;
    Y = y;
    X = z;
}
