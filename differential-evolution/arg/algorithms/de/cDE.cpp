#include "cDE.h"

using namespace arg;

cDE::cDE(const unsigned int pop_size, const unsigned int vector_length, const unsigned int max_gen)
{
	m_PopulationSize = pop_size;
	m_VectorLength = vector_length;
	m_MutationType = MUTATION_CLASSIC;
	m_SelectionType = SELECTION_RAND;
	m_MigrationType = MIGRATION_CLASSIC;
	m_CrossoverType = CROSSOVER_RANDOMIZED;
	m_MaxGenerations = max_gen;
	m_MaxEvaluations = 0;
	m_LowerBound = 0;
	m_UpperBound = 1;
	m_C = 0.9;
	m_F = 0.9;
	m_PrintFrequency = (unsigned int) -1;
	m_Iteration = m_MaxTime = 0;
	m_Initialized = false;

	m_Population = new double[m_PopulationSize * m_VectorLength];
	m_AuxPopulation = new double[m_PopulationSize * m_VectorLength];

	m_Random = cRandom::GetInstance();

	unsigned int seed = (const unsigned int) time(NULL) & cStaticRandom::NextInt(10000);
	dbg << " ["<< this << "] Seeding rng with: " << seed << ".\n";
	m_Random->Seed(&seed);

	dbg << "Initial population of " << m_PopulationSize << "x" << m_VectorLength << " created.\n";
}

void cDE::CheckRange(cArrayConst<double> & u)
{
	for (unsigned int i = 0; i < u.Count(); i++)
	{
		if (u[i] < m_LowerBound)
		{
			u[i] = m_LowerBound;
		}
		else if (u[i] > m_UpperBound)
		{
			u[i] = m_UpperBound;
		}
	}
}

void cDE::InitPopulation(double * m)
{
	for (unsigned int i = 0; i < m_PopulationSize; i++)
	{
		for (unsigned int j = 0; j < m_VectorLength; j++)
		{
			m[i * m_VectorLength + j] = m_Random->Next(m_LowerBound, m_UpperBound);
		}
	}
	dbg << "Population initialized with random numbers from the range [" << m_LowerBound << "," << m_UpperBound
			<< "].\n";
}

void cDE::Print(double * data)
{
	for (unsigned int i = 0; i < m_PopulationSize; i++)
	{
		for (unsigned int j = 0; j < m_VectorLength; j++)
		{
			std::cout << data[i * m_VectorLength + j];
		}
		std::cout << std::endl;
	}
}

void cDE::Evaluate(double * p, cArrayConst<double> & result)
{
	unsigned int N = m_PopulationSize;

	const unsigned int cols = m_VectorLength;

	for (unsigned int i = 0; i < N; i++)
	{
		double * row = p + i * m_VectorLength;
		result[i] = ComputeFitness(row, cols);
	}

	dbg << "Population evaluated to " << result << ".\n";
}

void cDE::Crossover(cArrayConst<double> & xi, const double C, cArrayConst<double> & u)
{
	unsigned int l = m_Random->NextInt(xi.Count());
	for (unsigned int j = 0; j < xi.Count(); j++)
	{
		double Uj = m_Random->Next(1);
		if ((j != l) && (Uj > C))
		{
			u[j] = xi[j];
		}
		else if (m_CrossoverType == CROSSOVER_RANDOMIZED)
		{
			u[j] *= m_Random->Next(1);
		}
	}
}

double cDE::MinFitness(unsigned int & idx)
{
	double minn = INT_MAX;
	idx = 0;

	for (unsigned int i = 0; i < m_Fitness.Count(); i++)
	{
		const double current = m_Fitness[i];
		if (current < minn)
		{
			minn = current;
			idx = i;
		}
	}

	return minn;
}

void cDE::Init()
{
	InitDE();
	dbg << "Init DE finished.\n";

	m_Gbfit = LONG_MAX;
	m_Gbidx = (unsigned int) -1;

	InitPopulation(m_Population);
	memcpy(m_AuxPopulation, m_Population, sizeof(double) * m_PopulationSize * m_VectorLength);

	m_Timer.CpuStart();
	m_Timer.StartTicking(m_MaxTime);

	m_Fitness.Resize(m_PopulationSize, m_PopulationSize);

	Evaluate(m_Population, m_Fitness);
	m_CurrentEvaluation = m_PopulationSize;
	m_Gbfit = MinFitness(m_Gbidx);
	m_Initialized = true;
	m_Iteration = 0;
}

