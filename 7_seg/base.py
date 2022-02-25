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
        display_sec_o = SevenSegmentDisplay(self.sys_clk_freq)
        display_sec_t = SevenSegmentDisplay(self.sys_clk_freq)
        display_min_o = SevenSegmentDisplay(self.sys_clk_freq)
        display_min_t = SevenSegmentDisplay(self.sys_clk_freq)
        display_hour_o = SevenSegmentDisplay(self.sys_clk_freq)
        display_hour_t = SevenSegmentDisplay(self.sys_clk_freq)
        self.submodules += display_sec_o, display_sec_t, display_min_o, display_min_t, display_hour_o, display_hour_t
        
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
            display_sec_o.values.eq(bcd_seconds.ones),
            display_sec_t.values.eq(bcd_seconds.tens),

            # Convert core minutes to bcd and connect
            # to display
            bcd_minutes.value.eq(core.minutes),
            display_min_o.values.eq(bcd_minutes.ones),
            display_min_t.values.eq(bcd_minutes.tens),

            # Convert core hours to bcd and connect
            # to display
            bcd_hours.value.eq(core.hours),
            display_hour_o.values.eq(bcd_hours.ones),
            display_hour_t.values.eq(bcd_hours.tens),
            
            #Connect to pads
            platform.request("seven_seg",0).eq(~display_sec_o.abcdefg),
            platform.request("seven_seg",1).eq(~display_sec_t.abcdefg),
            platform.request("seven_seg",2).eq(~display_min_o.abcdefg),
            platform.request("seven_seg",3).eq(~display_min_t.abcdefg),	
            platform.request("seven_seg",4).eq(~display_hour_o.abcdefg),
            platform.request("seven_seg",5).eq(~display_hour_t.abcdefg)
                     
        ]
       
        
        # -- TO BE COMPLETED --
            
module = Clock()

# Build --------------------------------------------------------------------------------------------

platform.build(module)
