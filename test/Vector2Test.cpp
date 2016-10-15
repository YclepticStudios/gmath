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
 *  This file contains test cases for the Vector2 functions.
 *
 *  Created by Eric Phillips on October 15, 2016.
 */

#include "catch.hpp"
#include "Vector2.hpp"


TEST_CASE("Vector2 plus scalar", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    v = v + 3;
    CHECK(v.X == Approx(5));
    CHECK(v.Y == Approx(-2));
    // Case 2
    v = Vector2(0.24, 0.0082);
    v = v + 0.2;
    CHECK(v.X == Approx(0.44));
    CHECK(v.Y == Approx(0.2082));
    // Case 3
    v = Vector2(-27, 83);
    v = v + 13;
    CHECK(v.X == Approx(-14));
    CHECK(v.Y == Approx(96));
}

TEST_CASE("Vector2 minus scalar", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    v = v - 3;
    CHECK(v.X == Approx(-1));
    CHECK(v.Y == Approx(-8));
    // Case 2
    v = Vector2(0.24, 0.0082);
    v = v - 0.2;
    CHECK(v.X == Approx(0.04));
    CHECK(v.Y == Approx(-0.1918));
    // Case 3
    v = Vector2(-27, 83);
    v = v - 13;
    CHECK(v.X == Approx(-40));
    CHECK(v.Y == Approx(70));
}

TEST_CASE("Vector2 times scalar", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    v = v * 3;
    CHECK(v.X == Approx(6));
    CHECK(v.Y == Approx(-15));
    // Case 2
    v = Vector2(0.24, 0.0082);
    v = v * 0.2;
    CHECK(v.X == Approx(0.048));
    CHECK(v.Y == Approx(0.00164));
    // Case 3
    v = Vector2(-27, 83);
    v = v * 13;
    CHECK(v.X == Approx(-351));
    CHECK(v.Y == Approx(1079));
}

TEST_CASE("Vector2 divided by scalar", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    v = v / 3;
    CHECK(v.X == Approx(0.66666667));
    CHECK(v.Y == Approx(-1.66666667));
    // Case 2
    v = Vector2(0.24, 0.0082);
    v = v / 0.2;
    CHECK(v.X == Approx(1.2));
    CHECK(v.Y == Approx(0.041));
    // Case 3
    v = Vector2(-27, 83);
    v = v / 13;
    CHECK(v.X == Approx(-2.0769231));
    CHECK(v.Y == Approx(6.3846154));
}

TEST_CASE("Vector2 plus Vector2", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = v1 + v2;
    CHECK(v.X == Approx(8));
    CHECK(v.Y == Approx(-3));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = v1 + v2;
    CHECK(v.X == Approx(0.77));
    CHECK(v.Y == Approx(-0.045));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = v1 + v2;
    CHECK(v.X == Approx(9));
    CHECK(v.Y == Approx(19));
}

TEST_CASE("Vector2 minus Vector2", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = v1 - v2;
    CHECK(v.X == Approx(-4));
    CHECK(v.Y == Approx(-7));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = v1 - v2;
    CHECK(v.X == Approx(-0.29));
    CHECK(v.Y == Approx(0.0614));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = v1 - v2;
    CHECK(v.X == Approx(-63));
    CHECK(v.Y == Approx(147));
}

TEST_CASE("Vector2 equality", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    CHECK_FALSE(v1 == v2);
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.24, 0.0082);
    CHECK(v1 == v2);
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(-27, 84);
    CHECK_FALSE(v1 == v2);
}

TEST_CASE("Vector2 inequality", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    CHECK(v1 != v2);
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.24, 0.0082);
    CHECK_FALSE(v1 != v2);
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(-27, 84);
    CHECK(v1 != v2);
}
