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


TEST_CASE("Vector3 plus scalar", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    v = v + 3;
    CHECK(v.X == Approx(5));
    CHECK(v.Y == Approx(-2));
    CHECK(v.Z == Approx(7));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v + 0.2;
    CHECK(v.X == Approx(0.44));
    CHECK(v.Y == Approx(0.2082));
    CHECK(v.Z == Approx(0.17));
    // Case 3
    v = Vector3(-27, 83, -163);
    v = v + 13;
    CHECK(v.X == Approx(-14));
    CHECK(v.Y == Approx(96));
    CHECK(v.Z == Approx(-150));
}

TEST_CASE("Vector3 minus scalar", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    v = v - 3;
    CHECK(v.X == Approx(-1));
    CHECK(v.Y == Approx(-8));
    CHECK(v.Z == Approx(1));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v - 0.2;
    CHECK(v.X == Approx(0.04));
    CHECK(v.Y == Approx(-0.1918));
    CHECK(v.Z == Approx(-0.23));
    // Case 3
    v = Vector3(-27, 83, -163);
    v = v - 13;
    CHECK(v.X == Approx(-40));
    CHECK(v.Y == Approx(70));
    CHECK(v.Z == Approx(-176));
}

TEST_CASE("Vector3 times scalar", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    v = v * 3;
    CHECK(v.X == Approx(6));
    CHECK(v.Y == Approx(-15));
    CHECK(v.Z == Approx(12));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v * 0.2;
    CHECK(v.X == Approx(0.048));
    CHECK(v.Y == Approx(0.00164));
    CHECK(v.Z == Approx(-0.006));
    // Case 3
    v = Vector3(-27, 83, -163);
    v = v * 13;
    CHECK(v.X == Approx(-351));
    CHECK(v.Y == Approx(1079));
    CHECK(v.Z == Approx(-2119));
}

TEST_CASE("Vector3 divided by scalar", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    v = v / 3;
    CHECK(v.X == Approx(0.66666667));
    CHECK(v.Y == Approx(-1.66666667));
    CHECK(v.Z == Approx(1.33333333));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = v / 0.2;
    CHECK(v.X == Approx(1.2));
    CHECK(v.Y == Approx(0.041));
    CHECK(v.Z == Approx(-0.15));
    // Case 3
    v = Vector3(-27, 83, -163);
    v = v / 13;
    CHECK(v.X == Approx(-2.0769231));
    CHECK(v.Y == Approx(6.3846154));
    CHECK(v.Z == Approx(-12.538462));
}

TEST_CASE("Vector3 plus Vector3", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = v1 + v2;
    CHECK(v.X == Approx(8));
    CHECK(v.Y == Approx(-3));
    CHECK(v.Z == Approx(-4));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = v1 + v2;
    CHECK(v.X == Approx(0.77));
    CHECK(v.Y == Approx(-0.045));
    CHECK(v.Z == Approx(-1.56));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = v1 + v2;
    CHECK(v.X == Approx(9));
    CHECK(v.Y == Approx(19));
    CHECK(v.Z == Approx(101));
}

TEST_CASE("Vector3 minus Vector3", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = v1 - v2;
    CHECK(v.X == Approx(-4));
    CHECK(v.Y == Approx(-7));
    CHECK(v.Z == Approx(12));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = v1 - v2;
    CHECK(v.X == Approx(-0.29));
    CHECK(v.Y == Approx(0.0614));
    CHECK(v.Z == Approx(1.5));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = v1 - v2;
    CHECK(v.X == Approx(-63));
    CHECK(v.Y == Approx(147));
    CHECK(v.Z == Approx(-427));
}

TEST_CASE("Vector3 equality", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    CHECK_FALSE(v1 == v2);
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.24, 0.0082, -0.03);
    CHECK(v1 == v2);
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(-27, 83, 264);
    CHECK_FALSE(v1 == v2);
}

