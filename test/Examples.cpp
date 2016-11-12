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
 *  This file contains random examples written in the form of test cases.
 *
 *  Created by Eric Phillips on November 12, 2016.
 */

#include "catch.hpp"
#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "Matrix3x3.hpp"


TEST_CASE("Generic example", "[Example]")
{
    Vector3 vec = Vector3(1, 2, 3);
    double angle = 3.141592;
    Vector3 axis = Vector3::Up();
    Quaternion quat = Quaternion::FromAngleAxis(angle, axis);
    Vector3 newVec = quat * vec;
}

TEST_CASE("Generic example 2", "[Example]")
{
    Vector3 vec = Vector3(1, 2, 3);
    Quaternion quat1 = Quaternion::Identity();
    Quaternion quat2 = Quaternion::FromAngleAxis(3.141592, Vector3::Up());
    Quaternion quat = Quaternion::Slerp(quat1, quat2, 0.3);
    Vector3 newVec = quat * vec;
}

TEST_CASE("Type conversions", "[Example]")
{
    Vector3 eulerRot = Vector3(12, -3.4, 7);
    Quaternion quatRot = Quaternion::FromEuler(eulerRot);
    Matrix3x3 matRot = Matrix3x3::FromQuaternion(quatRot);
    Vector3 newVec = matRot * Vector3::Forward();
}
