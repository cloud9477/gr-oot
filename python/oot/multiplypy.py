#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2022 Zelin Yun.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#


import numpy
from gnuradio import gr

class multiplypy(gr.basic_block):
    """
    docstring for block multiplypy
    """
    def __init__(self, m = 1.0):
        self.multiplier = m
        gr.basic_block.__init__(self,
            name="multiplypy",
            in_sig=[numpy.float32, ],
            out_sig=[numpy.float32, ])

    def forecast(self, noutput_items, ninputs):
        # ninputs is the number of input connections
        # setup size of input_items[i] for work call
        # the required number of input items is returned
        #   in a list where each element represents the
        #   number of required items for each input
        ninput_items_required = [noutput_items] * ninputs
        return ninput_items_required

    def general_work(self, input_items, output_items):
        # For this sample code, the general block is made to behave like a sync block
        ninput_items = min([len(items) for items in input_items])
        noutput_items = min(len(output_items[0]), ninput_items)
        output_items[0][:noutput_items] = [each * self.multiplier for each in input_items[0][:noutput_items]]
        self.consume_each(noutput_items)
        return noutput_items