TEST_CASE("Vector3 inequality", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    CHECK(v1 != v2);
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.24, 0.0082, -0.03);
    CHECK_FALSE(v1 != v2);
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(-27, 83, 264);
    CHECK(v1 != v2);
}

TEST_CASE("Angle between Vector3s", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    CHECK(Vector3::Angle(v1, v2) == Approx(2.02476));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    CHECK(Vector3::Angle(v1, v2) == Approx(1.11476));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    CHECK(Vector3::Angle(v1, v2) == Approx(2.91024));
}

TEST_CASE("Clamp magnitude of Vector3", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    v = Vector3::ClampMagnitude(v, 7);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    CHECK(v.Z == Approx(4));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    v = Vector3::ClampMagnitude(v, 0.2);
    CHECK(v.X == Approx(0.198341621));
    CHECK(v.Y == Approx(0.00677667205));
    CHECK(v.Z == Approx(-0.02479270262));
    // Case 3
    v = Vector3(-27, 83, -163);
    v = Vector3::ClampMagnitude(v, 100);
    CHECK(v.X == Approx(-14.6027035332));
    CHECK(v.Y == Approx(44.8897923428));
    CHECK(v.Z == Approx(-88.1570620707));
}

TEST_CASE("Component of a along b (Vector3)", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    CHECK(Vector3::Component(v1, v2) == Approx(-2.9417420271));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    CHECK(Vector3::Component(v1, v2) == Approx(0.10658));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    CHECK(Vector3::Component(v1, v2) == Approx(-179.9710189279));
}

TEST_CASE("Cross product of Vector3s", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Cross(v1, v2);
    CHECK(v.X == Approx(32));
    CHECK(v.Y == Approx(40));
    CHECK(v.Z == Approx(34));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Cross(v1, v2);
    CHECK(v.X == Approx(-0.014142));
    CHECK(v.Y == Approx(0.3513));
    CHECK(v.Z == Approx(-0.017114));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Cross(v1, v2);
    CHECK(v.X == Approx(11480));
    CHECK(v.Y == Approx(1260));
    CHECK(v.Z == Approx(-1260));
    // Cross product of vector and itself is zero
    v = Vector3::Cross(v1, v1);
    CHECK(v.X == Approx(0));
    CHECK(v.Y == Approx(0));
    CHECK(v.Z == Approx(0));
}

TEST_CASE("Distance between Vector3 points", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    CHECK(Vector3::Distance(v1, v2) == Approx(14.4568));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    CHECK(Vector3::Distance(v1, v2) == Approx(1.52901));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    CHECK(Vector3::Distance(v1, v2) == Approx(455.968));
}

TEST_CASE("Dot product of Vector3s", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    CHECK(Vector3::Dot(v1, v2) == Approx(-30));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    CHECK(Vector3::Dot(v1, v2) == Approx(0.172663));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    CHECK(Vector3::Dot(v1, v2) == Approx(-49316));
}

TEST_CASE("From Spherical coordinate space", "[Vector3]")
{
    // Case 1
    double rad = 6.7082;
    double theta = 0.931931;
    double phi = -1.19029;
    Vector3 v = Vector3::FromSpherical(rad, theta, phi);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    CHECK(v.Z == Approx(4));
    // Case 2
    rad = 0.242007;
    theta = 1.69508;
    phi = 0.0341533;
    v = Vector3::FromSpherical(rad, theta, phi);
    CHECK(v.X == Approx(0.24));
    CHECK(v.Y == Approx(0.0082));
    CHECK(v.Z == Approx(-0.03));
    // Case 3
    rad = 184.8972;
    theta = 2.6499755;
    phi = 1.8853006;
    v = Vector3::FromSpherical(rad, theta, phi);
    CHECK(v.X == Approx(-27));
    CHECK(v.Y == Approx(83));
    CHECK(v.Z == Approx(-163));
}

