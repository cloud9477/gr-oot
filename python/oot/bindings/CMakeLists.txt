# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT oot_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT oot_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND oot_python_files
    multiply_python.cc
    multiplyconf_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(oot
   ../../..
   gr::oot
   "${oot_python_files}")

# copy in bindings .so file for use in QA test module
add_custom_target(
  copy_bindings_for_tests ALL
  COMMAND
    ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/*.so"
    ${CMAKE_BINARY_DIR}/test_modules/gnuradio/oot/
  DEPENDS oot_python)

install(TARGETS oot_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/oot COMPONENT pythonapi)
