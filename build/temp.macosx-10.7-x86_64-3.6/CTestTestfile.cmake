# CMake generated Testfile for 
# Source directory: /Users/null/dev/netzwerk
# Build directory: /Users/null/dev/netzwerk/build/temp.macosx-10.7-x86_64-3.6
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test1 "/Users/null/dev/netzwerk/build/temp.macosx-10.7-x86_64-3.6/netzwerk_test")
set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "/Users/null/dev/netzwerk/CMakeLists.txt;74;add_test;/Users/null/dev/netzwerk/CMakeLists.txt;0;")
subdirs("lib/pybind11")
subdirs("lib/googletest")
