
#include "cAntColony.h"

cAntColony::cAntColony() {
    printf("Call empty constructor of cAntColony.\n");
    cAntColony(NULL, 0);
}

cAntColony::cAntColony(cAntFactory * factory, const unsigned int ant_cnt) :
	m_Factory(factory), m_AntCnt(ant_cnt), m_GlobalBestAnt(NULL), m_Minimize(false), m_MaxMin(0)
{
	m_RoundBestBoost = 5;
	m_GlobalBestBoost = 10;
	m_Alpha = 1;
	m_Beta = 1;
	m_Rho = 0.1;
    m_BestAntIdx = 0;
	Populate();
}

void cAntColony::Alpha(const double val)
{
	m_Alpha = val;
	for (unsigned int i = 0; i < m_AntCnt; i++)
	{
		m_Antz[i]->Alpha(val);
	}
}

void cAntColony::Beta(const double val)
{
	m_Beta = val;
	for (unsigned int i = 0; i < m_AntCnt; i++)
	{
		m_Antz[i]->Beta(val);
	}
}

void cAntColony::Rho(const double val)
{
	m_Rho = val;
	for (unsigned int i = 0; i < m_AntCnt; i++)
	{
		m_Antz[i]->Rho(val);
	}
}

void cAntColony::GoForward(void)
{
    #pragma omp parallel for
	for (unsigned int i = 0; i < m_AntCnt; i++)
	{
//        printf("%d. thread: %d\n", i, omp_get_thread_num());
		m_Antz[i]->GoForward();
	}
}


void cAntColony::ComputeFitness(void)
{
    double *m_Fitnesses = new double[m_AntCnt];

    #pragma omp parallel for
	for (unsigned int i = 0; i < m_AntCnt; i++)
	{
//        printf("i: %d. thread: %d\n", i, omp_get_thread_num());
		m_Fitnesses[i] = m_Antz[i]->ComputeFitness();
	}

	m_BestAntIdx = 0;
	m_BestAntFitness = m_Fitnesses[0];
    for (unsigned int i = 1; i < m_AntCnt; i++)
	{
		// Find best ant in this round
		if ((m_Minimize && (m_Fitnesses[i] < m_BestAntFitness)) || (!m_Minimize && (m_Fitnesses[i] > m_BestAntFitness)))
		{
			m_BestAntFitness = m_Fitnesses[i];
			m_BestAntIdx = i;
		}
	}

	// Check if this ant is not the best so far
	if ((m_Minimize && (m_BestAntFitness < m_GlobalBestAntFitness)) || (!m_Minimize && (m_BestAntFitness
			> m_GlobalBestAntFitness)))
	{
		m_GlobalBestAntFitness = m_BestAntFitness;
		*m_GlobalBestAnt = *(m_Antz[m_BestAntIdx]);
	}

    dbg << "Best fitness in this round is " << m_BestAntFitness << ".\n";
    dbg << "Best fitness so far is " << m_GlobalBestAntFitness << ".\n";
}

void cAntColony::PlacePheromones(void)
{
    #pragma omp parallel for
	for (unsigned int i = 0; i < m_AntCnt; i++)
	{
//        printf("i: %d. thread: %d\n", i, omp_get_thread_num());
		// Place pheromones. The first parameter is used to 'normalize' (i.e. divide) the pheromone values.
		m_Antz[i]->PlacePheromones(m_BestAntFitness, m_Minimize);
	}
}

void cAntColony::Evaporate(void)
{
	float * pheromones = m_Factory->Pheromones();

    #pragma omp parallel for
	for (unsigned int i = 0; i < m_Factory->GraphDim() * m_Factory->GraphDim(); i++)
	{
//        printf("i: %d. thread: %d\n", i, omp_get_thread_num());
		double before = pheromones[i];
		pheromones[i] *= (1 - m_Rho);
		double after = pheromones[i];

		if (before > 0 && after <= 0)
		{
			dbg	<< "Pheromones evaporated to 0!\t" << before << "\t" << after << ". Placing min. amount.\n";
			///This operation must be done even if the m_Maxmin is not true. Otherwise, there will be errors.
			pheromones[i] = 1e-9;
		}
		else if ((after > 1e3) && (m_MaxMin != 0))
		{
			///If m_Maxmin is requested, use upper pheromone limit 1e3.
			/// \TODO parameterize better
			pheromones[i] = m_MaxMin;
		}
	}
	dbg	<< "Pheromones evaporated.\n";
}

