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

class cTspAnt : public cAnt
{
		const double * m_Distances;				///< The matrix with distances between cities.

	protected:
		virtual double APriori(const unsigned long from, const unsigned long to);

	public:
		cTspAnt(double * pheromones, const double * distances, const unsigned int graph_dim);
		virtual double ComputeFitness(void);

		/** A method for tests. It can be used e.g. to verify found solutions. */
		double Test(const int *, const unsigned int, const int add = 0) const;
};

#endif /* CTSPANT_H_ */
