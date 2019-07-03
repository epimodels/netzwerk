# netzwerk
A project wrapping modern C++ with Python using setuptools, CMake, pybind11, and GoogleTest

### How does it work?
CMake provides cross-platform compilation of C++ projects with a variety of compilers (e.g., gcc, clang, Apple clang, and MSVC). Building and linking the pybind11 and GoogleTest headers is included in our `CMakeLists.txt` build file. The file is run by the `setup.py` file, which uses `setuptools` to specify the Python building process. Compiling the C++ code, linking it to Python, and running C++ and Python tests are all accomplished by running a single command:

`python setup.py test`

While C++ tests are specified using GoogleTest, Python tests utilize the included `unittest` library.

### Why pybind11?

Wrapping modern C++ code in Python provides high-level high-performance code, a sort of [have-your-cake-and-eat-it](https://en.wikipedia.org/wiki/You_can%27t_have_your_cake_and_eat_it) for programmers.

### At what cost?
Added complexity and code duplication, which pybind11 minimizes compared to other approaches.
