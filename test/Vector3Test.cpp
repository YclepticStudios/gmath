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
 *  This file contains test cases for the Vector3 functions.
 *
 *  Created by Eric Phillips on October 8, 2016.
 */

#include "catch.hpp"
#include "Vector3.hpp"


TEST_CASE("Vector plus scalar", "[Vector3]")
{
    // Vector 1
    Vector3 v = Vector3(2, -5, 4);
    v = v + 3;
    CHECK(v.X == Approx(5));
    CHECK(v.Y == Approx(-2));
    CHECK(v.Z == Approx(7));
    // Vector 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v + 0.2;
    CHECK(v.X == Approx(0.44));
    CHECK(v.Y == Approx(0.2082));
    CHECK(v.Z == Approx(0.17));
    // Vector 3
    v = Vector3(-27, 83, -163);
    v = v + 13;
    CHECK(v.X == Approx(-14));
    CHECK(v.Y == Approx(96));
    CHECK(v.Z == Approx(-150));
}

TEST_CASE("Vector minus scalar", "[Vector3]")
{
    // Vector 1
    Vector3 v = Vector3(2, -5, 4);
    v = v - 3;
    CHECK(v.X == Approx(-1));
    CHECK(v.Y == Approx(-8));
    CHECK(v.Z == Approx(1));
    // Vector 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v - 0.2;
    CHECK(v.X == Approx(0.04));
    CHECK(v.Y == Approx(-0.1918));
    CHECK(v.Z == Approx(-0.23));
    // Vector 3
    v = Vector3(-27, 83, -163);
    v = v - 13;
    CHECK(v.X == Approx(-40));
    CHECK(v.Y == Approx(70));
    CHECK(v.Z == Approx(-176));
}

TEST_CASE("Vector times scalar", "[Vector3]")
{
    // Vector 1
    Vector3 v = Vector3(2, -5, 4);
    v = v * 3;
    CHECK(v.X == Approx(6));
    CHECK(v.Y == Approx(-15));
    CHECK(v.Z == Approx(12));
    // Vector 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v * 0.2;
    CHECK(v.X == Approx(0.048));
    CHECK(v.Y == Approx(0.00164));
    CHECK(v.Z == Approx(-0.006));
    // Vector 3
    v = Vector3(-27, 83, -163);
    v = v * 13;
    CHECK(v.X == Approx(-351));
    CHECK(v.Y == Approx(1079));
    CHECK(v.Z == Approx(-2119));
}

TEST_CASE("Vector divided by scalar", "[Vector3]")
{
    // Vector 1
    Vector3 v = Vector3(2, -5, 4);
    v = v / 3;
    CHECK(v.X == Approx(0.66666667));
    CHECK(v.Y == Approx(-1.66666667));
    CHECK(v.Z == Approx(1.33333333));
    // Vector 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v / 0.2;
    CHECK(v.X == Approx(1.2));
    CHECK(v.Y == Approx(0.041));
    CHECK(v.Z == Approx(-0.15));
    // Vector 3
    v = Vector3(-27, 83, -163);
    v = v / 13;
    CHECK(v.X == Approx(-2.0769231));
    CHECK(v.Y == Approx(6.3846154));
    CHECK(v.Z == Approx(-12.538462));
}

TEST_CASE("Vector plus vector", "[Vector3]")
{
    // Vector 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = v1 + v2;
    CHECK(v.X == Approx(8));
    CHECK(v.Y == Approx(-3));
    CHECK(v.Z == Approx(-4));
    // Vector 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = v1 + v2;
    CHECK(v.X == Approx(0.77));
    CHECK(v.Y == Approx(-0.045));
    CHECK(v.Z == Approx(-1.56));
    // Vector 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = v1 + v2;
    CHECK(v.X == Approx(9));
    CHECK(v.Y == Approx(19));
    CHECK(v.Z == Approx(101));
}

TEST_CASE("Vector minus vector", "[Vector3]")
{
    // Vector 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = v1 - v2;
    CHECK(v.X == Approx(-4));
    CHECK(v.Y == Approx(-7));
    CHECK(v.Z == Approx(12));
    // Vector 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = v1 - v2;
    CHECK(v.X == Approx(-0.29));
    CHECK(v.Y == Approx(0.0614));
    CHECK(v.Z == Approx(1.5));
    // Vector 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = v1 - v2;
    CHECK(v.X == Approx(-63));
    CHECK(v.Y == Approx(147));
    CHECK(v.Z == Approx(-427));
}

TEST_CASE("Magnitude of a vector", "[Vector3]")
{
    // Vector 1
    Vector3 v = Vector3(2, -5, 4);
    CHECK(Vector3::Magnitude(v) == Approx(6.70820393));
    // Vector 2
    v = Vector3(0.24, 0.0082, -0.03);
    CHECK(Vector3::Magnitude(v) == Approx(0.242007));
    // Vector 3
    v = Vector3(-27, 83, -163);
    CHECK(Vector3::Magnitude(v) == Approx(184.897269));
}

TEST_CASE("Normalized vector", "[Vector3]")
{
    // Vector 1
    Vector3 v = Vector3(2, -5, 4);
    Vector3 n = Vector3::Normalized(v);
    CHECK(n.X == Approx(0.298142));
    CHECK(n.Y == Approx(-0.745356));
    CHECK(n.Z == Approx(0.596285));
    // Vector 2
    v = Vector3(0.24, 0.0082, -0.03);
    n = Vector3::Normalized(v);
    CHECK(n.X == Approx(0.991708));
    CHECK(n.Y == Approx(0.0338834));
    CHECK(n.Z == Approx(-0.123964));
    // Vector 3
    v = Vector3(-27, 83, -163);
    n = Vector3::Normalized(v);
    CHECK(n.X == Approx(-0.146027));
    CHECK(n.Y == Approx(0.448898));
    CHECK(n.Z == Approx(-0.881571));
}

TEST_CASE("Square magnitude of a vector", "[Vector3]")
{
    // Vector 1
    Vector3 v = Vector3(2, -5, 4);
    CHECK(Vector3::SqrMagnitude(v) == Approx(45));
    // Vector 2
    v = Vector3(0.24, 0.0082, -0.03);
    CHECK(Vector3::SqrMagnitude(v) == Approx(0.05856738));
    // Vector 3
    v = Vector3(-27, 83, -163);
    CHECK(Vector3::SqrMagnitude(v) == Approx(34187));
}
