#include "cFuncDE.h"

cFuncDE::cFuncDE(const unsigned int pop_size, const unsigned int dim) :
		arg::cDE(pop_size, dim)
{
	m_PrintFrequency = 1e6;
}

double cFuncDE::ComputeFitness(const double * individual, const unsigned int length)
{
	double fit = m_Functions.Evaluate(individual, length);
	return fit;
}

cFuncDE::~cFuncDE()
{
    //
}
