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
 *  This file contains test cases for the Quaternion functions.
 *
 *  Created by Eric Phillips on October 21, 2016.
 */

#include "catch.hpp"
#include "Quaternion.hpp"


TEST_CASE("Quaternion plus scalar", "[Quaternion]")
{
    // Case 1
    Quaternion q = Quaternion(2, -5, 3, 7);
    q = q + 3;
    CHECK(q.X == Approx(5));
    CHECK(q.Y == Approx(-2));
    CHECK(q.Z == Approx(6));
    CHECK(q.W == Approx(10));
    // Case 2
    q = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q = q + 0.2;
    CHECK(q.X == Approx(0.44));
    CHECK(q.Y == Approx(0.2082));
    CHECK(q.Z == Approx(-0.1));
    CHECK(q.W == Approx(0.8));
    // Case 3
    q = Quaternion(-27, 83, 32, -153);
    q = q + 13;
    CHECK(q.X == Approx(-14));
    CHECK(q.Y == Approx(96));
    CHECK(q.Z == Approx(45));
    CHECK(q.W == Approx(-140));
}

TEST_CASE("Quaternion minus scalar", "[Quaternion]")
{
    // Case 1
    Quaternion q = Quaternion(2, -5, 3, 7);
    q = q - 3;
    CHECK(q.X == Approx(-1));
    CHECK(q.Y == Approx(-8));
    CHECK(q.Z == Approx(0));
    CHECK(q.W == Approx(4));
    // Case 2
    q = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q = q - 0.2;
    CHECK(q.X == Approx(0.04));
    CHECK(q.Y == Approx(-0.1918));
    CHECK(q.Z == Approx(-0.5));
    CHECK(q.W == Approx(0.4));
    // Case 3
    q = Quaternion(-27, 83, 32, -153);
    q = q - 13;
    CHECK(q.X == Approx(-40));
    CHECK(q.Y == Approx(70));
    CHECK(q.Z == Approx(19));
    CHECK(q.W == Approx(-166));
}

TEST_CASE("Quaternion times scalar", "[Quaternion]")
{
    // Case 1
    Quaternion q = Quaternion(2, -5, 3, 7);
    q = q * 3;
    CHECK(q.X == Approx(6));
    CHECK(q.Y == Approx(-15));
    CHECK(q.Z == Approx(9));
    CHECK(q.W == Approx(21));
    // Case 2
    q = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q = q * 0.2;
    CHECK(q.X == Approx(0.048));
    CHECK(q.Y == Approx(0.00164));
    CHECK(q.Z == Approx(-0.06));
    CHECK(q.W == Approx(0.12));
    // Case 3
    q = Quaternion(-27, 83, 32, -153);
    q = q * 13;
    CHECK(q.X == Approx(-351));
    CHECK(q.Y == Approx(1079));
    CHECK(q.Z == Approx(416));
    CHECK(q.W == Approx(-1989));
}

TEST_CASE("Quaternion divided by scalar", "[Quaternion]")
{
    // Case 1
    Quaternion q = Quaternion(2, -5, 3, 7);
    q = q / 3;
    CHECK(q.X == Approx(0.66666667));
    CHECK(q.Y == Approx(-1.66666667));
    CHECK(q.Z == Approx(1));
    CHECK(q.W == Approx(2.33333333));
    // Case 2
    q = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q = q / 0.2;
    CHECK(q.X == Approx(1.2));
    CHECK(q.Y == Approx(0.041));
    CHECK(q.Z == Approx(-1.5));
    CHECK(q.W == Approx(3));
    // Case 3
    q = Quaternion(-27, 83, 32, -153);
    q = q / 13;
    CHECK(q.X == Approx(-2.0769231));
    CHECK(q.Y == Approx(6.3846154));
    CHECK(q.Z == Approx(2.461538462));
    CHECK(q.W == Approx(-11.76923077));
}

