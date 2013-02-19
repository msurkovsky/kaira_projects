#include "cRandom.h"

namespace arg
{
	void cRandom::Init()
	{
		srand((unsigned) time(NULL));
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

