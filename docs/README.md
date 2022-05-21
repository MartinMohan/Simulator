<img src="./docs/tango_logo.png">
# Tango Simulator server  
For description see ./docs/wepks030.pdf

# Installation overview 
## Create the ramp library -lsimulator\_cpp needed by tango ramp server 

>cd Simulator/simulator_c  
>make 

## <a href="https://tango-controls.readthedocs.io/en/latest/installation/tango-on-linux.html">Install Tango</a> and compile tango ramp server 

>apt-get install libtango-dev  
>cd Simulator  
>make 
## make Simulator server and add to \$PATH
>sed -i '$ a export PATH=\$PATH:\$HOME/DeviceServers' $HOME/.bashrc  
>source $HOME/.bashrc  
>Simulator  
usage :  Simulator instance_name [-v[trace level]] [-file=<file_name> | -nodb [-dlist <device name list>] ]  
## register/start the device (<a href="https://www.esrf.fr/computing/cs/tango/tango_doc/tools_doc/jive_doc/index.html">jive</a>) 
>sudo apt-get install libtango-java  
>sudo apt-get install openjdk-8-jdk  
>sudo update-alternatives --config java   
>jive

<img src="./docs/register.png">

## Access tango server using tango clients

<img src="./docs/clients.png">
