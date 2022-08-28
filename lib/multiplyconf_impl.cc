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
    using input_type = float;
    using output_type = float;
    multiplyconf::sptr
    multiplyconf::make(float m)
    {
      return gnuradio::make_block_sptr<multiplyconf_impl>(m
        );
    }


    /*
     * The private constructor
     */
    multiplyconf_impl::multiplyconf_impl(float m)
      : gr::block("multiplyconf",
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
              d_multiplier(m)
    {}

    /*
     * Our virtual destructor.
     */
    multiplyconf_impl::~multiplyconf_impl()
    {
    }

    void
    multiplyconf_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      gr_vector_int::size_type ninputs = ninput_items_required.size();
      for(gr_vector_int::size_type i=0; i < ninputs; i++)
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
      auto in = static_cast<const input_type*>(input_items[0]);
      auto out = static_cast<output_type*>(output_items[0]);

      // Do <+signal processing+>
      for(int i=0;i<noutput_items;i++)
      {
        out[i] = in[i] * d_multiplier;
      }
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace oot */
} /* namespace gr */
