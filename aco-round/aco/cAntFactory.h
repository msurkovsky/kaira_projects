/**
 * \class cAntFactory
 * \brief The class serves as an interface for creation of new ants.
 *
 * \author Pavel Krömer (c) 2011
 *
 */

#ifndef __CANTFACTORY_H__
#define __CANTFACTORY_H__

#include <iomanip>

#include "../arg/core/cDebuggable.h"

#include "cAnt.h"

class cAntFactory : public arg::cDebuggable
{
	protected:
		float * m_Pheromones;				///< Pheromone array shared among the ants. Managed by this object.
		unsigned long m_GraphDim;			///< The dimension of the graph. Pheromone array has the length m_GraphDim^2
		double m_Power;						///< Optional argument for the 'power rule'. Propagated to the ants when they are created.

		/** Utility method to print an array of double. */
		void PrintArray(const float* array, const unsigned int x, const unsigned int y) const;

		/** Default configuration of new ants. Sets Debug() if the factory is in debug mode and propagates m_Power to the ant. */
		virtual cAnt* Configure(cAnt * ant) const;

	public:

		cAntFactory(void);

		/**
		 * \brief This is the interface method. \ref cAntColony uses it to spawn new ants for its population.
		 * \returns New ant (i.e. candidate solution). The individual might not have Fitness computed.
		 * */
		virtual cAnt * GetInstance(void) = 0;

		/** Setters and getters. */
		float * const Pheromones(void) const	{return m_Pheromones;};
		unsigned long const GraphDim(void) const {return m_GraphDim;};
        double Power(void) const {return m_Power;};

		void const Power(const double val) {m_Power = val;};

		/** Prints the pheromone matrix. */
		void const PrintPheronomens(void) const;

		inline virtual ~cAntFactory();
};

inline cAntFactory::~cAntFactory(void)
{
	if (m_Pheromones != NULL)
	{
		delete[] m_Pheromones;
	}
}

#endif

