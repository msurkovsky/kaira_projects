/**
 * \class cAntColony
 * \brief Revised implementation of the ACO algorithm.
 *
 * The class implements slightly modified Min-Max Ant System with the possibility to reinforce the
 * trails found by globally best ant and round-best ant.
 *
 * The type of the algorithm can be set by the AcoType method using a bit mask of supported types, e.g.:
 * <code>
 * 	aco.AcoType(cAntColony::ACO_ELITIST_ANT_SYSTEM_GLOBAL | cAntColony::ACO_ELITIST_ANT_SYSTEM_ROUND);
 * </code>
 * \author Pavel Krömer (pkromer), (c) 2011
 *
 * History:
 *		- 2011-01,	pkromer,	initial version (original rewritten)
 *
 */

#ifndef CANTCOLONY_H_
#define CANTCOLONY_H_

#include <climits>

#include "../arg/utils/cTimer.h"

#include "cAntFactory.h"

class cAntColony: public arg::cDebuggable
{
		cAntFactory * m_Factory;							///< The 'factory' that can create ants. Also some other parameters are read from the class.

	protected:

		arg::cArrayConst<cAnt *> m_Antz;					///< The population of ants (unsorted).
		unsigned int m_AntCnt;								///< Number of ants in the population.
		unsigned int m_BestAntIdx;							///< The index of best ant (i.e. an ant with maximum or minimum fitness).

		unsigned int m_RoundBestBoost;						///< If the ACO type is set to ACO_ELITIST_ANT_SYSTEM_ROUND, then the round-best tour is repeated this much.
		unsigned int m_GlobalBestBoost;						///< If the ACO type is set to ACO_ELITIST_ANT_SYSTEM_GLOBAL, then the so far-best tour is repeated this much.

		double m_BestAntFitness;							///< The fitness of the best ant in the current round..
		double m_GlobalBestAntFitness;						///< The fitness of the best ant so far;

		cAnt* m_GlobalBestAnt;								///< A copy of the best ant so far.

		unsigned int m_AcoType;								///< The type of the ACO algorithm.

		double m_Rho, m_Alpha, m_Beta;						///< Algorithm parameters.
		bool m_Minimize;									///< Whether to maximize or minimize the fitness.
		double m_MaxMin;									///< Whether maxmin rule should be used. This will initiate Min Max behavior in the colony.

		void Delete();										///< Delete population and best ant.
		virtual void Populate();							///< Create new population and best ant.

		arg::cTimer timer;

	public:

		/** Different types of the algorithm. */
		unsigned static int const ACO_ANT_SYSTEM = 0;
		unsigned static int const ACO_ELITIST_ANT_SYSTEM_ROUND = 1;
		unsigned static int const ACO_ELITIST_ANT_SYSTEM_GLOBAL = 2;

        cAntColony();
        cAntColony(const cAntColony &c);
		cAntColony(cAntFactory* factory, const unsigned int ant_cnt);

		/** Ant parameter setters. These parameters are propagated to ants. */
		void Alpha(const double val);
		void Beta(const double val);
		void Rho(const double val);

		/** ACO parameter setters. */
		void Minimize(const bool val = true) {m_Minimize = val;};
		void MaxMin(const double val = true) {m_MaxMin = val;};
		void AcoType(const unsigned int val) {m_AcoType = val;};
		void RoundBestBoost(const unsigned int val) {m_RoundBestBoost = val;};
		void GlobalBestBoost(const unsigned int val) {m_GlobalBestBoost = val;};

		/** Algorithm steps. */
		void GoForward(void);
		void PlacePheromones(void);
		void Evaporate(void);
		void Reset(void);
		void ComputeFitness(void);

		/** A wrapper for the full ACO algorithm.
		 * \returns a \b pointer the the best found ant. The object is deleted when the ACO object ceases to exist.
		 * */
		cAnt* Execute(const unsigned int rounds);
		void StartExecution(void);
		void Execution(void);
		cAnt* EndExecution(void);
		void SetBestAntTrail(const unsigned long *trail, double fitness);

		/** Get the pointer to best ant or find new best ant (if rescan == true). */
		cAnt* BestAntPtr(const bool rescan = false);

		/** Get one ant from colony */
		cAnt* GetAnt(int val);

		/** Get dimension of graph */
		unsigned long GetDim();

		virtual ~cAntColony(void);
};

#endif /*CANTCOLONY_H_*/
