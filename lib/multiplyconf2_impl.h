/* -*- c++ -*- */
/*
 * Copyright 2022 Zelin Yun.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_OOT_MULTIPLYCONF2_IMPL_H
#define INCLUDED_OOT_MULTIPLYCONF2_IMPL_H

#include <gnuradio/oot/multiplyconf2.h>

namespace gr {
  namespace oot {

    class multiplyconf2_impl : public multiplyconf2
    {
     private:
      float d_multiplier1;
      float d_multiplier2;

     public:
      multiplyconf2_impl(float m1, float m2);
      ~multiplyconf2_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);

    };

  } // namespace oot
} // namespace gr

#endif /* INCLUDED_OOT_MULTIPLYCONF2_IMPL_H */
