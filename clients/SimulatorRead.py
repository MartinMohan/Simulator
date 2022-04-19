#!/usr/bin/python
# This prints the current value for Simulator signals
# read_device("test/Simulator/timeout") should throw CommunicationFailed
import PyTango,datetime
    
def read_device(device_name):
    Amplitude=-1
    time_now = datetime.datetime.now().strftime("%H:%M:%S")

    try:
        device_handle = PyTango.DeviceProxy(device_name)
    except Exception as exception:
        device_name = '\033[91m'+device_name+" "+ exception.__class__.__name__ +": " + '\033[0m'
        print ("Open: %s: device_name: %s Amplitude: %s"%(time_now,device_name,Amplitude))
        pass
        return

    try:
        Amplitude=device_handle.read_attribute("Amplitude").value
        print ("%s: device_name: %s: Amplitude %s"%(time_now,device_name,Amplitude))
    except Exception as exception:
        device_name = '\033[93m'+device_name+" "+ exception.__class__.__name__ +": " + '\033[0m'
        print ("Read: %s: device_name: %s Amplitude: %s"%(time_now,device_name,Amplitude))


read_device("test/simulator/rampx1")
read_device("test/simulator/rampx2")
read_device("test/simulator/timeout") #  Throws exception CommunicationFailed
read_device("test/simulator/error")
