/* -*- c++ -*- */
/*
 * Copyright 2022 Zelin Yun.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_OOT_MULTIPLYCONF_H
#define INCLUDED_OOT_MULTIPLYCONF_H

#include <gnuradio/oot/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace oot {

    /*!
     * \brief <+description of block+>
     * \ingroup oot
     *
     */
    class OOT_API multiplyconf : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<multiplyconf> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of oot::multiplyconf.
       *
       * To avoid accidental use of raw pointers, oot::multiplyconf's
       * constructor is in a private implementation
       * class. oot::multiplyconf::make is the public interface for
       * creating new instances.
       */
      static sptr make(float m);
    };

  } // namespace oot
} // namespace gr

#endif /* INCLUDED_OOT_MULTIPLYCONF_H */