TEST_CASE("Lerp two Vector3s", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Lerp(v1, v2, -0.2);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    CHECK(v.Z == Approx(4));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Lerp(v1, v2, 0.33);
    CHECK(v.X == Approx(0.3357));
    CHECK(v.Y == Approx(-0.012062));
    CHECK(v.Z == Approx(-0.525));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Lerp(v1, v2, 1.7);
    CHECK(v.X == Approx(36));
    CHECK(v.Y == Approx(-64));
    CHECK(v.Z == Approx(264));
}

TEST_CASE("Lerp two Vector3s without clamping", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::LerpUnclamped(v1, v2, -0.2);
    CHECK(v.X == Approx(1.2));
    CHECK(v.Y == Approx(-6.4));
    CHECK(v.Z == Approx(6.4));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::LerpUnclamped(v1, v2, 0.33);
    CHECK(v.X == Approx(0.3357));
    CHECK(v.Y == Approx(-0.012062));
    CHECK(v.Z == Approx(-0.525));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::LerpUnclamped(v1, v2, 1.7);
    CHECK(v.X == Approx(80.1));
    CHECK(v.Y == Approx(-166.9));
    CHECK(v.Z == Approx(562.9));
}

TEST_CASE("Magnitude of a Vector3", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    CHECK(Vector3::Magnitude(v) == Approx(6.70820393));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    CHECK(Vector3::Magnitude(v) == Approx(0.242007));
    // Case 3
    v = Vector3(-27, 83, -163);
    CHECK(Vector3::Magnitude(v) == Approx(184.897269));
}

TEST_CASE("Max of Vector3s", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Max(v1, v2);
    CHECK(v.X == Approx(6));
    CHECK(v.Y == Approx(2));
    CHECK(v.Z == Approx(4));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Max(v1, v2);
    CHECK(v.X == Approx(0.53));
    CHECK(v.Y == Approx(0.0082));
    CHECK(v.Z == Approx(-0.03));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Max(v1, v2);
    CHECK(v.X == Approx(36));
    CHECK(v.Y == Approx(83));
    CHECK(v.Z == Approx(264));
}

TEST_CASE("Min of Vector3s", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Min(v1, v2);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    CHECK(v.Z == Approx(-8));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Min(v1, v2);
    CHECK(v.X == Approx(0.24));
    CHECK(v.Y == Approx(-0.0532));
    CHECK(v.Z == Approx(-1.53));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Min(v1, v2);
    CHECK(v.X == Approx(-27));
    CHECK(v.Y == Approx(-64));
    CHECK(v.Z == Approx(-163));
}

TEST_CASE("Move towards", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::MoveTowards(v1, v2, 1.7);
    CHECK(v.X == Approx(2.4703658354));
    CHECK(v.Y == Approx(-4.176859788));
    CHECK(v.Z == Approx(2.5889024937));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::MoveTowards(v1, v2, 2);
    CHECK(v.X == Approx(0.53));
    CHECK(v.Y == Approx(-0.0532));
    CHECK(v.Z == Approx(-1.53));
    // Case 3 (already at point)
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(-27, 83, -163);
    v = Vector3::MoveTowards(v1, v2, 1.8);
    CHECK(v.X == Approx(-27));
    CHECK(v.Y == Approx(83));
    CHECK(v.Z == Approx(-163));
}

TEST_CASE("Normalized Vector3", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    Vector3 n = Vector3::Normalized(v);
    CHECK(n.X == Approx(0.298142));
    CHECK(n.Y == Approx(-0.745356));
    CHECK(n.Z == Approx(0.596285));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    n = Vector3::Normalized(v);
    CHECK(n.X == Approx(0.991708));
    CHECK(n.Y == Approx(0.0338834));
    CHECK(n.Z == Approx(-0.123964));
    // Case 3
    v = Vector3(-27, 83, -163);
    n = Vector3::Normalized(v);
    CHECK(n.X == Approx(-0.146027));
    CHECK(n.Y == Approx(0.448898));
    CHECK(n.Z == Approx(-0.881571));
}

