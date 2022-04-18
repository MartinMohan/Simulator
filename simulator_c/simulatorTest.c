/*
// Generates a wave
// ----------------------------------------------------------------------------
// M.Mohan 13/10/2010 created
 */

#include "simulator.h"
#undef DEBUG_ON
/*
#define DEBUG_ON 1
 */

int main(int argc, char *argv[]){
#ifdef DEBUG_ON 
	printf("DEBUGGING on\n");
#endif
	/* Select Wave Type */
	if (argc < 2){
		printf ("Usage: %s <DeviceNumber>\n", argv[0]);
		printf ("e.g. %s 1 - simulates ramp rising from 0 to 59.9999 every 60 seconds\n", argv[0]);
		printf ("e.g. %s 2 - simulates ramp rising from 0 to 119.9999 every 60 seconds\n", argv[0]);
		printf ("e.g. %s 3 - Returns error and fixed value for 60\n", argv[0]);
		printf ("e.g. %s 4 - timeout never returns\n", argv[0]);
		exit(0);
	}

	int DeviceNumber=atoi(argv[1]);
//	simulator(DeviceNumber);

#ifdef DEBUG_ON 
	printf ("DeviceNumber %d MaxAmplitude %d Amplitude %.06f\n",DeviceNumber,MaxAmplitude,Amplitude);
#endif

	double Amplitude=0.0;
	int returnvalue=-1;

	for(;;){
		returnvalue=GetAmplitude(DeviceNumber,&Amplitude);
		if(returnvalue==-1){
			printf ("DeviceNumber %d Amplitude %.06f AmplitudeMax %d returnvalue %d\n",DeviceNumber,Amplitude,GetAmplitudeMax(),returnvalue);
		}else{
			printf ("DeviceNumber %d Amplitude %.06f AmplitudeMax %d returnvalue %d\n",DeviceNumber,Amplitude,GetAmplitudeMax(),returnvalue);
		}
	}
	return 0;
}
