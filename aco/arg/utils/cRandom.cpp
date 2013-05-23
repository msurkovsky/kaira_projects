#include "cRandom.h"
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>

namespace arg
{
	void cRandom::Init()
	{
        struct timespec time;
        if (clock_gettime(CLOCK_MONOTONIC, &time)) {
    		perror("TraceLog::write_time");
    		exit(-1);
    	}

    	uint64_t t = ((uint64_t) (time.tv_sec)) * 1e9;
    	t += time.tv_nsec;
        srand(t);
	}

	int cRandom::Next()
	{
		return rand();
	}

	double cRandom::Next(double up_to)
	{
		//RAND_MAX;
		//double
		return (double) rand() / (double) RAND_MAX * up_to;
	}

	double cRandom::Next(double from, double to)
	{

		return from + cRandom::Next(1) * (to - from);
	}

	int cRandom::NextInt(int up_to)
	{
		return rand() % (up_to + 1);
	}
}

