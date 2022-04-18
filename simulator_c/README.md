ICALEPCS 2011  paper WEPKS030 

Simulator program to generate similar signals and errors expected by a hardware device 

For tango use libSimulator_cpp (c++ compiler): make 

For tine,epics use libSimulator libraries (c compiler): make -f Makefile_c 

clean: make clean 

test: make all;simulatorTest_cpp 1
