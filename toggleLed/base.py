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
    ("user_led", 1, Pins("A9"), IOStandard("3.3-V LVTTL")),
    ("user_led", 2, Pins("A10"), IOStandard("3.3-V LVTTL")),
    ("user_led", 3, Pins("B10"), IOStandard("3.3-V LVTTL")),
    ("user_led", 4, Pins("D13"), IOStandard("3.3-V LVTTL")),
    ("user_led", 5, Pins("C13"), IOStandard("3.3-V LVTTL")),
    ("user_led", 6, Pins("E14"), IOStandard("3.3-V LVTTL")),
    ("user_led", 7, Pins("D14"), IOStandard("3.3-V LVTTL")),
    ("user_led", 8, Pins("A11"), IOStandard("3.3-V LVTTL")),
    ("user_led", 9, Pins("B11"), IOStandard("3.3-V LVTTL")),

	#Switches
    ("user_switch", 0, Pins("C10"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 1, Pins("C11"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 2, Pins("D12"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 3, Pins("C12"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 4, Pins("A12"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 5, Pins("B12"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 6, Pins("A13"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 7, Pins("A14"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 8, Pins("B14"), IOStandard("3.3-V LVTTL")),
    ("user_switch", 9, Pins("F15"), IOStandard("3.3-V LVTTL")),

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
class Switch(Module):
    def __init__(self, platform):
        counter = Signal(32)     
        # synchronous assignments
        self.sync += []
        # combinatorial assignements
        for i in range(10):
            led = platform.request("user_led", i)
            sw = platform.request("user_switch", i)
            self.comb += led.eq(sw)	#assign led to sw

module = Switch(platform)

#
# build
#

platform.build(module)
