#!/usr/bin/python
# Filename: CryotrapReadOnly
import random
import unittest
from PyTango import *
import sys, os, time

def readDevice(myDeviceName):
    print myDeviceName

myDeviceName="test/Simulator/ramp"
try:
    DeviceName = DeviceProxy(myDeviceName)
#    return DeviceName
except:
    MyError="Failed to open device %s"%myDeviceName
    raise IOError(MyError)
#DeviceName=OpenTangoDevice("test/Simulator/ramp")
DeviceName.command_inout("UpdateAttributes")
print "Amplitude ",DeviceName.read_attribute("Amplitude").value

helloworld("test")
