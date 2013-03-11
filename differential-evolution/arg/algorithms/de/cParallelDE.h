/**
 * \class cParallelDE
 * \brief A simple parallel differential evolution
 *
 * A simple parallel differential evolution implemented according to (text describes parallel GA):
 * E. Alba, E.-G. Talbi, G. Luque, and N. Melab, Metaheuristics and Parallelism.
 * John Wiley & Sons, Inc., 2005, pp. 79–103. [Online]. Available: http://dx.doi.org/10.1002/0471739383.ch4
 *
 * The class expects all cDE's to be fully set up before calling AddDE. The class does not delete
 * cDE's it used unless DeleteDEs is explicitly called.
 *
 * Only single migration strategy is implemented in version 1.0 (and m_ParallelMigrationType is
 * therefore unused in version 1).
 *
 *
 * \author Pavel Krömer (c) 2013
 *
 * \version 1.0
 *
 * \b History:
 * 		- 201303,	pkromer,	initial version
 */

#ifndef CPARALLELDE_H_
#define CPARALLELDE_H_

#include <arg/algorithms/de/cDE.h>

namespace arg
{
	class cParallelDE : public arg::cDebuggable
	{
		public:
			typedef enum {PARALLEL_MIGRATION_RING = 0}	t_ParallelDEMigrationType;

		private:
			arg::cArrayConst<arg::cDE*> m_Islands;

			unsigned int m_MigrationGap;					///< Number of generations between vector migration
			unsigned int m_MigrationRate;					///< Number of vectors to exchange between islands
			unsigned int m_MaxIterations;					///< Number of max iterations

			t_ParallelDEMigrationType m_ParallelMigrationType;	///< Type of vector migration.

		public:
			cParallelDE(const unsigned int gap, const unsigned int rate, const unsigned int max_iter);

			inline void AddDE(arg::cDE * item);
			inline void AddDE(arg::cArrayConst<arg::cDE *> & items);
			inline void DeleteDEs(void);

			void ParallelMigrationType(const t_ParallelDEMigrationType val) {m_ParallelMigrationType = val;};

			void Execute(void);
			void Migrate(void);

			arg::cArrayConst<double> Winner(void);

			virtual ~cParallelDE(void);
	};

	inline void cParallelDE::AddDE(arg::cDE* item)
	{
		m_Islands.Append(item);
	}

	inline void cParallelDE::AddDE(arg::cArrayConst<arg::cDE *> & items)
	{
		m_Islands.Add(items);
	}

	inline void cParallelDE::DeleteDEs(void)
	{
		for (unsigned int i = 0; i < m_Islands.Count(); i++)
		{
			delete m_Islands[i];
		}
		m_Islands.Clear();
	}
}

#endif /* CPARALLELDE_H_ */
