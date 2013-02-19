/**
 * \class cTspAntFactory
 * \brief
 *
 * \author Pavel Krömer (c) 2011
 *
 */

#ifndef CTSPANTFACTORY_H_
#define CTSPANTFACTORY_H_

#include <fstream>

#include "../../arg/core/cArray.h"

#include "../cAntFactory.h"

#include "cTspAnt.h"

class cTspAntFactory: public cAntFactory
{
		typedef struct
		{
				double x;
				double y;
		} t_Pair;

		double * m_Distances;

	public:
		cTspAntFactory(const char * fname);

		virtual cAnt * GetInstance(void);

		void PrintDistances(void) const;

		virtual ~cTspAntFactory();
};

#endif /* CTSPANTFACTORY_H_ */