TEST_CASE("OrthoNormalize three Vector3s", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v3 = Vector3(7, -3, -1);
    Vector3::OrthoNormalize(v1, v2, v3);
    CHECK(Vector3::Angle(v1, v2) == Approx(M_PI / 2));
    CHECK(Vector3::Angle(v2, v3) == Approx(M_PI / 2));
    CHECK(Vector3::Angle(v3, v1) == Approx(M_PI / 2));
    CHECK(Vector3::Magnitude(v1) == Approx(1));
    CHECK(Vector3::Magnitude(v2) == Approx(1));
    CHECK(Vector3::Magnitude(v3) == Approx(1));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v3 = Vector3(-0.73, 0.624, 0.0346);
    Vector3::OrthoNormalize(v1, v2, v3);
    CHECK(Vector3::Angle(v1, v2) == Approx(M_PI / 2));
    CHECK(Vector3::Angle(v2, v3) == Approx(M_PI / 2));
    CHECK(Vector3::Angle(v3, v1) == Approx(M_PI / 2));
    CHECK(Vector3::Magnitude(v1) == Approx(1));
    CHECK(Vector3::Magnitude(v2) == Approx(1));
    CHECK(Vector3::Magnitude(v3) == Approx(1));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v3 = Vector3(-57, -46, 635);
    Vector3::OrthoNormalize(v1, v2, v3);
    CHECK(Vector3::Angle(v1, v2) == Approx(M_PI / 2));
    CHECK(Vector3::Angle(v2, v3) == Approx(M_PI / 2));
    CHECK(Vector3::Angle(v3, v1) == Approx(M_PI / 2));
    CHECK(Vector3::Magnitude(v1) == Approx(1));
    CHECK(Vector3::Magnitude(v2) == Approx(1));
    CHECK(Vector3::Magnitude(v3) == Approx(1));
}

TEST_CASE("Vector3 projection of a on b", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Project(v1, v2);
    CHECK(v.X == Approx(-1.7307692308));
    CHECK(v.Y == Approx(-0.5769230769));
    CHECK(v.Z == Approx(2.3076923077));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Project(v1, v2);
    CHECK(v.X == Approx(0.03487));
    CHECK(v.Y == Approx(-0.0035));
    CHECK(v.Z == Approx(-0.10065));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Project(v1, v2);
    CHECK(v.X == Approx(-23.6439377797));
    CHECK(v.Y == Approx(42.0336671639));
    CHECK(v.Z == Approx(-173.3888770509));
}

TEST_CASE("Vector3 projection on plane", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::ProjectOnPlane(v1, v2);
    CHECK(v.X == Approx(3.7307692308));
    CHECK(v.Y == Approx(-4.4230769231));
    CHECK(v.Z == Approx(1.6923076923));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::ProjectOnPlane(v1, v2);
    CHECK(v.X == Approx(0.2051334533));
    CHECK(v.Y == Approx(0.0116998119));
    CHECK(v.Z == Approx(0.0706524838));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::ProjectOnPlane(v1, v2);
    CHECK(v.X == Approx(-3.3560622203));
    CHECK(v.Y == Approx(40.9663328361));
    CHECK(v.Z == Approx(10.3888770509));
}

TEST_CASE("Vector3 reflect off plane", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Reflect(v1, v2);
    CHECK(v.X == Approx(5.4615384615));
    CHECK(v.Y == Approx(-3.8461538462));
    CHECK(v.Z == Approx(-0.6153846154));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Reflect(v1, v2);
    CHECK(v.X == Approx(0.1702669066));
    CHECK(v.Y == Approx(0.0151996237));
    CHECK(v.Z == Approx(0.1713049677));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Reflect(v1, v2);
    CHECK(v.X == Approx(20.2878755593));
    CHECK(v.Y == Approx(-1.0673343277));
    CHECK(v.Z == Approx(183.7777541019));
    // Case 4
    v1 = Vector3(1, 2, 3);
    v2 = Vector3(0, 1, 0);
    v = Vector3::Reflect(v1, v2);
    CHECK(v.X == Approx(1));
    CHECK(v.Y == Approx(-2));
    CHECK(v.Z == Approx(3));
}