TEST_CASE("Quaternion plus Quaternion", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(2, -5, 3, 7);
    Quaternion q2 = Quaternion(6, 2, -1, 9);
    Quaternion q = q1 + q2;
    CHECK(q.X == Approx(8));
    CHECK(q.Y == Approx(-3));
    CHECK(q.Z == Approx(2));
    CHECK(q.W == Approx(16));
    // Case 2
    q1 = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q2 = Quaternion(0.53, -0.0532, 0.22, 0.85);
    q = q1 + q2;
    CHECK(q.X == Approx(0.77));
    CHECK(q.Y == Approx(-0.045));
    CHECK(q.Z == Approx(-0.08));
    CHECK(q.W == Approx(1.45));
    // Case 3
    q1 = Quaternion(-27, 83, 32, -153);
    q2 = Quaternion(36, -64, 12, 24);
    q = q1 + q2;
    CHECK(q.X == Approx(9));
    CHECK(q.Y == Approx(19));
    CHECK(q.Z == Approx(44));
    CHECK(q.W == Approx(-129));
}

TEST_CASE("Quaternion minus Quaternion", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(2, -5, 3, 7);
    Quaternion q2 = Quaternion(6, 2, -1, 9);
    Quaternion q = q1 - q2;
    CHECK(q.X == Approx(-4));
    CHECK(q.Y == Approx(-7));
    CHECK(q.Z == Approx(4));
    CHECK(q.W == Approx(-2));
    // Case 2
    q1 = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q2 = Quaternion(0.53, -0.0532, 0.22, 0.85);
    q = q1 - q2;
    CHECK(q.X == Approx(-0.29));
    CHECK(q.Y == Approx(0.0614));
    CHECK(q.Z == Approx(-0.52));
    CHECK(q.W == Approx(-0.25));
    // Case 3
    q1 = Quaternion(-27, 83, 32, -153);
    q2 = Quaternion(36, -64, 12, 24);
    q = q1 - q2;
    CHECK(q.X == Approx(-63));
    CHECK(q.Y == Approx(147));
    CHECK(q.Z == Approx(20));
    CHECK(q.W == Approx(-177));
}

TEST_CASE("Quaternion times Quaternion", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(0.3919183, 0.3196269, -0.8430416, -0.1830837);
    Quaternion q2 = Quaternion(0.3535534, -0.1464466, 0.3535534, 0.8535535);
    Quaternion q = q1 * q2;
    CHECK(q.X == Approx(0.25933797330736996));
    CHECK(q.Y == Approx(-0.13699362693909));
    CHECK(q.Z == Approx(-0.9547112526844199));
    CHECK(q.W == Approx(0.050032716379809994));
    // Case 2
    q1 = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q2 = Quaternion(0.53, -0.0532, 0.22, 0.85);
    q = q1 * q2;
    CHECK(q.X == Approx(0.507844));
    CHECK(q.Y == Approx(-0.23675));
    CHECK(q.Z == Approx(-0.140114));
    CHECK(q.W == Approx(0.44923624));
    // Case 3
    q1 = Quaternion(0, 0.7071068, 0, 0.7071068);
    q2 = Quaternion(0, 0.7071068, 0, 0.7071068);
    q = q1 * q2;
    CHECK(q.X == Approx(0));
    CHECK(q.Y == Approx(1));
    CHECK(q.Z == Approx(0));
    CHECK(q.W == Approx(0));
}

TEST_CASE("Quaternion equality", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(2, -5, 3, 7);
    Quaternion q2 = Quaternion(6, 2, -1, 9);
    CHECK_FALSE(q1 == q2);
    // Case 2
    q1 = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q2 = Quaternion(0.24, 0.0082, -0.3, 0.6);
    CHECK(q1 == q2);
    // Case 3
    q1 = Quaternion(-27, 83, 32, -153);
    q2 = Quaternion(-27, 84, 32, -153);
    CHECK_FALSE(q1 == q2);
}

TEST_CASE("Quaternion inequality", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(2, -5, 3, 7);
    Quaternion q2 = Quaternion(6, 2, -1, 9);
    CHECK(q1 != q2);
    // Case 2
    q1 = Quaternion(0.24, 0.0082, -0.3, 0.6);
    q2 = Quaternion(0.24, 0.0082, -0.3, 0.6);
    CHECK_FALSE(q1 != q2);
    // Case 3
    q1 = Quaternion(-27, 83, 32, -153);
    q2 = Quaternion(-27, 84, 32, -153);
    CHECK(q1 != q2);
}

