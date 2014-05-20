/**
 * \class cAnt
 * \brief Revised implementation of an artificial ant for the ACO.
 *
 * The ant works on a pheromone matrix. It decides its movements upon the pheromones and
 * updates the matrix. The ant works well with the operations as implemented in \ref cAntColony.
 *
 * The structure of its environmnet is also defined in the pheromone matrix. Every two nodes with
 * pheromone_ij = 0 are considered as not connected.
 *
 * The major difference from the usual ACO ants implementations lies in the possibility to define
 * a \b power value that can be used for definition of the \delta T_ij value to update chromosomes.
 *
 * \author Pavel Krömer (pkromer), (c) 2009 - 2011
 *
 * \b History:
 *		- 2010-01,	pkromer,	initial version
 *		- 2011-01,	pkromer,	rewritten
 *
 */

#ifndef __CANT_H__
#define __CANT_H__

#include <vector>
#include "../arg/core/cArray.h"
#include "../arg/core/cDebuggable.h"

#include "../arg/utils/cRandom.h"

#include <math.h>

class cAnt: public arg::cDebuggable
{
		unsigned int m_TrailLength; 					///< How many steps to do.
		bool m_DeadEnd;									///< Dead end- whether or not is this ant in a dead end.

		unsigned long m_GraphDim;						///< Graph dimension. The size of m_Pheromones must be m_GraphDim^2.
		float* m_Pheromones; 							///< The shared pheromone matrix used and updated by each ant.
		arg::cArrayConst<bool> m_Visited;				///< Bitmap of visited nodes for quick check.
		bool m_Symmetric;								///< Shall be the pheromone matrix updated in a symmetric manner?

		unsigned long m_Position; 						///< Current position (node index)

		double m_Alpha, m_Beta, m_Rho; 					///< ACO parameters
		double m_Power;									///< If not 0, the 'power rule' will be used to generate deltaTij.


		void StepForward(void); 						///< Makes one step forward
		long NextPosition(void);						///< Compute node to move to
		void ClearVisited(void);						///< Clears array of visited nodes (i.e. the ant can move to any connected node).

//		arg::cArrayConst<unsigned long> m_Trail;		///< The memory of ants' steps. Visited nodes in chronological order.

        std::vector<unsigned long> m_Trail;
	protected:

		double m_Fitness;								///< The fitness of the solution represented by this ants travel.

		virtual double APriori(const unsigned long from, const unsigned long to) = 0;			///< Get apriori information for movement between two nodes
		virtual unsigned long StartNode(void) const; 	///< Generate start node for this ant.

	public:

		cAnt(float * pheromones, const unsigned int graph_dim, const unsigned int trail_length, const double power = 0);

		void PlacePheromones(const double normalize_pheromones = 0, const bool minimize = false); 	///< Update the pheromone matrix.
		void GoForward(void);																		///< Run there

		/** Getters and setters. */
		double const Fitness(void) const {return m_Fitness;};
		void const Alpha(const double val){ m_Alpha = val;};
		void const Beta(const double val){ m_Beta = val;};
		void const Rho(const double val){if (m_Rho < 1 && m_Rho > 0) m_Rho = val;};
		void const Symmetric(const bool val){m_Symmetric = val;};
		void const Power(const double val) {m_Power = val;};
		unsigned int const GraphDim(void) const { return m_GraphDim;};
		unsigned int const TrailLength(void) const { return m_TrailLength;};

		const std::vector<unsigned long> & Trail(void) const {return m_Trail;};				///< Read only access to the trail of this ant.
		void SetTrail(const unsigned long *trail);

		virtual double ComputeFitness(void) = 0; 													///< Compute fitness corresponding to the ant trail.
		inline virtual void Print(void) const;														///< Print the ant.
};

inline void cAnt::Print(void) const
{
//	std::cout << m_Trail << std::endl;
}

#endif