cAnt * cAntColony::Execute(const unsigned int limit)
{
	m_GlobalBestAntFitness = m_Minimize ? ULLONG_MAX : 0;
	std::cout << "Round\ttime[ms]\tbest_fitness\n";

	arg::cTimer timer;
	timer.CpuStart();

	for (unsigned int i = 0; i < limit; i++)
	{
		GoForward();
		ComputeFitness();

		PlacePheromones();

		if (m_AcoType & ACO_ELITIST_ANT_SYSTEM_ROUND)
		{
			for (unsigned int j = 0; j < m_RoundBestBoost; j++)
			{
				m_Antz[m_BestAntIdx]->PlacePheromones(m_BestAntFitness, m_Minimize);
			}
		}
		if (m_AcoType & ACO_ELITIST_ANT_SYSTEM_GLOBAL)
		{
			for (unsigned int j = 0; j < m_GlobalBestBoost; j++)
			{
				m_GlobalBestAnt->PlacePheromones(m_BestAntFitness, m_Minimize);
			}
		}

		Evaporate();
		std::cout << i << "\t" << timer.CpuStop().CpuMillis() << "\t" << m_Antz[m_BestAntIdx]->Fitness() << std::endl;
	}
	std::cout << m_GlobalBestAnt->Fitness() << "\n";
	std::cout << "\nBest found trail:\n";
//	std::cout << m_GlobalBestAnt->Trail() << std::endl;
	std::cout << "Best ant :\n";
	m_GlobalBestAnt->Print();
	return m_GlobalBestAnt;
}

void cAntColony::StartExecution(void)
{
	m_GlobalBestAntFitness = m_Minimize ? ULLONG_MAX : 0;
	//std::cout << "Round\ttime[ms]\tbest_fitness\n";

	//timer.CpuStart();
}

void cAntColony::Execution(void)
{
//	arg::cTimer timer;
//	timer.CpuStart();
	GoForward();
//	std::cout << "GoForward: " << timer.CpuStop().CpuMillis() << std::endl;

//    timer.CpuStart();
	ComputeFitness();
//	std::cout << "ComputeFitness: " << timer.CpuStop().CpuMillis() << std::endl;

//    timer.CpuStart();
	PlacePheromones();
//	std::cout << "PlacePheromones: " << timer.CpuStop().CpuMillis() << std::endl;

//    timer.CpuStart();
	if (m_AcoType & ACO_ELITIST_ANT_SYSTEM_ROUND)
	{
		for (unsigned int j = 0; j < m_RoundBestBoost; j++)
		{
			m_Antz[m_BestAntIdx]->PlacePheromones(m_BestAntFitness, m_Minimize);
		}
	}
	if (m_AcoType & ACO_ELITIST_ANT_SYSTEM_GLOBAL)
	{
		for (unsigned int j = 0; j < m_GlobalBestBoost; j++)
		{
			m_GlobalBestAnt->PlacePheromones(m_BestAntFitness, m_Minimize);
		}
	}
//	std::cout << "Boost: " << timer.CpuStop().CpuMillis() << std::endl;

//    timer.CpuStart();
	Evaporate();
//	std::cout << "Evaporate: " << timer.CpuStop().CpuMillis() << std::endl;
	//std::cout << "\t" << timer.CpuStop().CpuMillis() << "\t" << m_Antz[m_BestAntIdx]->Fitness() << std::endl;
}

cAnt* cAntColony::EndExecution(void)
{
	std::cout << m_GlobalBestAnt->Fitness() << "\n";
	std::cout << "\nBest found trail:\n";
//	std::cout << m_GlobalBestAnt->Trail() << std::endl;
	std::cout << "Best ant :\n";
	m_GlobalBestAnt->Print();
	return m_GlobalBestAnt;
}

cAnt * cAntColony::BestAntPtr(const bool rescan)
{
	if (rescan)
	{
		m_BestAntIdx = 0;
		m_BestAntFitness = m_Antz[0]->Fitness();

		for (unsigned int i = 1; i < m_AntCnt; i++)
		{
			double ant_loot = m_Antz[i]->Fitness();
			if ((ant_loot > m_BestAntFitness && !m_Minimize) || (ant_loot < m_BestAntFitness && m_Minimize))
			{
				m_BestAntIdx = i;
			}
		}
	}
	return m_Antz[m_BestAntIdx];
}

cAnt* cAntColony::GetAnt(int val)
{
	if(val < m_Antz.Size() && val >= 0)
	{
		return m_Antz[val];
	}
	 else
	{
		return NULL;
	}
}

void cAntColony::Delete()
{
	if (m_GlobalBestAnt != NULL)
	{
		delete m_GlobalBestAnt;
		m_GlobalBestAnt = NULL;
	}

	for (unsigned int i = 0; i < m_Antz.Count(); i++)
	{
		delete m_Antz[i];
	}
	m_Antz.Clear();
}

void cAntColony::Reset()
{
	Populate();
}

void cAntColony::Populate()
{
	Delete();

	//we just need an instance ...
	m_GlobalBestAnt = m_Factory->GetInstance();
	dbg	<< "Creating " << m_AntCnt << " artificial ants.\n";
	for (unsigned int i = 0; i < m_AntCnt; i++)
	{
		cAnt * ant = m_Factory->GetInstance();
		ant->Rho(m_Rho);
		ant->Alpha(m_Alpha);
		ant->Beta(m_Beta);
		m_Antz.Append(ant);
	}
	dbg	<< "Done.\n";
}

unsigned long cAntColony::GetDim()
{
	return m_Factory->GraphDim();
}

void cAntColony::SetBestAntTrail(const unsigned long *trail, double fitness) {
	m_GlobalBestAnt->SetTrail(trail);
    m_GlobalBestAntFitness = fitness;
}

cAntColony::~cAntColony()
{
	Delete();
	delete m_Factory;
}
