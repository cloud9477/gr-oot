/* -*- c++ -*- */
/*
 * Copyright 2022 Zelin Yun.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "multiply_impl.h"

namespace gr {
  namespace oot {
    multiply::sptr
    multiply::make()
    {
      return gnuradio::make_block_sptr<multiply_impl>(
        );
    }

    multiply_impl::multiply_impl()
      : gr::block("multiply",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
    {}

    multiply_impl::~multiply_impl()
    {}

    void
    multiply_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      gr_vector_int::size_type ninputs = ninput_items_required.size();
      for(int i=0; i < ninputs; i++)
      {
	      ninput_items_required[i] = noutput_items;
      }
    }

    int
    multiply_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const float* in = static_cast<const float*>(input_items[0]);
      float* out = static_cast<float*>(output_items[0]);

      for(int i=0;i<noutput_items;i++)
      {
        out[i] = in[i] * 2.0f;  
      }

      consume_each (noutput_items);
      return noutput_items;
    }

  } /* namespace oot */
} /* namespace gr */
