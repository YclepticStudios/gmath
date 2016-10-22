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
 *  This file implements the base interactions among all vector and matrix
 *  types. This includes basic operator overloading, some simple identity values
 *  and any functions which can operate on arbitrarily sized vectors/matrices.
 *
 *  Created by Eric Phillips on October 16, 2016.
 */

#pragma once

#define NUMARGS(...) (sizeof((int[]){__VA_ARGS__})/sizeof(int))
#define Core(...) Core::CreateCore(NUMARGS(__VA_ARGS__), __VA_ARGS__)
#define Core(...) Core<__VA_ARGS__>()


template<unsigned int... N>
struct Core2
{
    int Dimensions;
    int Length;
    void *data;


    /**
     * Constructors.
     * NOTE: Use the "Core" macro defined above. It can be used as a generic
     * constructor and automatically populates the number of arguments.
     */
    static Core2 CreateCore(int numArgs, ...)
    {
        Core2 c;
        c.Dimensions = numArgs;
        c.Length = 3;
        return c;
    }

    Core2 operator [](int index)
    {
        return ((Core2*)data)[index];
    }

    operator T() const { return ((T*)data)[0]; }
};




template<unsigned ... RestD>
struct Core
{

};

template<unsigned PrimaryD>
struct Core<PrimaryD>
{
    typedef double Type[PrimaryD];
    private: Type _data;

    double& operator[](unsigned idx) { return _data[idx]; }
};

template<unsigned PrimaryD, unsigned ... RestD >
struct Core<PrimaryD, RestD...>
{
    typedef typename Core<RestD...>::Type OneDimensionDownT;
    typedef OneDimensionDownT Type[PrimaryD];
    private: Type _data;

    OneDimensionDownT& operator[](unsigned idx) { return _data[idx]; }
};

int main()
{
    auto c = Core(1, 4, 2);
    Core<2, 3>::Type a4 = { { 1, 2, 3}, { 1, 2, 3} };
    Core<2, 3> a5{ { { 1, 2, 3}, { 4, 5, 6} } };
    std::cout << a5[1][2] << std::endl;

    Core<3> a6{ {1, 2, 3} };
    std::cout << a6[1] << std::endl;

    Core<1, 2, 3> a7{ { { { 1, 2, 3}, { 4, 5, 6 } } }};
    std::cout << a7[0][1][2] << std::endl;
}
