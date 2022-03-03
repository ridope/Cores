#!/usr/bin/env python3

from migen import *

from litex.build.generic_platform import *
from litex.build.altera import AlteraPlatform
from litex.build.altera.programmer import USBBlaster

from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.cores.uart import UARTWishboneBridge
from litex.soc.cores.spi import SPIMaster

from ios import Led, Button, Switch
from display import *

# IOs ----------------------------------------------------------------------------------------------

_io = [
	#clk
    ("clk10", 0, Pins("N5"), IOStandard("3.3-V LVTTL")),
    ("clk50", 0, Pins("P11"), IOStandard("3.3-V LVTTL")),
    ("clk50", 1, Pins("N14"), IOStandard("3.3-V LVTTL")),

    ("serial", 0,
        Subsignal("tx", Pins("V10"), IOStandard("3.3-V LVTTL")), # JP1 GPIO[0]
        Subsignal("rx", Pins("W10"), IOStandard("3.3-V LVTTL"))  # JP1 GPIO[1]
    ),

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
	#Buttons
    ("user_btn", 0, Pins("B8"), IOStandard("3.3-V LVTTL")),
    ("user_btn", 1, Pins("A7"), IOStandard("3.3-V LVTTL")),
	#Switches
    ("user_sw", 0, Pins("C10"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 1, Pins("C11"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 2, Pins("D12"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 3, Pins("C12"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 4, Pins("A12"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 5, Pins("B12"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 6, Pins("A13"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 7, Pins("A14"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 8, Pins("B14"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 9, Pins("F15"), IOStandard("3.3-V LVTTL")),

	# 7-segment displays
    ("seven_seg", 0, Pins("C14 E15 C15 C16 E16 D17 C17 D15"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 1, Pins("C18 D18 E18 B16 A17 A18 B17 A16"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 2, Pins("B20 A20 B19 A21 B21 C22 B22 A19"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 3, Pins("F21 E22 E21 C19 C20 D19 E17 D22"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 4, Pins("F18 E20 E19 J18 H19 F19 F20 F17"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 5, Pins("J20 K20 L18 N18 M20 N19 N20 L19"), IOStandard("3.3-V LVTTL")),


    ("gpio_0", 0,
        Pins("V10 W10 V9 W9 V8 W8 V7 W7 W6 V5 W5 AA15 AA14 W13 W12 AB13 AB12 Y11 AB11 W11 AB10 AA10 AA9 Y8 AA8 Y7 AA7 Y6 AA6 Y5 AA5 Y4 AB3 Y3 AB2 AA2"),
        IOStandard("3.3-V LVTTL")
    ),
    ("gpio_1", 0,
        Pins("AB5 AB6 AB7 AB8 AB9 Y10 AA11 AA12 AB17 AA17 AB19 AA19 Y19 AB20 AB21 AA20 F16"),
        IOStandard("3.3-V LVTTL")
    ),

	#Accelerometer
    ("adxl362_spi", 0,
        Subsignal("int1", Pins("Y14")),
        Subsignal("int1", Pins("Y13")),
        Subsignal("mosi", Pins("V11")),
        Subsignal("miso", Pins("V12")),
        Subsignal("clk", Pins("AB15")),
        Subsignal("cs_n", Pins("AB16")),
        IOStandard("3.3-V LVTTL")
    )
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

# Create our platform (fpga interface)
platform = Platform()

# Create our soc (fpga description)
class BaseSoC(SoCMini):
    def __init__(self, platform, **kwargs):
        sys_clk_freq = int(50e6)

        # SoCMini (No CPU, we are controlling the SoC over UART)
        SoCMini.__init__(self, platform, sys_clk_freq, csr_data_width=32,
            ident="My first LiteX System On Chip", ident_version=True)

        # No CPU, use Serial to control Wishbone bus
        self.submodules.serial_bridge = UARTWishboneBridge(platform.request("serial"), sys_clk_freq)
        self.add_wb_master(self.serial_bridge.wishbone)


        # Led
        user_leds = Cat(*[platform.request("user_led", i) for i in range(9)])
        self.submodules.leds = Led(user_leds)
        self.add_csr("leds")

        # Switches
        user_switches = Cat(*[platform.request("user_sw", i) for i in range(9)])
        self.submodules.switches = Switch(user_switches)
        self.add_csr("switches")

        # Buttons
        user_buttons = Cat(*[platform.request("user_btn", i) for i in range(1)])
        self.submodules.buttons = Button(user_buttons)
        self.add_csr("buttons")

        # Accelerometer
        self.submodules.accel = SPIMaster(platform.request("adxl362_spi"),
            data_width   = 32,
            sys_clk_freq = sys_clk_freq,
            spi_clk_freq = 1e6)
        self.add_csr("adxl362") 

        # SevenSegmentDisplay
        self.submodules.display0 = SevenSegmentDisplay0(sys_clk_freq)
        self.add_csr("display0")
        self.submodules.display1 = SevenSegmentDisplay1(sys_clk_freq)
        self.add_csr("display1")
        self.submodules.display2 = SevenSegmentDisplay2(sys_clk_freq)
        self.add_csr("display2")
        self.submodules.display3 = SevenSegmentDisplay3(sys_clk_freq)
        self.add_csr("display3")
        self.submodules.display4 = SevenSegmentDisplay4(sys_clk_freq)
        self.add_csr("display4")
        self.submodules.display5 = SevenSegmentDisplay5(sys_clk_freq)
        self.add_csr("display5")
        self.comb += [
            platform.request("seven_seg",0).eq(~self.display0.abcdefg),
            platform.request("seven_seg",1).eq(~self.display1.abcdefg),
            platform.request("seven_seg",2).eq(~self.display2.abcdefg),
            platform.request("seven_seg",3).eq(~self.display3.abcdefg),	
            platform.request("seven_seg",4).eq(~self.display4.abcdefg),
            platform.request("seven_seg",5).eq(~self.display5.abcdefg)
        ]

soc = BaseSoC(platform)

# Build --------------------------------------------------------------------------------------------

builder = Builder(soc, output_dir="build", csr_csv="test/csr.csv")
builder.build(build_name="top")
