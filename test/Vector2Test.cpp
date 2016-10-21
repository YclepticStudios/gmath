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

TEST_CASE("Angle between Vector2s", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    CHECK(Vector2::Angle(v1, v2) == Approx(1.5120404684));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    CHECK(Vector2::Angle(v1, v2) == Approx(0.1341958967));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    CHECK(Vector2::Angle(v1, v2) == Approx(2.9437072677));
}

TEST_CASE("Clamp magnitude of Vector2", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    v = Vector2::ClampMagnitude(v, 6);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    // Case 2
    v = Vector2(0.24, 0.0082);
    v = Vector2::ClampMagnitude(v, 0.2);
    CHECK(v.X == Approx(0.199883366));
    CHECK(v.Y == Approx(0.006829348338));
    // Case 3
    v = Vector2(-50, 97);
    v = Vector2::ClampMagnitude(v, 100);
    CHECK(v.X == Approx(-45.8176021421));
    CHECK(v.Y == Approx(88.8861481557));
}

TEST_CASE("Component of a along b (Vector2)", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    CHECK(Vector2::Component(v1, v2) == Approx(0.316227766));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    CHECK(Vector2::Component(v1, v2) == Approx(0.2379810081));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    CHECK(Vector2::Component(v1, v2) == Approx(-85.5778230514));
}

TEST_CASE("Distance between Vector2 points", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    CHECK(Vector2::Distance(v1, v2) == Approx(8.0622577483));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    CHECK(Vector2::Distance(v1, v2) == Approx(0.2964286761));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    CHECK(Vector2::Distance(v1, v2) == Approx(159.9312352231));
}

TEST_CASE("Dot product of Vector2s", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    CHECK(Vector2::Dot(v1, v2) == Approx(2));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    CHECK(Vector2::Dot(v1, v2) == Approx(0.12676376));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    CHECK(Vector2::Dot(v1, v2) == Approx(-6284));
}

TEST_CASE("From Polar coordinate space", "[Vector2]")
{
    // Case 1
    double rad = 5.3851648071;
    double theta = -1.1902899497;
    Vector2 v = Vector2::FromPolar(rad, theta);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    // Case 2
    rad = 0.2401400425;
    theta = 0.034153381;
    v = Vector2::FromPolar(rad, theta);
    CHECK(v.X == Approx(0.24));
    CHECK(v.Y == Approx(0.0082));
    // Case 3
    rad = 87.2811548961;
    theta = 1.8853006312;
    v = Vector2::FromPolar(rad, theta);
    CHECK(v.X == Approx(-27));
    CHECK(v.Y == Approx(83));
}

TEST_CASE("Lerp two Vector2s", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::Lerp(v1, v2, -0.2);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::Lerp(v1, v2, 0.33);
    CHECK(v.X == Approx(0.3357));
    CHECK(v.Y == Approx(-0.012062));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::Lerp(v1, v2, 1.7);
    CHECK(v.X == Approx(36));
    CHECK(v.Y == Approx(-64));
}

TEST_CASE("Lerp two Vector2s without clamping", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::LerpUnclamped(v1, v2, -0.2);
    CHECK(v.X == Approx(1.2));
    CHECK(v.Y == Approx(-6.4));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::LerpUnclamped(v1, v2, 0.33);
    CHECK(v.X == Approx(0.3357));
    CHECK(v.Y == Approx(-0.012062));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::LerpUnclamped(v1, v2, 1.7);
    CHECK(v.X == Approx(80.1));
    CHECK(v.Y == Approx(-166.9));
}

TEST_CASE("Magnitude of a Vector2", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    CHECK(Vector2::Magnitude(v) == Approx(5.385164807));
    // Case 2
    v = Vector2(0.24, 0.0082);
    CHECK(Vector2::Magnitude(v) == Approx(0.2401400425));
    // Case 3
    v = Vector2(-27, 83);
    CHECK(Vector2::Magnitude(v) == Approx(87.2811549));
}

TEST_CASE("Max of Vector2s", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::Max(v1, v2);
    CHECK(v.X == Approx(6));
    CHECK(v.Y == Approx(2));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::Max(v1, v2);
    CHECK(v.X == Approx(0.53));
    CHECK(v.Y == Approx(0.0082));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::Max(v1, v2);
    CHECK(v.X == Approx(36));
    CHECK(v.Y == Approx(83));
}

TEST_CASE("Min of Vector2s", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::Min(v1, v2);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::Min(v1, v2);
    CHECK(v.X == Approx(0.24));
    CHECK(v.Y == Approx(-0.0532));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::Min(v1, v2);
    CHECK(v.X == Approx(-27));
    CHECK(v.Y == Approx(-64));
}

