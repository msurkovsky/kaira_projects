
#include "cAntFactory.h"

cAntFactory::cAntFactory(void) :
	m_Pheromones(NULL)
{
}

void cAntFactory::PrintArray(const double* array, const unsigned int x, const unsigned int y) const
{
	for (unsigned long l = 0; l < x; l++)
	{
		for (unsigned long k = 0; k < y; k++)
		{
			std::cout << std::fixed << std::setprecision(3) << array[l * y + k] << " ";
		}
		std::cout << std::endl;
	}
}

void const cAntFactory::PrintPheronomens(void) const
{
	PrintArray(m_Pheromones, m_GraphDim, m_GraphDim);
}

cAnt * cAntFactory::Configure(cAnt * ant) const
{
	ant->Power(m_Power);
	if (IsDebugging())
		ant->Debug();
	return ant;
}
