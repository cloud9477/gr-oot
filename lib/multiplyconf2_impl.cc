/* -*- c++ -*- */
/*
 * Copyright 2022 Zelin Yun.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "multiplyconf2_impl.h"

namespace gr {
  namespace oot {
    using input_type = float;
    using output_type = float;
    multiplyconf2::sptr
    multiplyconf2::make(float m1, float m2)
    {
      return gnuradio::make_block_sptr<multiplyconf2_impl>(m1, m2
        );
    }


    /*
     * The private constructor
     */
    multiplyconf2_impl::multiplyconf2_impl(float m1, float m2)
      : gr::block("multiplyconf2",
              gr::io_signature::make(1, 1, sizeof(input_type)),
              gr::io_signature::make(2, 2, sizeof(output_type))),
              d_multiplier1(m1),
              d_multiplier2(m2)
    {}

    /*
     * Our virtual destructor.
     */
    multiplyconf2_impl::~multiplyconf2_impl()
    {
    }

    void
    multiplyconf2_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      gr_vector_int::size_type ninputs = ninput_items_required.size();
      for(gr_vector_int::size_type i=0; i < ninputs; i++)
      {
	      ninput_items_required[i] = noutput_items;
      }
    }

    int
    multiplyconf2_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      auto in = static_cast<const input_type*>(input_items[0]);
      auto out1 = static_cast<output_type*>(output_items[0]);
      auto out2 = static_cast<output_type*>(output_items[1]);

      // Do <+signal processing+>
      for(int i=0;i<noutput_items;i++)
      {
        out1[i] = in[i] * d_multiplier1;
        out2[i] = in[i] * d_multiplier2;
      }
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace oot */
} /* namespace gr */