TEST_CASE("Move towards Vector2", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::MoveTowards(v1, v2, 1.7);
    CHECK(v.X == Approx(2.8434361952));
    CHECK(v.Y == Approx(-3.5239866584));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::MoveTowards(v1, v2, 2);
    CHECK(v.X == Approx(0.53));
    CHECK(v.Y == Approx(-0.0532));
    // Case 3 (already at point)
    v1 = Vector2(-27, 83);
    v2 = Vector2(-27, 83);
    v = Vector2::MoveTowards(v1, v2, 1.8);
    CHECK(v.X == Approx(-27));
    CHECK(v.Y == Approx(83));
}

TEST_CASE("Normalized Vector2", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    Vector2 n = Vector2::Normalized(v);
    CHECK(n.X == Approx(0.3713906764));
    CHECK(n.Y == Approx(-.9284766909));
    // Case 2
    v = Vector2(0.24, 0.0082);
    n = Vector2::Normalized(v);
    CHECK(n.X == Approx(0.9994168299));
    CHECK(n.Y == Approx(0.0341467417));
    // Case 3
    v = Vector2(-27, 83);
    n = Vector2::Normalized(v);
    CHECK(n.X == Approx(-0.3093451276));
    CHECK(n.Y == Approx(0.9509498367));
}

TEST_CASE("OrthoNormalize two Vector2s", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2::OrthoNormalize(v1, v2);
    CHECK(Vector2::Angle(v1, v2) == Approx(M_PI / 2));
    CHECK(Vector2::Magnitude(v1) == Approx(1));
    CHECK(Vector2::Magnitude(v2) == Approx(1));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    Vector2::OrthoNormalize(v1, v2);
    CHECK(Vector2::Angle(v1, v2) == Approx(M_PI / 2));
    CHECK(Vector2::Magnitude(v1) == Approx(1));
    CHECK(Vector2::Magnitude(v2) == Approx(1));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    Vector2::OrthoNormalize(v1, v2);
    CHECK(Vector2::Angle(v1, v2) == Approx(M_PI / 2));
    CHECK(Vector2::Magnitude(v1) == Approx(1));
    CHECK(Vector2::Magnitude(v2) == Approx(1));
}


TEST_CASE("Vector2 projection of a on b", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::Project(v1, v2);
    CHECK(v.X == Approx(0.3));
    CHECK(v.Y == Approx(0.1));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::Project(v1, v2);
    CHECK(v.X == Approx(0.23679109));
    CHECK(v.Y == Approx(-0.0237684641));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::Project(v1, v2);
    CHECK(v.X == Approx(-41.9554896142));
    CHECK(v.Y == Approx(74.587537092));
}

TEST_CASE("Vector2 reflect about line", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::Reflect(v1, v2);
    CHECK(v.X == Approx(1.4));
    CHECK(v.Y == Approx(-5.2));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::Reflect(v1, v2);
    CHECK(v.X == Approx(-0.23358218));
    CHECK(v.Y == Approx(0.0557369283));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::Reflect(v1, v2);
    CHECK(v.X == Approx(56.9109792285));
    CHECK(v.Y == Approx(-66.175074184));
    // Case 4
    v1 = Vector2(1, 2);
    v2 = Vector2(0, 1);
    v = Vector2::Reflect(v1, v2);
    CHECK(v.X == Approx(1));
    CHECK(v.Y == Approx(-2));
}

TEST_CASE("Vector2 rejection", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::Reject(v1, v2);
    CHECK(v.X == Approx(1.7));
    CHECK(v.Y == Approx(-5.1));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::Reject(v1, v2);
    CHECK(v.X == Approx(0.00320891));
    CHECK(v.Y == Approx(0.0319684641));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::Reject(v1, v2);
    CHECK(v.X == Approx(14.9554896142));
    CHECK(v.Y == Approx(8.412462908));
}