void cDE::KairaIntegrateVector(double *vector, double *fitness) {
    cArrayConst<t_FitnessIndexPair> population_info;
    this->SortPopulation(population_info);

    int count = m_PopulationSize * 0.1;

    int exchange_idx;
    double *pv = vector;
    for (int i = 0; i < count; i++) {
        exchange_idx = population_info[m_PopulationSize-i-1].idx;
        if (fitness[i] < m_Fitness[exchange_idx]) {

            memcpy(&m_Population[exchange_idx * m_VectorLength],
                   pv, m_VectorLength*sizeof(double));

            m_Fitness[exchange_idx] = fitness[i];
            if (m_Fitness[exchange_idx] < m_Gbfit) {
                m_Gbfit = m_Fitness[exchange_idx];
                m_Gbidx = exchange_idx;
            }
            pv += m_VectorLength;
        }
    }
}

void cDE::KairaExecute() {

    if (!m_Initialized) {
        err << "Initialize must be called prior to Iterate.\n";
    } else {
        double C = m_C;
		double Fj = m_F;

		cArrayConst<double> u;
		u.Resize(m_VectorLength, m_VectorLength);
		cArrayConst<double> xi;
		xi.Resize(m_VectorLength, m_VectorLength);

        // m_AuxPopulation acts as V^t (read-only), m_Population as V^{t+1} (write-only)
		double *tmp = m_AuxPopulation;
		m_AuxPopulation = m_Population;
		m_Population = tmp;

		unsigned int r1, r2, r3;

		if (m_MutationType == MUTATION_INVERSE && m_Iteration < m_MaxGenerations) /// 50)
		{
			C = 1.0 / m_Gbfit;
		}

		for (unsigned int i = 0; i < m_PopulationSize; i++)
		{
			//1. select vectors
			r1 = r2 = r3 = i;

			if (m_SelectionType == SELECTION_BEST)
			{
				r1 = m_Gbidx; //DE/best
				Fj = Fj + 0.00001 * (m_Random->Next(1) - 0.5);
			}
			else
			{
				r1 = m_Random->NextInt(m_PopulationSize - 1); //DE/rand
			}

			r2 = m_Random->NextInt(m_PopulationSize - 1);
			while ((r1 == r2) || (r2 == i))
			{
				r2 = (r2 + 1) % m_PopulationSize;
			}

			r3 = m_Random->NextInt(m_PopulationSize - 1);
			while ((r2 == r3) || (r1 == r3) || (i == r3))
			{
				r3 = (r3 + 1) % m_PopulationSize;
			}

			//2. mutate
			if (m_MutationType == MUTATION_TARGET_TO_BEST)
			{
				MutationTargetToBest(u, m_AuxPopulation, i, Fj, r2, r3);
			}
			else if (m_MutationType == MUTATION_EITHER_OR)
    		{
				MutationEitherOr(u, m_AuxPopulation, Fj, r1, r2, r3);
			}
			else
			{
				MutationStandard(u, m_AuxPopulation, Fj, r1, r2, r3);
			}

			// 3. crossover
			memcpy(xi.GetArray(0), m_AuxPopulation + i * m_VectorLength, m_VectorLength * sizeof(double));
			Crossover(xi, C, u);

			CheckRange(u);

			//4. trial
			double score = ComputeFitness(u.GetArray(0), u.Count());
			m_CurrentEvaluation++;
			if (score < m_Fitness[i])
			{
				memcpy(m_Population + i * m_VectorLength, u.GetArray(0), m_VectorLength * sizeof(double));
				m_Fitness[i] = score;
				if (m_Gbfit > score)
				{
					m_Gbfit = score;
					m_Gbidx = i;
				}
			}
			/*else if (m_MigrationType == MIGRATION_ELITISM)
			{
				unsigned int minIdx;

				double minScore = MinFitness(minIdx);

				if (minScore < score)
				{
					memcpy(m_Population + minIdx * m_VectorLength, u.GetArray(0), m_VectorLength * sizeof(double));
				}
			}*/
		}
    }
}

