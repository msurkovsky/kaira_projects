
#include "cTspAnt.h"

cTspAnt::cTspAnt(double * pheromones, const double * distances, const unsigned int graph_dim) :
	cAnt(pheromones, graph_dim, graph_dim - 1), m_Distances(distances)
{
	Symmetric(false);
}

double cTspAnt::APriori(const unsigned long from, const unsigned long to)
{
	return 1.0 / m_Distances[from * GraphDim() + to];
}

double cTspAnt::ComputeFitness(void)
{
	const arg::cArrayConst<unsigned long> & trail = Trail();

	double dist = 0;

	for (unsigned int i = 0; i < trail.Count() - 1; i++)
	{
		dist += m_Distances[trail[i] * GraphDim() + trail[i + 1]];
	}
        //dist += m_Distances[trail[trail.Count() - 1] * GraphDim() + trail[0]];
	return m_Fitness = dist;
}

double cTspAnt::Test(const int * trail, const unsigned int length, const int add) const
{
	double dist = 0;

	//1. Verify that it really is a valid trail
	for (unsigned int i = 0; i < length; i++)
	{
		bool found = false;
		for (unsigned int j = 0; j < length; j++)
		{
			if ( (unsigned int) (trail[j] + add) == i)
			{
				found = true;
				break;
			}
		}
		if (!found) {
			std::cerr << "WRONG Trail! Missing " << i << std::endl;
		}
	}

	//2. Compute the distance
	for (unsigned int i = 0; i < length - 1; i++)
	{
		dist += m_Distances[(trail[i] + add) * GraphDim() + (trail[i + 1] + add)];
	}
	return dist;
}
