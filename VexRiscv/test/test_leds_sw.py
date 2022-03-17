#!/usr/bin/env python3

from migen import *
#from migen.build.generic_platform import *
from litex.build.generic_platform import *


# create our module (fpga description)
class SwitchLed(Module):
    def __init__(self, led, sw):   
        # synchronous assignments
        self.sync += []
        # combinatorial assignements
            self.comb += led.eq(sw)	#assign led to sw