TEST_CASE("Angle between quaternions", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(0.3919183, 0.3196269, -0.8430416, -0.1830837);
    Quaternion q2 = Quaternion(0, 0.7071068, 0, 0.7071068);
    double a = Quaternion::Angle(q1, q2);
    CHECK(a == Approx(2.94819));
    // Case 2
    a = Quaternion::Angle(q2, q1);
    CHECK(a == Approx(2.94819));
    // Case 3
    q1 = Quaternion(0.3535534, -0.1464466, 0.3535534, 0.8535535);
    q2 = Quaternion(0.3919183, 0.3196269, -0.8430416, -0.1830837);
    a = Quaternion::Angle(q1, q2);
    CHECK(a == Approx(2.399531));
    // Case 4
    a = Quaternion::Angle(q1, q1);
    CHECK(a == Approx(0));
}

TEST_CASE("Quaternion conjugate", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(0.3919183, 0.3196269, -0.8430416, -0.1830837);
    Quaternion q = Quaternion::Conjugate(q1);
    CHECK(q.X == Approx(-0.3919183));
    CHECK(q.Y == Approx(-0.3196269));
    CHECK(q.Z == Approx(0.8430416));
    CHECK(q.W == Approx(-0.1830837));
    // Case 2
    q1 = Quaternion(0, 0.7071068, 0, 0.7071068);
    q = Quaternion::Conjugate(q1);
    CHECK(q.X == Approx(0));
    CHECK(q.Y == Approx(-0.7071068));
    CHECK(q.Z == Approx(0));
    CHECK(q.W == Approx(0.7071068));
    // Case 3
    q1 = Quaternion(0.3535534, -0.1464466, 0.3535534, 0.8535535);
    q = Quaternion::Conjugate(q1);
    CHECK(q.X == Approx(-0.3535534));
    CHECK(q.Y == Approx(0.1464466));
    CHECK(q.Z == Approx(-0.3535534));
    CHECK(q.W == Approx(0.8535535));
}

TEST_CASE("Dot product of quaternions", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(-27, 83, 32, -153);
    Quaternion q2 = Quaternion(36, -64, 12, 24);
    double a = Quaternion::Dot(q1, q2);
    CHECK(a == Approx(-9572));
    // Case 2
    a = Quaternion::Dot(q2, q1);
    CHECK(a == Approx(-9572));
    // Case 3
    q1 = Quaternion(0.3535534, -0.1464466, 0.3535534, 0.8535535);
    q2 = Quaternion(0.3919183, 0.3196269, -0.8430416, -0.1830837);
    a = Quaternion::Dot(q1, q2);
    CHECK(a == Approx(-0.362576186656952));
    // Case 4
    q1 = Quaternion(0, 0.7071068, 0, 0.7071068);
    q2 = Quaternion(0, 0.7071068, 0, 0.7071068);
    a = Quaternion::Dot(q1, q1);
    CHECK(a == Approx(1.0));
}

TEST_CASE("Quaternion from angle axis", "[Quaternion]")
{
    // Case 1
    double angle = 0.7;
    Vector3 axis = Vector3(1, 2, 3);
    Quaternion q = Quaternion::FromAngleAxis(angle, axis);
    CHECK(q.X == Approx(0.09164329));
    CHECK(q.Y == Approx(0.1832866));
    CHECK(q.Z == Approx(0.2749299));
    CHECK(q.W == Approx(0.9393727));
    // Case 2
    angle = 3.14159265;
    axis = Vector3(0, 0, 1);
    q = Quaternion::FromAngleAxis(angle, axis);
    CHECK(q.X == Approx(0));
    CHECK(q.Y == Approx(0));
    CHECK(q.Z == Approx(1));
    CHECK(q.W == Approx(0));
    // Case 2
    angle = -9.24;
    axis = Vector3(-1, 0.4, 2.9);
    q = Quaternion::FromAngleAxis(angle, axis);
    CHECK(q.X == Approx(-0.3218755));
    CHECK(q.Y == Approx(0.1287502));
    CHECK(q.Z == Approx(0.9334388));
    CHECK(q.W == Approx(-0.09225724));
}

