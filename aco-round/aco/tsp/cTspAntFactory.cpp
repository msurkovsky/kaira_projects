#include "cTspAntFactory.h"

using namespace std;

cTspAntFactory::cTspAntFactory(const char * fname)
//	m_Distances(NULL)
{
	ifstream in(fname);

	if (in.is_open())
	{
		in >> m_GraphDim;
//		t_Pair city;
		for (unsigned int i = 0; i < m_GraphDim; i++)
		{
            std::pair<double, double> city;
			unsigned int id;
			in >> id; //ignored
			in >> city.first;
			in >> city.second;
			m_Cities.push_back(city);
		}


//		m_Distances = new double[m_GraphDim * m_GraphDim];
		m_Pheromones = new float[m_GraphDim * m_GraphDim];

		for (unsigned int i = 0; i < m_GraphDim; i++)
		{
//			const t_Pair & city_i = cities[i];
			const std::pair<double, double> &city = m_Cities[i];

			for (unsigned int j = 0; j < m_GraphDim; j++)
			{
				if (i == j)
				{
					m_Pheromones[i * m_GraphDim + j] = 0;
//					m_Distances[i * m_GraphDim + j] = 0;
				}
				else
				{
					m_Pheromones[i * m_GraphDim + j] = 0.1;
//					const t_Pair & city_j = cities[j];
//					const double dist_ij = sqrt((city_i.first - city_j.first) * (city_i.first - city_j.first) + (city_i.second - city_j.second)
//							* (city_i.second - city_j.second));
//					m_Distances[i * m_GraphDim + j] = dist_ij;
				}
			}
		}
	}
	else
	{
		err << "Could not open file \'" << fname << "\'.\n";
	}
}

void cTspAntFactory::PrintDistances(void) const
{
    printf("Print of distances is disabled.\n");
//	PrintArray(m_Distances, m_GraphDim, m_GraphDim);
}

cAnt * cTspAntFactory::GetInstance(void)
{
	return Configure(new cTspAnt(m_Pheromones, m_Cities, m_GraphDim));
}

cTspAntFactory::~cTspAntFactory()
{
//	if (m_Distances != NULL)
//	{
//		delete[] m_Distances;
//	}
}

