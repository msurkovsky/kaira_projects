/**
 * \class arg::cDE
 * \brief An implementation of Differential Evolution.
 *
 * A differential evolution implemented according to:
 * Differential Evolution: A Practical Approach to Global Optimization (Natural Computing Series) [Hardcover]
 * Kenneth Price (Author), Rainer M. Storn (Author), Jouni A. Lampinen (Author)
 *
 * Own improvements:
 * - inverted crossover (helps with convergence in the initial phase; by default off)
 * - randomized crossover (helps when the population is stuck in local extreme; by default on)
 *
 * Intended use:
 * \code
 *  cFuncDE de(10);
 *  de.MaxGen(3000000);
 *  de.Range(-30,30);
 *  de.Process();
 *  vecd winner = de.Winner();
 * \endcode
 *
 * \author Pavel Krömer (c) 2012
 *
 * \version 2.0
 *
 * \b History:
 * 		- 2012-10,	pkromer,	initial version without itpp
 */

#ifndef CDE_H_
#define CDE_H_

#include <iostream>
#include <climits>
#include <cstdlib>

#include <arg/utils/cRandom.h>
#include <arg/utils/cTimer.h>

#include <arg/core/cArray.h>
#include <arg/core/cDebuggable.h>

namespace arg
{
	class cDE : public cDebuggable
	{
		public:

			typedef enum {SELECTION_RAND = 0, SELECTION_BEST} 			t_DESelectionType;
			typedef enum {MUTATION_INVERSE = 4, MUTATION_CLASSIC,	MUTATION_TARGET_TO_BEST,
												  MUTATION_EITHER_OR} 	t_DEMutationType;
			typedef enum {MIGRATION_ELITISM = 8, MIGRATION_CLASSIC} 	t_DEMigrationType;
			typedef enum {CROSSOVER_CLASSIC = 100, CROSSOVER_RANDOMIZED} t_DECrossoverType;

			typedef struct {double fit; unsigned int idx;} t_FitnessIndexPair;

		protected:
			double * m_Population;					///< Population of candidate solutions
			double * m_AuxPopulation;				///< Auxiliary population of candidate solutions (used in each iteration)
			unsigned int m_Gbidx;					///< Index of the best solution
			double m_Gbfit;							///< Fitness of the best solution (lowest fitness)
			double m_C, m_F;						///< DE parameters

			double m_LowerBound, m_UpperBound;		///< Lower and upper bound (range) of the searched space

			t_DESelectionType m_SelectionType;		///< Types of operations
			t_DEMutationType  m_MutationType;
			t_DEMigrationType m_MigrationType;
			t_DECrossoverType m_CrossoverType; 		///< Types of crossover (randomized or not)

			unsigned int m_PopulationSize, m_VectorLength;					///< Size of population and dimension of vector

			cArrayConst<double> m_Fitness;			///< A vector with fitness values of the population

			unsigned int m_MaxTime;					///< Maximum time for algorithm running
			unsigned int m_MaxGenerations;			///< Maximum number of generations
			unsigned int m_MaxEvaluations;			///< Maximum number of fitness function evaluations
			unsigned int m_CurrentEvaluation;

			unsigned int m_PrintFrequency;			///< The frequency of fitness reporting
			unsigned int m_Iteration;				///< Current iteration
			bool m_Initialized;						///< Whether or not properly initialized

			cTimer m_Timer;							///< Timing of the algorithm
			cRandom * m_Random;						///< Random number generator

			void MutationTargetToBest(cArrayConst<double> & u, double* P, const unsigned i, const double Fj, const unsigned int r2, const unsigned int r3);
			void MutationStandard(cArrayConst<double> & u, double* P, const double Fj, const unsigned int r1, const unsigned int r2, const unsigned int r3);
			void MutationEitherOr(cArrayConst<double> & u, double* P, const double Fj, const unsigned int r1, const unsigned int r2,	const unsigned int r3);

			/** Vector selection methods. */
			unsigned int SelectVector(const unsigned int tabu = (unsigned int) -1, const unsigned int tabu2 = (unsigned int) -1);

			virtual void Print(double* p);
			virtual void PrintPopInfo(int);

			virtual void InitPopulation(double* m);
			virtual void Evaluate(double* p, cArrayConst<double> & results);

			virtual void CheckRange(cArrayConst<double> & u);

			virtual void InitDE() = 0;
			virtual void FinalizeDE()=0;
			virtual double ComputeFitness(const double * individual, const unsigned int size) = 0;
			virtual void Crossover(cArrayConst<double> & xi, const double C, cArrayConst<double> & u);

			double MinFitness(unsigned int & idx);

			static int CompareVectors(const void*, const void*);
			void SortPopulation(cArrayConst<t_FitnessIndexPair> &indexes);

		public:
			cDE(const unsigned int population_size, const unsigned int vector_length, const unsigned int max = 1e9);

			/** Perform the default DE procedure. */
			virtual void Execute(void);

			/** Breakdown of DE steps. */
			virtual void Init();
			virtual void Finalize();

			/** Returns true if the final iteration was not reached.*/
			virtual bool Iterate(unsigned int iterations);

			/** Return the fitness of the best individual in the population. */
			double BestFitness(void) const {return m_Gbfit;};

			/** Getters and setters. */
			void PrintFrequency(const unsigned int i) {m_PrintFrequency = i;};
			void C(const double c) {m_C = c;};
			void F(const double f) {m_F = f;};
			void SelectionType(const t_DESelectionType type) { m_SelectionType = type; };
			t_DESelectionType SelectionType(void) const { return m_SelectionType; };
			void MutationType(const t_DEMutationType sel) { m_MutationType = sel; };
			t_DEMutationType MutationType(void) const { return m_MutationType; };
			void MigrationType(const t_DEMigrationType mig) { m_MigrationType = mig; };
			t_DEMigrationType MigrationType(void) const { return m_MigrationType; };
			void CrossoverType(const t_DECrossoverType mig) { m_CrossoverType = mig; };
			t_DECrossoverType CrossoverType(void) const { return m_CrossoverType; };
			void MaxTime(const unsigned int sec) { m_MaxTime = sec; };
			void MaxGenerations(const unsigned int maxx) { m_MaxGenerations = maxx; };
			void MaxEvaluations(const unsigned int maxx) { m_MaxEvaluations = maxx; };
			void SetRange(double lower, double upper) {m_LowerBound = lower; m_UpperBound = upper;};
			void Iteration(const unsigned int val = 0) {m_Iteration = val;};

			/**
			 * Exchange vectors with another instance of compatible arg::cDE.
			 *
			 * \param[in, out] other_pop 	- another population
			 * \param[in] vecs				- number of vectors to exchange (must be less than 1/2 of
			 * 								  the smaller population)
			 * \param[in] one_way			- if true, vectors are only sent to other_pop. Otherwise both
			 * 								  fetched and sent.
			 * */
			void ExchangeVectors(cDE* other_pop, const unsigned int vecs, const bool one_way = false);

			/** Return the best individual in the population. */
			cArrayConst<double> Winner(void);

			virtual ~cDE();
	};
}

#endif /* CDE_H_ */

