#include "cTspAntFactory.h"

using namespace std;

cTspAntFactory::cTspAntFactory(const char * fname) :
	m_Distances(NULL)
{
	ifstream in(fname);

	if (in.is_open())
	{
		in >> m_GraphDim;
		arg::cArrayConst<t_Pair> cities;
		t_Pair city;
		for (unsigned int i = 0; i < m_GraphDim; i++)
		{
			unsigned int id;
			in >> id; //ignored
			in >> city.x;
			in >> city.y;
			cities.Append(city);
		}

		m_Distances = new double[m_GraphDim * m_GraphDim];
		m_Pheromones = new double[m_GraphDim * m_GraphDim];

		for (unsigned int i = 0; i < m_GraphDim; i++)
		{
			const t_Pair & city_i = cities[i];

			for (unsigned int j = 0; j < m_GraphDim; j++)
			{
				if (i == j)
				{
					m_Pheromones[i * m_GraphDim + j] = 0;
					m_Distances[i * m_GraphDim + j] = 0;
				}
				else
				{
					const t_Pair & city_j = cities[j];
					const double dist_ij = sqrt((city_i.x - city_j.x) * (city_i.x - city_j.x) + (city_i.y - city_j.y)
							* (city_i.y - city_j.y));
					m_Pheromones[i * m_GraphDim + j] = 0.1;
					m_Distances[i * m_GraphDim + j] = dist_ij;
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
	PrintArray(m_Distances, m_GraphDim, m_GraphDim);
}

cAnt * cTspAntFactory::GetInstance(void)
{
	return Configure(new cTspAnt(m_Pheromones, m_Distances, m_GraphDim));
}

cTspAntFactory::~cTspAntFactory()
{
	if (m_Distances != NULL)
	{
		delete[] m_Distances;
	}
}

