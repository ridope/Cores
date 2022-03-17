#!/usr/bin/env python3

import time
import datetime

from litex import RemoteClient

wb = RemoteClient()
wb.open()

# # #

def display0_write(sel, value):

    wb.regs.display0_value.write(value)
    wb.regs.display0_write.write(1)
    
def display1_write(sel, value):    
    wb.regs.display1_sel.write(sel)
    wb.regs.display1_value.write(value)
    wb.regs.display1_write.write(1)
    
def display2_write(sel, value):    
    wb.regs.display2_sel.write(sel)
    wb.regs.display2_value.write(value)
    wb.regs.display2_write.write(1)
    
def display3_write(sel, value):    
    wb.regs.display3_sel.write(sel)
    wb.regs.display3_value.write(value)
    wb.regs.display3_write.write(1)
    
def display4_write(sel, value):    
    wb.regs.display4_sel.write(sel)
    wb.regs.display4_value.write(value)
    wb.regs.display4_write.write(1)
    
def display5_write(sel, value):    
    wb.regs.display5_sel.write(sel)
    wb.regs.display5_value.write(value)
    wb.regs.display5_write.write(1)

def display0_time(second):
    display0_write(0, second%10)
    
def display1_time(second):    
    display1_write(1, (second//10)%10)
    
def display2_time(minute):
    display2_write(2, minute%10)
    
def display3_time(minute):
    display3_write(3, (minute//10)%10)
    
def display4_time(hour):
    display4_write(4, hour%10)
    
def display5_time(hour):
    display5_write(5, (hour//10)%10)

print("Testing SevenSegmentDisplay...")
while True:
    t = datetime.datetime.now()
    
    display0_time(t.second)
    display1_time(t.second)
    display2_time(t.minute)
    display3_time(t.minute)
    display4_time(t.hour)
    display5_time(t.hour)
    
    time.sleep(0.2)

# # #

wb.close()
