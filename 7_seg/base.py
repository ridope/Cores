#!/usr/bin/env python3

from migen import *
from migen.genlib.cdc import MultiReg

from litex.build.generic_platform import *
from litex.build.altera import AlteraPlatform
from litex.build.altera.programmer import USBBlaster

from tick import *
from display import *
from bcd import *
from core import *

# IOs ----------------------------------------------------------------------------------------------

_io = [
    # Led
    ("user_led", 0, Pins("A8"), IOStandard("3.3-V LVTTL")),
    
    # Switch
    ("user_switch", 0, Pins("C10"), IOStandard("3.3-V LVTTL")),
    
    # Buttons
    ("user_btn_r", 0, Pins("B8"), IOStandard("3.3-V LVTTL")),
    ("user_btn_l", 1, Pins("A7"), IOStandard("3.3-V LVTTL")),
    
    # CLK
    ("clk10", 0, Pins("N5"), IOStandard("3.3-V LVTTL")),
    ("clk50", 0, Pins("P11"), IOStandard("3.3-V LVTTL")),
    ("clk50", 1, Pins("N14"), IOStandard("3.3-V LVTTL")),


    
    # 7-segment displays
    ("seven_seg", 0, Pins("C14 E15 C15 C16 E16 D17 C17 D15"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 1, Pins("C18 D18 E18 B16 A17 A18 B17 A16"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 2, Pins("B20 A20 B19 A21 B21 C22 B22 A19"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 3, Pins("F21 E22 E21 C19 C20 D19 E17 D22"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 4, Pins("F18 E20 E19 J18 H19 F19 F20 F17"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 5, Pins("J20 K20 L18 N18 M20 N19 N20 L19"), IOStandard("3.3-V LVTTL")),
]

# Platform -----------------------------------------------------------------------------------------

class Platform(AlteraPlatform):
    default_clk_name = "clk50"	#default clk
    default_clk_period = 1e9/50e6
    create_rbf = False

    def __init__(self):
        AlteraPlatform.__init__(self, "10M50DAF484C7G", _io) #FPGA type

    def create_programmer(self):
        return USBBlaster()

# Design -------------------------------------------------------------------------------------------

# User button detection
class UserButtonPress(Module):
    def __init__(self, user_btn):
        self.rising = Signal()

        # # #

        _user_btn = Signal()
        _user_btn_d = Signal()

        # resynchronize user_btn
        self.specials += MultiReg(user_btn, _user_btn)
        # detect rising edge
        self.sync += [
            _user_btn_d.eq(user_btn),
            self.rising.eq(_user_btn & ~_user_btn_d)
        ]

# Create our platform (fpga interface)
platform = Platform()

# Create our main module (fpga description)
class Clock(Module):
    sys_clk_freq = int(50e6)
    def __init__(self):
        # -- TO BE COMPLETED --
        # Tick generation : timebase
        tick = Tick(self.sys_clk_freq, 1) 
        self.submodules += tick

        # SevenSegmentDisplay
        display = SevenSegmentDisplay(self.sys_clk_freq)
        self.submodules += display
        
        # Core : counts ss/mm/hh
        core = Core()
        self.submodules += core

        # set mm/hh
        btn0_press = UserButtonPress(platform.request("user_btn_r"))   #mm
        btn1_press = UserButtonPress(platform.request("user_btn_l"))   #hh
        self.submodules += btn0_press, btn1_press

        # Binary Coded Decimal: convert ss/mm/hh to decimal values
        bcd_seconds = BCD()
        bcd_minutes = BCD()
        bcd_hours = BCD()
        self.submodules += bcd_seconds, bcd_minutes, bcd_hours
        # use the generated verilog file
        platform.add_source("bcd.v")

        # combinatorial assignement
        self.comb += [
            # Connect tick to core (core timebase)
            core.tick.eq(tick.ce),

            # Set minutes/hours
            core.inc_minutes.eq(btn0_press.rising),
            core.inc_hours.eq(btn1_press.rising),

            # Convert core seconds to bcd and connect
            # to display
            bcd_seconds.value.eq(core.seconds),
            display.values[0].eq(bcd_seconds.ones),
            display.values[1].eq(bcd_seconds.tens),

            # Convert core minutes to bcd and connect
            # to display
            bcd_minutes.value.eq(core.minutes),
            display.values[2].eq(bcd_minutes.ones),
            display.values[3].eq(bcd_minutes.tens),

            # Convert core hours to bcd and connect
            # to display
            bcd_hours.value.eq(core.hours),
            display.values[4].eq(bcd_hours.ones),
            display.values[5].eq(bcd_hours.tens),
            
            #Connect to pads
            platform.request("display_seg",0).eq(~display.abcdefg[0]),
            platform.request("display_seg",1).eq(~display.abcdefg[1]),
            platform.request("display_seg",2).eq(~display.abcdefg[2]),
            platform.request("display_seg",3).eq(~display.abcdefg[3]),	
            platform.request("display_seg",4).eq(~display.abcdefg[4]),
            platform.request("display_seg",5).eq(~display.abcdefg[5])
                     
        ]
       
        
        # -- TO BE COMPLETED --
            
module = Clock()

# Build --------------------------------------------------------------------------------------------

platform.build(module)