TEST_CASE("Vector3 rejection", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Reject(v1, v2);
    CHECK(v.X == Approx(3.7307692308));
    CHECK(v.Y == Approx(-4.4230769231));
    CHECK(v.Z == Approx(1.6923076923));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Reject(v1, v2);
    CHECK(v.X == Approx(0.2051334533));
    CHECK(v.Y == Approx(0.0116998119));
    CHECK(v.Z == Approx(0.0706524838));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Reject(v1, v2);
    CHECK(v.X == Approx(-3.3560622203));
    CHECK(v.Y == Approx(40.9663328361));
    CHECK(v.Z == Approx(10.3888770509));
}

TEST_CASE("Vector3 rotate towards", "[Vector3]")
{
    // Identical vectors rotate towards
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(2, -5, 4);
    Vector3 v = Vector3::RotateTowards(v1, v2, 0.5, 3);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    CHECK(v.Z == Approx(4));
    // Opposite vectors rotate away
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = -v1;
    v = Vector3::RotateTowards(v1, v2, -0.5, 2);
    CHECK(v.X == Approx(0.24));
    CHECK(v.Y == Approx(0.0082));
    CHECK(v.Z == Approx(-0.03));
    // Identical vectors rotate away
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(-27, 83, -163);
    v = Vector3::RotateTowards(v1, v2, -0.2, 1);
    CHECK(v.X == Approx(-27));
    CHECK(v.Y == Approx(48.9624250412));
    CHECK(v.Z == Approx(-176.2404066441));
    // Rotate without change in magnitude
    v1 = Vector3(1, 0, 0);
    v2 = Vector3(0, -3, 0);
    v = Vector3::RotateTowards(v1, v2, M_PI_4 , 0);
    CHECK(v.X == Approx(0.7071067812));
    CHECK(v.Y == Approx(-0.7071067812));
    CHECK(v.Z == Approx(0));
    // Rotate and change in magnitude
    v1 = Vector3(1, 0, 0);
    v2 = Vector3(0, 5, 0);
    v = Vector3::RotateTowards(v1, v2, M_PI_4 , 2);
    CHECK(v.X == Approx(2.1213203436));
    CHECK(v.Y == Approx(2.1213203436));
    CHECK(v.Z == Approx(0));
    // Rotate and negative change in magnitude
    v1 = Vector3(5, 0, 0);
    v2 = Vector3(0, 1, 0);
    v = Vector3::RotateTowards(v1, v2, M_PI_4 , 2);
    CHECK(v.X == Approx(2.1213203436));
    CHECK(v.Y == Approx(2.1213203436));
    CHECK(v.Z == Approx(0));
    // Clamp magnitude with max
    v1 = Vector3(1, 0, 0);
    v2 = Vector3(0, 5, 0);
    v = Vector3::RotateTowards(v1, v2, M_PI_4 , 10);
    CHECK(v.X == Approx(3.535533906));
    CHECK(v.Y == Approx(3.535533906));
    CHECK(v.Z == Approx(0));
    // Clamp magnitude with min
    v1 = Vector3(5, 0, 0);
    v2 = Vector3(0, 1, 0);
    v = Vector3::RotateTowards(v1, v2, M_PI_4 , 10);
    CHECK(v.X == Approx(0.7071067812));
    CHECK(v.Y == Approx(0.7071067812));
    CHECK(v.Z == Approx(0));
    // Clamp angle max
    v1 = Vector3(2, -5, 4);
    v2 = Vector3(6, 2, -8);
    v = Vector3::RotateTowards(v1, v2, M_PI , 0);
    CHECK(v.X == Approx(3.946761086));
    CHECK(v.Y == Approx(1.315587029));
    CHECK(v.Z == Approx(-5.262348114));
    // Clamp angle min
    v1 = Vector3(2, -5, 4);
    v2 = Vector3(6, 2, -8);
    v = Vector3::RotateTowards(v1, v2, 0 , 0);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    CHECK(v.Z == Approx(4));
}

