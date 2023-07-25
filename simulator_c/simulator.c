/*
// Generates dummy signals and errors to simulate hardware
// ----------------------------------------------------------------------------
// M.Mohan 23/11/2010 created
 */

#include "simulator.h"
#include "string.h"
#undef DEBUG_ON

// private
int AmplitudeMax=60; // Max height of signal

// Set Max height AmplitudeMax
void SetAmplitudeMax(int myAmplitude)
{
	AmplitudeMax = myAmplitude;
}

// Get Max height AmplitudeMax
int GetAmplitudeMax()
{
	return(AmplitudeMax);
}

//  DeviceNumber=Type of ramp 1,2,3,4 *Amplitude=ramp value return value=-1 error, 0 success
int GetAmplitude (int DeviceNumber, double *Amplitude){
        struct timeval  tv; struct timezone tz;
        struct tm      *tm;
        gettimeofday(&tv, &tz); tm = localtime(&tv.tv_sec);

        // *Amplitude= Seconds time of system clock
        *Amplitude=((double)((1000000*tm->tm_sec)+tv.tv_usec)/1000000); //  0-59.999999

        int ErrorValue =0; // default 0=ok

        switch (DeviceNumber)
        {
                case 1: // 0-59.999999 = ramp
                        break;
                case 2: // 0-119.999998 = rampx2
                        *Amplitude=*Amplitude*2; 
                        break;
                case 4: // timeout
                        sleep(99999999);  
                        break;
                default: // error
                        *Amplitude=60;
                        ErrorValue=-1; //  -1 = Error
                        break;
        }
        return ErrorValue; // return 0 or -1d
}

