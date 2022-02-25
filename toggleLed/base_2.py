#!/usr/bin/env python3
from migen import *
#from migen.build.generic_platform import *
from litex.build.generic_platform import *
from litex.build.altera import AlteraPlatform
from litex.build.altera.programmer import USBBlaster
from migen.genlib.cdc import MultiReg



#IOs definition
_io = [
	#50 Mhz clock
    ("clk50",  0, Pins("N14"), IOStandard("3.3-V LVTTL")),
    
	#Leds
    ("user_led", 0, Pins("A8 A9 A10 B10 D13 C13 E14 D14 A11 B11"), IOStandard("3.3-V LVTTL")),


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
    
    	#Buttons
    ("user_btn_r", 0, Pins("B8"), IOStandard("3.3-V LVTTL")),
    ("user_btn_l", 1, Pins("A7"), IOStandard("3.3-V LVTTL")),

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

# create switch module (fpga description)
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
            
# create button module (fpga description)
class Counter(Module):
    def __init__(self):
    
    	self.count = Signal(4)    
        
        # Set interface
    	self.inc_count = Signal()
    	self.dec_count = Signal()

        # # #

        # Synchronous assigment
    	self.sync += [
            # Increment count
            If(self.inc_count,
                self.count.eq(self.count + 1),
                If(self.count == 10,
                    self.count.eq(0)
                )
            # Decrement count
            ).Elif(self.dec_count,
                self.count.eq(self.count - 1)
            )
        ]

class LedDisplay(Module):
    def __init__(self):
    	# Module's interface
    	i=10
    	#input
    	self.value = value = Signal(4) 
    	#Output  
    	self.current = current = Signal(10)    	    	
    	
    	#table of Led values
    	table_values = Array(Signal(10) for a in range(i)) 
    	#Assignment 
    	self.comb += [
    	table_values[0].eq(0b0000000001),
    	table_values[1].eq(0b0000000011), 
    	table_values[2].eq(0b0000000111), 
    	table_values[3].eq(0b0000001111), 
    	table_values[4].eq(0b0000011111), 
    	table_values[5].eq(0b0000111111), 
    	table_values[6].eq(0b0001111111), 
    	table_values[7].eq(0b0011111111), 
    	table_values[8].eq(0b0111111111), 
    	table_values[9].eq(0b1111111111)
    	]
        # # #

        # Combinatorial assignement
    	self.comb += current.eq(table_values[value])
        
class Button(Module):
    
    def __init__(self, platform):
        #User buttons
    	user_btn_r = UserButtonPress(platform.request("user_btn_r"))
    	user_btn_l = UserButtonPress(platform.request("user_btn_l"))
    	self.submodules += user_btn_r, user_btn_l
        
    	#Count
    	counter = Counter()
    	self.submodules += counter
	
	#Display
    	display = LedDisplay()
    	self.submodules += display
        
        # combinatorial assignements
    	self.comb += [
    	counter.inc_count.eq(user_btn_r.rising),
    	counter.dec_count.eq(user_btn_l.rising),
        
    	display.value.eq(counter.count),
 	#Connect to pads
	platform.request("user_led").eq(display.current)
        ]
       

#Create table which takes index as count signal
#signal(10) for Leds  where s.eq(table[i])
module = Button(platform)

#
# build
#

platform.build(module)