TEST_CASE("Scale Vector3", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Scale(v1, v2);
    CHECK(v.X == Approx(12));
    CHECK(v.Y == Approx(-10));
    CHECK(v.Z == Approx(-32));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Scale(v1, v2);
    CHECK(v.X == Approx(0.1272));
    CHECK(v.Y == Approx(-0.00043624));
    CHECK(v.Z == Approx(0.0459));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Scale(v1, v2);
    CHECK(v.X == Approx(-972));
    CHECK(v.Y == Approx(-5312));
    CHECK(v.Z == Approx(-43032));
}

TEST_CASE("Slerp two Vector3s with clamping", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::Slerp(v1, v2, -0.2);
    CHECK(v.X == Approx(2));
    CHECK(v.Y == Approx(-5));
    CHECK(v.Z == Approx(4));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::Slerp(v1, v2, 0.33);
    CHECK(v.X == Approx(0.6141718));
    CHECK(v.Y == Approx(0.008699415));
    CHECK(v.Z == Approx(-0.328942));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::Slerp(v1, v2, 1.7);
    CHECK(v.X == Approx(36));
    CHECK(v.Y == Approx(-64));
    CHECK(v.Z == Approx(264));
}

TEST_CASE("Slerp two Vector3s without clamping", "[Vector3]")
{
    // Case 1
    Vector3 v1 = Vector3(2, -5, 4);
    Vector3 v2 = Vector3(6, 2, -8);
    Vector3 v = Vector3::SlerpUnclamped(v1, v2, -0.2);
    CHECK(v.X == Approx(-0.2476361));
    CHECK(v.Y == Approx(-3.772974));
    CHECK(v.Z == Approx(4.671862));
    // Case 2
    v1 = Vector3(0.24, 0.0082, -0.03);
    v2 = Vector3(0.53, -0.0532, -1.53);
    v = Vector3::SlerpUnclamped(v1, v2, 0.33);
    CHECK(v.X == Approx(0.6141718));
    CHECK(v.Y == Approx(0.008699415));
    CHECK(v.Z == Approx(-0.328942));
    // Case 3
    v1 = Vector3(-27, 83, -163);
    v2 = Vector3(36, -64, 264);
    v = Vector3::SlerpUnclamped(v1, v2, 1.7);
    CHECK(v.X == Approx(3.913376));
    CHECK(v.Y == Approx(-255.0197));
    CHECK(v.Z == Approx(-219.3645));
}

TEST_CASE("Square magnitude of a Vector3", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    CHECK(Vector3::SqrMagnitude(v) == Approx(45));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    CHECK(Vector3::SqrMagnitude(v) == Approx(0.05856738));
    // Case 3
    v = Vector3(-27, 83, -163);
    CHECK(Vector3::SqrMagnitude(v) == Approx(34187));
}

TEST_CASE("To Spherical coordinate space", "[Vector3]")
{
    // Case 1
    Vector3 v = Vector3(2, -5, 4);
    double rad, theta, phi;
    Vector3::ToSpherical(v, rad, theta, phi);
    CHECK(rad == Approx(6.7082));
    CHECK(theta == Approx(0.931931));
    CHECK(phi == Approx(-1.19029));
    // Case 2
    v = Vector3(0.24, 0.0082, -0.03);
    Vector3::ToSpherical(v, rad, theta, phi);
    CHECK(rad == Approx(0.242007));
    CHECK(theta == Approx(1.69508));
    CHECK(phi == Approx(0.0341533));
    // Case 3
    v = Vector3(-27, 83, -163);
    Vector3::ToSpherical(v, rad, theta, phi);
    CHECK(rad == Approx(184.8972));
    CHECK(theta == Approx(2.6499755));
    CHECK(phi == Approx(1.8853006));
}