TEST_CASE("Vector2 rotate towards", "[Vector2]")
{
    // Identical vectors rotate towards
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(2, -5);
    Vector2 v = Vector2::RotateTowards(v1, v2, 0.5, 3);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    // Opposite vectors rotate away
    v1 = Vector2(0.24, 0.0082);
    v2 = -v1;
    v = Vector2::RotateTowards(v1, v2, -0.5, 2);
    CHECK(v.X == Approx(0.24));
    CHECK(v.Y == Approx(0.0082));
    // Identical vectors rotate away
    v1 = Vector2(-27, 83);
    v2 = Vector2(-27, 83);
    v = Vector2::RotateTowards(v1, v2, -0.2, 1);
    CHECK(Vector2::Angle(v, v1) == Approx(0.2));
    CHECK(Vector2::Magnitude(v) == Vector2::Magnitude(v1));
    // Rotate without change in magnitude
    v1 = Vector2(1, 0);
    v2 = Vector2(0, -3);
    v = Vector2::RotateTowards(v1, v2, M_PI_4 , 0);
    CHECK(v.X == Approx(0.7071067812));
    CHECK(v.Y == Approx(-0.7071067812));
    // Rotate and change in magnitude
    v1 = Vector2(1, 0);
    v2 = Vector2(0, 5);
    v = Vector2::RotateTowards(v1, v2, M_PI_4 , 2);
    CHECK(v.X == Approx(2.1213203436));
    CHECK(v.Y == Approx(2.1213203436));
    // Rotate and negative change in magnitude
    v1 = Vector2(5, 0);
    v2 = Vector2(0, 1);
    v = Vector2::RotateTowards(v1, v2, M_PI_4 , 2);
    CHECK(v.X == Approx(2.1213203436));
    CHECK(v.Y == Approx(2.1213203436));
    // Clamp magnitude with max
    v1 = Vector2(1, 0);
    v2 = Vector2(0, 5);
    v = Vector2::RotateTowards(v1, v2, M_PI_4 , 10);
    CHECK(v.X == Approx(3.535533906));
    CHECK(v.Y == Approx(3.535533906));
    // Clamp magnitude with min
    v1 = Vector2(5, 0);
    v2 = Vector2(0, 1);
    v = Vector2::RotateTowards(v1, v2, M_PI_4 , 10);
    CHECK(v.X == Approx(0.7071067812));
    CHECK(v.Y == Approx(0.7071067812));
    // Clamp angle max
    v1 = Vector2(2, -5);
    v2 = Vector2(6, 2);
    v = Vector2::RotateTowards(v1, v2, M_PI , 0);
    CHECK(v.X == Approx(5.1088159098));
    CHECK(v.Y == Approx(1.7029386366));
    // Clamp angle min
    v1 = Vector2(2, -5);
    v2 = Vector2(6, 2);
    v = Vector2::RotateTowards(v1, v2, 0 , 0);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
}

TEST_CASE("Scale Vector2", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::Scale(v1, v2);
    CHECK(v.X == Approx(12));
    CHECK(v.Y == Approx(-10));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::Scale(v1, v2);
    CHECK(v.X == Approx(0.1272));
    CHECK(v.Y == Approx(-0.00043624));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::Scale(v1, v2);
    CHECK(v.X == Approx(-972));
    CHECK(v.Y == Approx(-5312));
}

TEST_CASE("Slerp two Vector2s with clamping", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::Slerp(v1, v2, -0.2);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::Slerp(v1, v2, 0.33);
    CHECK(v.X == Approx(0.3366554545));
    CHECK(v.Y == Approx(-0.003410834));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::Slerp(v1, v2, 1.7);
    CHECK(v.X == Approx(36));
    CHECK(v.Y == Approx(-64));
}

TEST_CASE("Slerp two Vector2s without clamping", "[Vector2]")
{
    // Case 1
    Vector2 v1 = Vector2(2, -5);
    Vector2 v2 = Vector2(6, 2);
    Vector2 v = Vector2::SlerpUnclamped(v1, v2, -0.2);
    CHECK(v.X == Approx(0.4054866393));
    CHECK(v.Y == Approx(-5.1814447478));
    // Case 2
    v1 = Vector2(0.24, 0.0082);
    v2 = Vector2(0.53, -0.0532);
    v = Vector2::SlerpUnclamped(v1, v2, 0.33);
    CHECK(v.X == Approx(0.3366554545));
    CHECK(v.Y == Approx(-0.003410834));
    // Case 3
    v1 = Vector2(-27, 83);
    v2 = Vector2(36, -64);
    v = Vector2::SlerpUnclamped(v1, v2, 1.7);
    CHECK(v.X == Approx(-63.7183356526));
    CHECK(v.Y == Approx(-1.4396764415));
}

TEST_CASE("Square magnitude of a Vector2", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    CHECK(Vector2::SqrMagnitude(v) == Approx(29));
    // Case 2
    v = Vector2(0.24, 0.0082);
    CHECK(Vector2::SqrMagnitude(v) == Approx(0.05766724));
    // Case 3
    v = Vector2(-27, 83);
    CHECK(Vector2::SqrMagnitude(v) == Approx(7618));
}

TEST_CASE("To Polar coordinate space", "[Vector2]")
{
    // Case 1
    Vector2 v = Vector2(2, -5);
    double rad, theta;
    Vector2::ToPolar(v, rad, theta);
    CHECK(rad == Approx(5.3851648071));
    CHECK(theta == Approx(-1.1902899497));
    // Case 2
    v = Vector2(0.24, 0.0082);
    Vector2::ToPolar(v, rad, theta);
    CHECK(rad == Approx(0.2401400425));
    CHECK(theta == Approx(0.034153381));
    // Case 3
    v = Vector2(-27, 83);
    Vector2::ToPolar(v, rad, theta);
    CHECK(rad == Approx(87.2811548961));
    CHECK(theta == Approx(1.8853006312));
}
