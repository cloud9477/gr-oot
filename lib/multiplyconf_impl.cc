/* -*- c++ -*- */
/*
 * Copyright 2022 Zelin Yun.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "multiplyconf_impl.h"

namespace gr {
  namespace oot {
    multiplyconf::sptr
    multiplyconf::make(float m)
    {
      return gnuradio::make_block_sptr<multiplyconf_impl>(m
        );
    }

    multiplyconf_impl::multiplyconf_impl(float m)
      : gr::block("multiplyconf",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float))),
              d_multiplier(m)
    {}

    multiplyconf_impl::~multiplyconf_impl()
    {}

    void
    multiplyconf_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      gr_vector_int::size_type ninputs = ninput_items_required.size();
      for(int i=0; i < ninputs; i++)
      {
	      ninput_items_required[i] = noutput_items;
      }
    }

    int
    multiplyconf_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const float* in = static_cast<const float*>(input_items[0]);
      float* out = static_cast<float*>(output_items[0]);

      for(int i=0;i<noutput_items;i++)
      {
        out[i] = in[i] * d_multiplier;  
      }

      consume_each (noutput_items);
      return noutput_items;
    }

  } /* namespace oot */
} /* namespace gr */
