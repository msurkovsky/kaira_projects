/**
 * \class cTspAnt
 * \brief An implementation of the artificial ant for the traveling salesman problem.
 *
 * Behavior (apriori information) of this ant is similar to those from the book
 * "Ant Colony Optimization", Dorigo & Stuetzle, MIT Press, 2004
 *
 * \author Pavel Krömer (c) 2011
 *
 */

#ifndef CTSPANT_H_
#define CTSPANT_H_


#include "../cAnt.h"
//#include "../../arg/core/cArray.h"
#include <vector>

class cTspAnt : public cAnt
{
//		const double * m_Distances;				///< The matrix with distances between cities.

    const std::vector<std::pair<double, double> > &m_Cities;
	protected:
		virtual double APriori(const unsigned long from, const unsigned long to);
        double GetDistance(unsigned long from, unsigned long to) const;

	public:
		cTspAnt(float * pheromones,
                const std::vector<std::pair<double, double> > &cities,
                const unsigned int graph_dim);
		virtual double ComputeFitness(void);

		/** A method for tests. It can be used e.g. to verify found solutions. */
		double Test(const int *, const unsigned int, const int add = 0) const;
};

#endif /* CTSPANT_H_ */
