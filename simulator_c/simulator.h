/*
   ----------------------------------------------------------------
   @file simulator.h
   Generate a sine wave

   who      when     what
   ----------------------------------------------------------------
   mmohan   04/07/2010 created
   ----------------------------------------------------------------
 */

#ifndef simulator_h
#define simulator_h

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// public  values and interfaces
int GetAmplitude (int RegisterNumber, double *Amplitude);

void SetAmplitudeMax(int myAmplitude);
int GetAmplitudeMax();

#endif
