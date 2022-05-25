/* -*- c++ -*- */
/*
 * Copyright 2022 Zelin Yun.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_OOT_MULTIPLY_H
#define INCLUDED_OOT_MULTIPLY_H

#include <oot/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace oot {

    /*!
     * \brief <+description of block+>
     * \ingroup oot
     *
     */
    class OOT_API multiply : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<multiply> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of oot::multiply.
       *
       * To avoid accidental use of raw pointers, oot::multiply's
       * constructor is in a private implementation
       * class. oot::multiply::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace oot
} // namespace gr

#endif /* INCLUDED_OOT_MULTIPLY_H */