TEST_CASE("Quaternion from euler angles", "[Quaternion]")
{
    // Case 1
    Vector3 axis = Vector3(0.8, 1.4, 2.6);
    Quaternion q = Quaternion::FromEuler(axis);
    CHECK(q.X == Approx(0.6514133));
    CHECK(q.Y == Approx(-0.1282655));
    CHECK(q.Z == Approx(0.6116868));
    CHECK(q.W == Approx(0.430172));
    // Case 2
    q = Quaternion::FromEuler(0, 0, 3.14159265);
    CHECK(q.X == Approx(0));
    CHECK(q.Y == Approx(0));
    CHECK(q.Z == Approx(1));
    CHECK(q.W == Approx(0));
    // Case 2
    axis = Vector3(-1, 0.4, 2.9);
    q = Quaternion::FromEuler(axis);
    CHECK(q.X == Approx(0.1164578));
    CHECK(q.Y == Approx(0.4874545));
    CHECK(q.Z == Approx(0.8652994));
    CHECK(q.W == Approx(0.009090029));
}

TEST_CASE("Quaternion inverse", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(0.3919183, 0.3196269, -0.8430416, -0.1830837);
    Quaternion q = Quaternion::Inverse(q1);
    CHECK(q.X == Approx(-0.3919183));
    CHECK(q.Y == Approx(-0.3196269));
    CHECK(q.Z == Approx(0.8430416));
    CHECK(q.W == Approx(-0.1830837));
    // Case 2
    q1 = Quaternion(0.4, 0.2, -1.3, -0.5);
    q = Quaternion::Inverse(q1);
    CHECK(q.X == Approx(-0.1869158879));
    CHECK(q.Y == Approx(-0.0934579439));
    CHECK(q.Z == Approx(0.6074766355));
    CHECK(q.W == Approx(-0.2336448598));
    // Case 3
    q1 = Quaternion(0.3535534, -0.1464466, 0.3535534, 0.8535535);
    q = Quaternion::Inverse(q1);
    CHECK(q.X == Approx(-0.3535534));
    CHECK(q.Y == Approx(0.1464466));
    CHECK(q.Z == Approx(-0.3535534));
    CHECK(q.W == Approx(0.8535535));
}

TEST_CASE("Quaternion norm", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(0.3919183, 0.3196269, -0.8430416, -0.1830837);
    double n = Quaternion::Norm(q1);
    CHECK(n == Approx(1));
    // Case 2
    q1 = Quaternion(0, 0.7071068, 0, 0.7071068);
    n = Quaternion::Norm(q1);
    CHECK(n == Approx(1));
    // Case 3
    q1 = Quaternion(0.3535534, -0.1464466, 0.3535534, 0.8535535);
    n = Quaternion::Norm(q1);
    CHECK(n == Approx(1));
}

TEST_CASE("Quaternion normalized", "[Quaternion]")
{
    // Case 1
    Quaternion q1 = Quaternion(0.4, 0.2, -1.3, -0.5);
    Quaternion q = Quaternion::Normalized(q1);
    CHECK(q.X == Approx(0.2734343708));
    CHECK(q.Y == Approx(0.1367171854));
    CHECK(q.Z == Approx(-0.888661705));
    CHECK(q.W == Approx(-0.3417929635));
    // Case 2
    q1 = Quaternion(0, 0, 0, 0.2);
    q = Quaternion::Normalized(q1);
    CHECK(q.X == Approx(0));
    CHECK(q.Y == Approx(0));
    CHECK(q.Z == Approx(0));
    CHECK(q.W == Approx(1));
    // Case 3
    q1 = Quaternion(0.5, 0.5, -0.5, 0.5);
    q = Quaternion::Normalized(q1);
    CHECK(q.X == Approx(0.5));
    CHECK(q.Y == Approx(0.5));
    CHECK(q.Z == Approx(-0.5));
    CHECK(q.W == Approx(0.5));
}
