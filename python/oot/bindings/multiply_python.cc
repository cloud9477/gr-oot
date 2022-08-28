/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(multiply.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(fa74e7224c2e5807d76b50b1e9c8e367)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/oot/multiply.h>
// pydoc.h is automatically generated in the build directory
#include <multiply_pydoc.h>

void bind_multiply(py::module& m)
{

    using multiply    = gr::oot::multiply;


    py::class_<multiply, gr::block, gr::basic_block,
        std::shared_ptr<multiply>>(m, "multiply", D(multiply))

        .def(py::init(&multiply::make),
           D(multiply,make)
        )
        



        ;




}







