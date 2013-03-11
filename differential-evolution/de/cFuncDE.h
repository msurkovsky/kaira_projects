/**
 * \class cFuncDE
 * \brief
 *
 * \author Pavel Krömer (c) 2012
 *
 */

#ifndef CFUNCDE_H_
#define CFUNCDE_H_

#include <arg/algorithms/de/cDE.h>

#include "../cFunctions.h"

class cFuncDE: public arg::cDE
{
	private:

		cFunctions m_Functions;

		virtual double ComputeFitness(const double* individual, const unsigned int length);
		virtual void InitDE() {};
		virtual void FinalizeDE() {};

	public:
		cFuncDE(const unsigned int pop_size, const unsigned int dim);
		virtual ~cFuncDE();
};

#endif /* CFUNCDE_H_ */