bool cDE::Iterate(const unsigned int iterations)
{
	if (!m_Initialized)
	{
		err << "Initialize must be called prior to Iterate.\n";
	}
	else
	{
		double C = m_C;
		double Fj = m_F;

		cArrayConst<double> u;
		u.Resize(m_VectorLength, m_VectorLength);
		cArrayConst<double> xi;
		xi.Resize(m_VectorLength, m_VectorLength);
		PrintPopInfo(m_Iteration);

		for (unsigned int i = 0; i < iterations; i++)
		{
			// m_AuxPopulation acts as V^t (read-only), m_Population as V^{t+1} (write-only)
			double *tmp = m_AuxPopulation;
			m_AuxPopulation = m_Population;
			m_Population = tmp;

			unsigned int r1, r2, r3;

			if (m_MutationType == MUTATION_INVERSE && m_Iteration < m_MaxGenerations) /// 50)
			{
				C = 1.0 / m_Gbfit;
			}

			for (unsigned int i = 0; i < m_PopulationSize; i++)
			{
				//1. select vectors
				r1 = r2 = r3 = i;

				if (m_SelectionType == SELECTION_BEST)
				{
					r1 = m_Gbidx; //DE/best
					Fj = Fj + 0.00001 * (m_Random->Next(1) - 0.5);
				}
				else
				{
					r1 = m_Random->NextInt(m_PopulationSize - 1); //DE/rand
				}

				r2 = m_Random->NextInt(m_PopulationSize - 1);
				while ((r1 == r2) || (r2 == i))
				{
					r2 = (r2 + 1) % m_PopulationSize;
				}

				r3 = m_Random->NextInt(m_PopulationSize - 1);
				while ((r2 == r3) || (r1 == r3) || (i == r3))
				{
					r3 = (r3 + 1) % m_PopulationSize;
				}

				//2. mutate
				if (m_MutationType == MUTATION_TARGET_TO_BEST)
				{
					MutationTargetToBest(u, m_AuxPopulation, i, Fj, r2, r3);
				}
				else if (m_MutationType == MUTATION_EITHER_OR)
				{
					MutationEitherOr(u, m_AuxPopulation, Fj, r1, r2, r3);
				}
				else
				{
					MutationStandard(u, m_AuxPopulation, Fj, r1, r2, r3);
				}

				// 3. crossover
				memcpy(xi.GetArray(0), m_AuxPopulation + i * m_VectorLength, m_VectorLength * sizeof(double));
				Crossover(xi, C, u);

				CheckRange(u);

				//4. trial
				double score = ComputeFitness(u.GetArray(0), u.Count());
				m_CurrentEvaluation++;
				if (score < m_Fitness[i])
				{
					memcpy(m_Population + i * m_VectorLength, u.GetArray(0), m_VectorLength * sizeof(double));
					m_Fitness[i] = score;
					if (m_Gbfit > score)
					{
						m_Gbfit = score;
						m_Gbidx = i;
						PrintPopInfo(m_Iteration);
					}
				}
				else if (m_MigrationType == MIGRATION_ELITISM)
				{
					unsigned int minIdx;

					double minScore = MinFitness(minIdx);

					if (minScore < score)
					{
						memcpy(m_Population + minIdx * m_VectorLength, u.GetArray(0), m_VectorLength * sizeof(double));
					}
				}

				if (i == 0 && m_Iteration % m_PrintFrequency == 0)
				{
					PrintPopInfo(m_Iteration);
				}

				if (m_MaxEvaluations > 0 && m_CurrentEvaluation >= m_MaxEvaluations)
				{
					break;
				}
			}
			m_Iteration++;

			if (m_Iteration > m_MaxGenerations)
			{
				dbg << "Generation limit reached.\n";
				break;
			}

			if (m_MaxEvaluations > 0 && m_CurrentEvaluation >= m_MaxEvaluations)
			{
				dbg << "Fitness function evaluation limit reached.\n";
				break;
			}

			if (m_MaxTime > 0 && !m_Timer.IsTicking())
			{
				dbg << "DE finished due to time limit.\n";
				break;
			}
		}
		PrintPopInfo(m_Iteration);
	}
	return m_Iteration < m_MaxGenerations;
}

