/* -*- c++ -*- */
/*
 * Copyright 2022 Zelin Yun.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_OOT_MULTIPLYCONF2_H
#define INCLUDED_OOT_MULTIPLYCONF2_H

#include <gnuradio/oot/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace oot {

    /*!
     * \brief <+description of block+>
     * \ingroup oot
     *
     */
    class OOT_API multiplyconf2 : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<multiplyconf2> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of oot::multiplyconf2.
       *
       * To avoid accidental use of raw pointers, oot::multiplyconf2's
       * constructor is in a private implementation
       * class. oot::multiplyconf2::make is the public interface for
       * creating new instances.
       */
      static sptr make(float m1, float m2);
    };

  } // namespace oot
} // namespace gr

#endif /* INCLUDED_OOT_MULTIPLYCONF2_H */
