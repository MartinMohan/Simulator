# author: mmohan@ego-gw.it 
# Date: 30/11/2011
# Make application simulatorTest which generates test signals
#
# c++ library generated for tango
#
export LD_RUN_PATH=.
MYHOME=.

#Tango
CC=c++

all: simulatorTest_cpp simulatorTest_static_cpp
	rm *.o

# Create dynamic executable
simulatorTest_cpp: libsimulator_cpp.o
	${CC} simulatorTest_cpp.o -o simulatorTest_cpp -g -Wl,-rpath,$(MYHOME) -I$(MYHOME) -L$(MYHOME) -lsimulator_cpp

# Create static executable - recompile App as static
simulatorTest_static_cpp: libsimulator_cpp.a
	${CC} -static simulatorTest.c -L. -lsimulator_cpp -o simulatorTest_static_cpp

# Create dynamic library
libsimulator_cpp.o: simulator_cpp.o simulatorTest_cpp.o
	${CC} -shared -g -Wl,-soname,libsimulator_cpp.so.1 -o libsimulator_cpp.so.1.0 simulator_cpp.o
	ln -sf libsimulator_cpp.so.1.0 libsimulator_cpp.so.1
	ln -sf libsimulator_cpp.so.1 libsimulator_cpp.so

# Create static library - "need static c prog so need to recompile"
libsimulator_cpp.a:
	${CC} -g -c -Wall -Wextra simulator.c -o simulator_cpp.o
	ar rcs libsimulator_cpp.a simulator_cpp.o

# Compile
simulator_cpp.o: simulator.c
	${CC} -fPIC -g -c -Wall -Wextra simulator.c -o simulator_cpp.o

# Compile
simulatorTest_cpp.o: simulatorTest.c
	${CC} -fPIC -g -c -Wall -Wextra -c simulatorTest.c -o simulatorTest_cpp.o

clean:
	rm -f simulatorTest_cpp simulatorTest_static_cpp libsimulator_cpp.*
	rm -f simulatorTest simulatorTest_* libsimulator*.*
