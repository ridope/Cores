#!/usr/bin/env python3
from migen import *
#from migen.build.generic_platform import *
from litex.build.generic_platform import *
from litex.build.altera import AlteraPlatform
from litex.build.altera.programmer import USBBlaster



#IOs definition
_io = [
	#50 Mhz clock
    ("clk50",  0, Pins("N14"), IOStandard("3.3-V LVTTL")),
    
	#Leds
    ("user_led", 0, Pins("A8"), IOStandard("3.3-V LVTTL")),




]

#Platform def
class Platform(AlteraPlatform):
    default_clk_name = "clk50"	#default clk
    default_clk_period = 1e9/50e6
    create_rbf = False

    def __init__(self):
        AlteraPlatform.__init__(self, "10M50DAF484C7G", _io) #FPGA type

    def create_programmer(self):
        return USBBlaster()
#
# design
#


# create our platform (fpga interface)
platform = Platform()

# create our module (fpga description)
class Blink(Module):
    def __init__(self, blink_freq, sys_clk_freq, led):
        counter = Signal(32)     
        # synchronous assignments
        self.sync += [
            counter.eq(counter + 1),
            If(counter == int((sys_clk_freq/blink_freq)/2 - 1),
                counter.eq(0),
                led.eq(~led)
            )
        ]
        # combinatorial assignements
        self.comb += []

module = Blink(1, 100e6, platform.request("user_led"))

#
# build
#

platform.build(module)
