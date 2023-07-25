<img src="./docs/tango_logo.png">
# Tango Simulator server  
This is a test server which works with the Tango scada. https://www.tango-controls.org/. A small c library (simulator_c) generates signals simlar to those expected from a hardware device and this library is incorporated into the Simulator Tango server.  
This server must be registerd to a Tango scada. The Tango tools can then be used to visualize and store signals. For description see ./docs/wepks030.pdf  

# Installation overview  (for debian/ubuntu)
## Install the Tango scada
https://tango-controls.readthedocs.io/en/9.3.3/installation/tango-on-linux.html

## Make the simulator_c library -lsimulator\_cpp needed by the server  
>git clone https://github.com/MartinMohan/Simulator  
>cd Simulator/simulator_c  
>make  
>./simulatorTest_cpp 1 (tests if library works)  
DeviceNumber 1 Amplitude 33.055296 AmplitudeMax 60 returnvalue 0  
DeviceNumber 1 Amplitude 33.055307 AmplitudeMax 60 returnvalue 0  
DeviceNumber 1 Amplitude 33.055319 AmplitudeMax 60 returnvalue 0  
DeviceNumber 1 Amplitude 33.055330 AmplitudeMax 60 returnvalue 0  

## Make the Tango server  
>cd Simulator  
>make   
>cd bin  
> ./Simulator  
usage :  ./Simulator instance_name [-v[trace level]] [-file=<file_name> | -nodb [-dlist <device name list>] ]  

## Register/start the device with (<a href="https://www.esrf.fr/computing/cs/tango/tango_doc/tools_doc/jive_doc/index.html">jive</a>)   
<img src="./docs/register.png">  

## Access tango server using tango clients  

<img src="./docs/clients.png">
