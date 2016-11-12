# GMath

This is a lightweight C++ math library aimed at geometry math problems (Vectors, Quaternions and Matrices). It contains implementations of nearly every geometry math function found in the Unity game engine as well as many others. Additionally, it is a header only library and is written so that any of the files (Vector3, Quaternion, etc.) can be used individually without the need for the rest of the library.

## Code Examples

This example takes a vector and rotates it by a quaternion. The quaternion is created by spherical-linear interpolation between two other quaternions.

```
#include "Vector3.hpp"
#include "Quaternion.hpp"

Vector3 vec = Vector3(1, 2, 3);
Quaternion quat1 = Quaternion::Identity();
Quaternion quat2 = Quaternion::FromAngleAxis(3.141592, Vector3::Up());
Quaternion quat = Quaternion::Slerp(quat1, quat2, 0.3);
Vector3 newVec = quat * vec;
 ```
 
This example takes the Euler angle representation of a rotation, converts it to a quaternion, then converts it to a rotation matrix, and finally rotates a vector using that matrix.

```
#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "Matrix3x3.hpp"

Vector3 eulerRot = Vector3(12, -3.4, 7);
Quaternion quatRot = Quaternion::FromEuler(eulerRot);
Matrix3x3 matRot = Matrix3x3::FromQuaternion(quatRot);
Vector3 newVec = matRot * Vector3::Forward();
```
 
## Getting Started

Using GMath is super simple! Since it is a header only library, there is no extra setup, and the "hpp" files are all that's needed.

1. Clone the repo or download a zip of it.
2. Copy the "hpp" files you want to use from src/ into your project.

## Tests

GMath includes a full set of test cases for every function. You must have Make and a command line C++ compiler to build and run the tests. Once these are installed, simply use the following commands to build, run, and clean the unit tests.

```
# Build the unit tests
make
# Run the unit tests
bin/GMathTest.app
# Clean the project
make clean
```

## Authors

* **Eric Phillips** - *Initial work* - [YclepticStudios](https://github.com/YclepticStudios)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
