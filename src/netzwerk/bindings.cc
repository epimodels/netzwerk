#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "ops.h"

namespace py = pybind11;


PYBIND11_MODULE(netzwerk, m)
{
  m.doc() = "pybind11 netzwerk plugin"; // optional module docstring
  #ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
  #else
    m.attr("__version__") = "dev";
  #endif
  m.def("add", &add, "A function that adds two numbers",
    py::arg("i"), py::arg("j"));
  //m.def("add", &add<float>, "A function that adds two numbers",
  //  py::arg("i"), py::arg("j"));
  //m.def("add", &add<double>, "A function that adds two numbers",
  //  py::arg("i"), py::arg("j"));
  // subtract
  m.def("subtract", &subtract, "A function that subtracts one number from another",
    py::arg("i"), py::arg("j"));
  //m.def("subtract", &subtract<float>, "A function that subtracts one number from another",
  //  py::arg("i"), py::arg("j"));
  //m.def("subtract", &subtract<double>, "A function that subtracts one number from another",
  //  py::arg("i"), py::arg("j"));
  // square
  m.def("square", py::vectorize(square), "A vectorized square function.");
}
