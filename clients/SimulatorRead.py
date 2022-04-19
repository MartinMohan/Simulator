#!/usr/bin/python
import PyTango,datetime
import sys
sys.tracebacklimit = 0
    
def read_device(device_name):
    Amplitude=-1
    try:
        device_handle = PyTango.DeviceProxy(device_name)
    except:
        MyError="Failed to open device %s"%device_name
        raise IOError(MyError)

    try:
        Amplitude=device_handle.read_attribute("Amplitude").value
    except Exception as exception:
        print ("Fail: device_name: %s raised error %s"%(device_name,exception.__class__.__name__))
#        pass

    time_now = datetime.datetime.now().strftime("%H:%M:%S")
    print ("%s: device_name: %s: Amplitude %s"%(time_now,device_name,Amplitude))


read_device("test/Simulator/rampx1")
read_device("test/Simulator/rampx2")
read_device("test/Simulator/timeout") # TODO handle timeout better
read_device("test/Simulator/error")
