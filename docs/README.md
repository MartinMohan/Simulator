<img src="./tango_logo.png">
# Tango Simulator server  
For description see ./docs/wepks030.pdf

# Installation overview 
## Create the ramp library -lsimulator\_cpp needed by tango ramp server 

>cd Simulator/simulator_c  
>make 

## Install <a href="https://tango-controls.readthedocs.io/en/latest/installation/tango-on-linux.html">Tango</a> and compile tango ramp server 

>apt-get install libtango-dev  
>cd Simulator  
>make 
## Register and execute  Simulator tango server
>sed -i '$ a export PATH=\$PATH:\$HOME/DeviceServers' $HOME/.bashrc  
>source $HOME/.bashrc  
>Simulator  
usage :  Simulator instance_name [-v[trace level]] [-file=<file_name> | -nodb [-dlist <device name list>] ]  
## register/start the device (e.g. jive tools "Server Wizard") 
>sudo apt-get install libtango-java  
>sudo apt-get install openjdk-8-jdk  
>sudo update-alternatives --config java   

![Alt text](./register.png?raw=true "register")

## Access tango server using tango clients
![Alt text](./clients.png?raw=true "Clients")