void cDE::Finalize()
{
	FinalizeDE();
	dbg << "Finalize DE finished.\n";
}

void cDE::Execute()
{
	Init();
	Iterate(m_MaxGenerations);
	Finalize();
}

void cDE::PrintPopInfo(int cnt)
{
	std::cout << cnt << "\t" << m_CurrentEvaluation << "\t" << m_Timer.CpuStop().CpuMillis() << "\t" << m_Gbfit << "\t"
			<< m_Gbidx << std::endl;
}

unsigned int cDE::SelectVector(const unsigned int tabu, const unsigned int tabu2)
{
	double maxx = 0;
	double fitSum = 0;

	for (unsigned int i = 0; i < m_Fitness.Count(); i++)
	{
		const double current = m_Fitness[i];
		fitSum += current;

		if (current > maxx)
			maxx = current;
	}

	double score = m_Random->Next(fitSum);
	unsigned int selected = 0;

	do
	{
		fitSum = 0;
		for (unsigned int i = 0; i < m_Fitness.Count(); i++)
		{
			fitSum += (maxx - m_Fitness[i]);
			if (score < fitSum)
			{
				selected = i;
				break;
			}
		}
	} while (selected == tabu || selected == tabu2);
	return selected;
}

cArrayConst<double> cDE::Winner(void)
{
	cArrayConst<double> result;
	double * winner = m_Population + m_Gbidx * m_VectorLength;

	for (unsigned int i = 0; i < m_VectorLength; i++)
		result.Append(winner[i]);

	return result;
}

void cDE::MutationTargetToBest(cArrayConst<double> & u, double * P, const unsigned i, const double Fj,
		const unsigned int r2, const unsigned int r3)
{
	// u = P.get_row(i) + Fj * (P.get_row(m_Gbidx) - P.get_row(i)) + Fj * (P.get_row(r2) - P.get_row(r3));

	double * Pi = P + i * m_VectorLength;
	double * Pgbidx = P + m_Gbidx * m_VectorLength;
	double * Pr2 = P + r2 * m_VectorLength;
	double * Pr3 = P + r3 * m_VectorLength;

	for (unsigned int j = 0; j < m_VectorLength; j++)
	{
		u[j] = Pi[j] + Fj * (Pgbidx[j] - Pi[j]) + Fj * (Pr2[j] - Pr3[j]);
	}
}

void cDE::MutationStandard(cArrayConst<double> & u, double * P, const double Fj, const unsigned int r1,
		const unsigned int r2, const unsigned int r3)
{
	// u = P.get_row(r1) + Fj * (P.get_row(r2) - P.get_row(r3));

	double * Pr1 = P + r1 * m_VectorLength;
	double * Pr2 = P + r2 * m_VectorLength;
	double * Pr3 = P + r3 * m_VectorLength;

	for (unsigned int j = 0; j < m_VectorLength; j++)
	{
		u[j] = Pr1[j] + Fj * (Pr2[j] - Pr3[j]);
	}
}

void cDE::MutationEitherOr(cArrayConst<double> & u, double * P, const double Fj, const unsigned int r1,
		const unsigned int r2, const unsigned int r3)
{
	double * Pr1 = P + r1 * m_VectorLength;
	double * Pr2 = P + r2 * m_VectorLength;
	double * Pr3 = P + r3 * m_VectorLength;

	double rnd = m_Random->Next(1);

	if (rnd < m_F)
	{
		MutationStandard(u, P, Fj, r1, r2, r3);
	}
	else
	{
		for (unsigned int j = 0; j < m_VectorLength; j++)
		{
			u[j] = Pr1[j] + 0.5 * (Fj + 1) * (Pr2[j] + Pr3[j] - 2 * Pr1[j]);
		}
		// u = P.get_row(r1) + 0.5 * (Fj + 1) * (P.get_row(r2) + P.get_row(r3) - 2 * P.get_row(r1));
	}
}

