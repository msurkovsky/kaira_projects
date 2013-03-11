#include "cParallelDE.h"

using namespace arg;

cParallelDE::cParallelDE(const unsigned int gap, const unsigned int rate, const unsigned int max_iter) :
		m_MigrationGap(gap), m_MigrationRate(rate), m_MaxIterations(max_iter)
{
}

void cParallelDE::Execute()
{
	dbg << "Initializing all islands.\n";
	for (unsigned int i = 0; i < m_Islands.Count(); i++)
	{
		m_Islands[i]->Init();
	}

	dbg << "Starting main loop.\n";
	for (unsigned int iteration = 0; iteration < m_MaxIterations; iteration += m_MigrationGap)
	{
		for (unsigned int i = 0; i < m_Islands.Count(); i++)
		{
			dbg << "Evolving island " << i << ".\n";
			m_Islands[i]->Iterate(m_MigrationGap);
		}
		Migrate();
	}

	dbg << "Finalizing islands.\n";
	for (unsigned int i = 0; i < m_Islands.Count(); i++)
	{
		m_Islands[i]->Finalize();
	}
}

void cParallelDE::Migrate()
{
	dbg << "Migrating vectors between islands.\n";
	// simple 'circular' migration
	for (int i = m_Islands.Count() - 2; i >= 0; i--)
	{
		dbg << "Migrating " << i << " -> " << i+1<< " done.\n";
		m_Islands[i]->ExchangeVectors(m_Islands[i + 1], m_MigrationRate, true);
		dbg << "Done.\n";
	}

	m_Islands[m_Islands.Count() - 1]->ExchangeVectors(m_Islands[0], m_MigrationRate, true);
	dbg << "Migration finished.\n";
}

arg::cArrayConst<double> cParallelDE::Winner()
{
	if (m_Islands.Count() > 0)
	{
		unsigned int idx = 0;
		double fit = m_Islands[0]->BestFitness();

		for (unsigned int i = 1; i < m_Islands.Count(); i++)
		{
			if (m_Islands[i]->BestFitness() < fit)
			{
				fit = m_Islands[i]->BestFitness();
				idx = i;
			}
		}
		return m_Islands[idx]->Winner();
	}
	arg::cArrayConst<double> dummy;
	return dummy;
}

cParallelDE::~cParallelDE()
{
}
