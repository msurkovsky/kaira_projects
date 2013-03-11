/**
 * \class cFunctions
 * \brief
 *
 * Based on http://www.math.ntu.edu.tw/~wwang/cola_lab/test_problems/multiple_opt/multiopt_prob/
 * and http://www.zsd.ict.pwr.wroc.pl/files/docs/functions.pdf
 *
 * All functions to be minimized in POSITIVE numbers (e.g. global minima must be >= 0).
 *
 * \author Pavel Krömer (c) 2012
 *
 */

#ifndef CFUNCTIONS_H_
#define CFUNCTIONS_H_

#include <math.h>

class cFunctions
{
	public:
		typedef enum { FUNC_ACKLEY, FUNC_EASOM, FUNC_SCHWEFEL, FUNC_ROSENBROCK, FUNC_RASTRIGIN	,
			FUNC_DEJONG, FUNC_GRIEWANK} t_FunctionType;

	private:
		static t_FunctionType m_FunctionType;

		double BnchFunc_USS_002_Ackley (const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_Easom (const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_Schwefel(const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_Rosenbrock(const double *position, const unsigned int dimension) const;

		double BnchFunc_USS_002_Camel3 (const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_Camel6 (const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_AluffiPentini (const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_BeckerLago(const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_Bohachevsky1(const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_Bohachevsky2(const double *position, const unsigned int dimension) const;
		double BnchFunc_USS_002_Branin(const double *position, const unsigned int dimension) const;

		double Rastrigin(const double * position, const unsigned int dimension) const;
		double Dejong(const double * position, const unsigned int dimension) const;
		double Griewank(const double * position, const unsigned int dimension) const;

	public:
		cFunctions();

		void SetFunction(const t_FunctionType type);

		double RangeMin(void) const;
		double RangeMax(void) const;

		double Evaluate (const double * data, const unsigned int dim) const;

		virtual ~cFunctions();
};

inline void cFunctions::SetFunction(const t_FunctionType type)
{
	m_FunctionType = type;
}

#endif /* CFUNCTIONS_H_ */