int cDE::CompareVectors(const void* x, const void* y)
{
	t_FitnessIndexPair a = *((t_FitnessIndexPair *) x);
	t_FitnessIndexPair b = *((t_FitnessIndexPair *) y);

	double diff = a.fit - b.fit;

	unsigned int result = 0;
	if (diff < 0)
	{
		result = -1;
	}
	else if (diff > 0)
	{
		result = 1;
	}

	return result;
}

void cDE::SortPopulation(cArrayConst<t_FitnessIndexPair> &indexes)
{
	indexes.Clear();
	t_FitnessIndexPair item;
	for (unsigned int i = 0; i < m_PopulationSize; i++)
	{
		item.fit = m_Fitness[i];
		item.idx = i;
		indexes.Add(&item);
	}

	qsort(indexes.GetArray(0), indexes.Count(), sizeof(t_FitnessIndexPair), CompareVectors);

	if (IsDebugging())
	{
		dbg << "Sorted population is:\n";
		for (unsigned int i = 0; i < indexes.Count(); i++)
		{
			_dbg << "\t" << indexes[i].fit << "\t" << indexes[i].idx << "\n";
		}
	}
}

void cDE::ExchangeVectors(cDE* other_pop, const unsigned int vecs, const bool one_way)
{
	if (m_VectorLength != other_pop->m_VectorLength)
	{
		err << "Cannot swap vectors between incompatible populations (m_VectorLength is not the same). Skipping.\n";
	}
	else
	{
		// exchange at most half of the population
		unsigned int n =
				m_PopulationSize < other_pop->m_PopulationSize ? m_PopulationSize : other_pop->m_PopulationSize;
		if (vecs > n / 2)
		{
			err << "Number of vectors to exchange (" << vecs << ") is more than a half of smaller population (" << n
					<< "). Exchanging " << n / 2 << " vectors.\n";
			n = n / 2;
		}
		else
		{
			n = vecs;
		}

		dbg << "Sorting this population.\n";
		cArrayConst<t_FitnessIndexPair> my_info;
		SortPopulation((my_info));

		dbg << "Sorting other population.\n";
		cArrayConst<t_FitnessIndexPair> other_info;
		other_pop->SortPopulation(other_info);

		//3. exchange vectors
		for (unsigned int i = 0; i < n; i++)
		{
			unsigned int idx;
			if (!one_way)
			{
				// from there to here
				idx = my_info[m_PopulationSize - 1 - i].idx;
				memcpy(&m_Population[idx * m_VectorLength],
						&other_pop->m_Population[other_info[i].idx * m_VectorLength], m_VectorLength * sizeof(double));
				m_Fitness[idx] = other_info[i].fit;
				if (m_Fitness[idx] < m_Gbfit)
				{
					m_Gbfit = m_Fitness[idx];
					m_Gbidx = idx;
				}
			}

			// from here to there
			idx = other_info[other_pop->m_PopulationSize - 1 - i].idx;
			dbg << "Indexes for migration are " << my_info[i].idx << " " << idx << ".\n";
			memcpy(&other_pop->m_Population[idx * m_VectorLength], &m_Population[my_info[i].idx * m_VectorLength],
					m_VectorLength * sizeof(double));
			other_pop->m_Fitness[idx] = my_info[i].fit;
			if (other_pop->m_Fitness[idx] < other_pop->m_Gbfit)
			{
				other_pop->m_Gbfit = other_pop->m_Fitness[idx];
				other_pop->m_Gbidx = idx;
			}
		}

		if (IsDebugging())
		{
			if (!one_way)
			{
				dbg << "Sorting updated population.\n";
				SortPopulation(other_info);
			}
			dbg << "Sorting updated other_population.\n";
			other_pop->SortPopulation(other_info);
		}
	}
}

cDE::~cDE()
{
	if (m_Population != NULL)
		delete[] m_Population;

	if (m_AuxPopulation != NULL)
		delete[] m_AuxPopulation;

	delete m_Random;
}
