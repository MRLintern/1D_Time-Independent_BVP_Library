## 1D Boundary Value Problem Library

An Object Oriented Designed Library to solve 1D Boundary Value Problems (BVP) called `bvplib.hpp`

The type of BVP is 1D and time independent.

The differential equation is discretized using a Finite Difference Method.
The resulting system of algebraic equations are solved via Gaussian elimination.

The typical form of a BVP:

    Au''(x) + Bu'(x) + Cu(x) = f(x), X_0 < x < X_1.

`A`, `B` and `C` are coefficients; specified by the user. 

`f(x)` is the source function.

`u''(x)` is the 2nd derivative w.r.t.x.

`u'(x)` is the 1st derivative w.r.t.x.

`u(x)` is the solution.

`X_0 < x < X_1` is the interval in which the differential equation is discretized.

Boundary conditions: `x = X_0` & `x = X_1`; specified by the user.

## Requirements

1. Compiler: `gcc/g++`.`9.4.0` was used to allow for further development in a newer standard: e.g. `C++17`.
2. `CMake`; build generator 
3. `ninja-build`; build tool which depends on `CMake`.
4. `conan`. Used for package management; `fmt` and `spdlog`; https://conan.io/center/. `fmt` is used for formatting and `spdlog` is used for logging issues.
5. `Ubuntu 20.04`.
6. `make`.
7. `FetchContent` is used to get the contents from of `fmt` and `spdlog` for `CMake`. It comes with `CMake`.
8. Knowledge of `Numerical Linear Algebra`, `Numerical Differential Equations` & `Numerical Methods`.


## Example models

Two models are used.

Model 1:

    u''(x) = -1, 0 < x < 1,

with Dirichlet Conditions:

    u = 0 at x = 0 
    u = 0 at x = 1 

Model 2:

    u''(x) + 3*u'(x) - 4*u(x) = -34*sin*x, 0 < x < pi,

with Neumann conditions:

    u'(x) = -5, at x = 0
    u = 4, at x = pi

Two `.dat` files are generated, one each corresponding to one model problem. These can be used for plotting the solution.

## Instructions

Note: Don't leave spaces between commands and prompt.

1. `$ pip install conan`. Installing `conan`.
2. `$ source ~/.profile`. Needed as the directory won't be automatically appended to the PATH and conan commands won't work.
3. Clone the repository: `$ git clone https://github.com/MRLintern/1D_Time-Independent_BVP_Library.git`
4. `$ make prepare`. Used to create the build library and configure `conan`
5. `$ cd build`
6. `$ cmake ..`
7. `$ cmake --build .`
8. `$ cd build`
9. `$ ./Executable`

NOTE:

The user has to specify the boundary/initial conditions for the problem. To do this go to `main/main.cpp`.
You'll see that these have already been applied for Model 1 and Model 2 listed above.

## Further Development

1. Create unit tests; currently looking at using `catch2`. Consider using`GoogleTest` too. 
2. Consider developing the software in a newer modern standard; e.g. `C++17`.
   
## Issues: TODO

Software builds, compiles and runs but `.dat` solution files are not generated. 


