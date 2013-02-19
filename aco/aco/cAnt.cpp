
#include "cAnt.h"

cAnt::cAnt(double * pheromones, const unsigned int graph_dim, const unsigned int trail_length, const double power) :
	m_TrailLength(trail_length), m_GraphDim(graph_dim), m_Pheromones(pheromones), m_Symmetric(true), m_Power(power)
{
	m_Visited.Resize(m_GraphDim);
	m_Alpha = 1;
	m_Beta = 1;
	m_Rho = 0.1;
}

void cAnt::ClearVisited(void)
{
	for (unsigned int i = 0; i < m_GraphDim; i++)
	{
		m_Visited[i] = false;
	}
}

unsigned long cAnt::StartNode(void) const
{
	return arg::cRandom::NextInt(m_GraphDim - 1);
}

void cAnt::GoForward()
{
	dbg	<< "Starting trail of " << m_TrailLength << " steps on graph with " << m_GraphDim << " nodes.\n";
	ClearVisited();
	m_DeadEnd = false;
	m_Trail.Clear();
	m_Fitness = 0;
	m_Position = StartNode();
	for (unsigned int i = 0; i < m_TrailLength && !m_DeadEnd; i++)
	{
		StepForward();
	}
	m_Trail.Append(m_Position);

	dbg	<< "This ant went " << m_Trail << "\n";
}

long cAnt::NextPosition(void)
{
	dbg	<< "Old position is " << m_Position << ".\n";

	//0. no. of nodes
	int N = m_GraphDim;
	dbg	<< "Pheromone matrix has " << N << " rows.\n";

	arg::cArrayConst<unsigned long> Nik;

	//1. create Nik
	unsigned long offset = m_Position * m_GraphDim;
	for (unsigned int i = 0; i < m_GraphDim; i++)
	{
		if (m_Pheromones[offset + i] > 0 && !m_Visited[i])
		{
			Nik.Append(i);
		}
		else
		{
			dbg	<< "Node " << i << " is unreachable or it has been visited.\n";
		}
	}


	if (Nik.Count() == 0)
	{
		dbg	<< "This ant has no reachable nodes.\n";
		m_DeadEnd = true;
		return -1;
	}
	else
	{
		dbg	<< "Possible moves: " << Nik << "\n";
	}

	//2. create an empty vector pij
	arg::cArrayConst<double> pij;
	for (unsigned int i = 0; i < Nik.Count(); i++)
	{
		pij.Append(0);
	}

	//3. create sum tilnil
	double sum = 0;
	dbg	<< "Alpha is " << m_Alpha << ".\n";
	for (unsigned int i = 0; i < Nik.Count(); i++)
	{
		int idx = Nik[i];

		double bit = pow(m_Pheromones[m_Position * m_GraphDim + idx], m_Alpha) + pow(APriori(m_Position, idx), m_Beta);
		dbg	<< "Bit for " << m_Position << ", " << idx << " is " << bit << ".\n";
		sum += bit;
		pij[i] = bit;
	}
	dbg	<< "Sum is: " << sum << ".\n";

	//4. fill pij with the probability
	for (unsigned int i = 0; i < Nik.Count(); i++)
	{
		pij[i] = pij[i] / (sum);
	}

	dbg	<< "Probabilities pij are " << pij << ".\n";

	//5. pick randomly the node
	double rnd = arg::cRandom::Next(1);
	int result = pij.Count() - 1;

	for (unsigned int i = 0; i < pij.Count(); i++)
	{
		if (rnd < pij[i])
		{
			result = Nik[i];
			break;
		}
		else
		{
			rnd -= pij[i];
		}
	}

	dbg	<< "Selected next node " << result << ".\n";

	return result;
}

void cAnt::StepForward()
{
	dbg	<< "Current position " << m_Position << ".\n";
	m_Trail.Append(m_Position);
	m_Visited[m_Position] = true;
	m_Position = NextPosition();
}

void cAnt::PlacePheromones(const double normalize_pheromones, const bool minimize)
{
	unsigned int n = m_Trail.Count();

	dbg	<< "Final loot is " << m_Fitness << ".\n";

	//1. normalize pheromones
	double fit = m_Fitness;

	if (normalize_pheromones > 0)
	{
		dbg	<< "Pheromones normalized with " << normalize_pheromones << ".\n";
		fit = fit / normalize_pheromones;
		dbg	<< "Pheromones value is " << fit << ".\n";
	}

	if (minimize)
	{
		fit = 1.0 / fit;
		dbg	<< "Pheromones changed for minimization to " << fit << ".\n";
	}

	double deltaTij = 0;

	if (m_Power != 0)
	{
		// Use the power update.
		deltaTij = pow(fit, m_Power);
	}
	else
	{
		// Use the traditional update.
		deltaTij = fit;
	}

	dbg	<< this << " DeltaTij is " << deltaTij << ".\n";

	//2. place pheromones
	dbg	<< "This ant has trail: " << m_Trail << ".\n";

	for (unsigned int i = 0; i < n - 1; i++)
	{
		unsigned long x = m_Trail[i];
		unsigned long y = m_Trail[i + 1];

		m_Pheromones[x * m_GraphDim + y] += deltaTij;
		if (m_Symmetric)
		{
			m_Pheromones[y * m_GraphDim + x] += deltaTij;
		}
	}
}

void cAnt::SetTrail(const unsigned long *trail) {
	for(unsigned int i = 0 ; i < m_Trail.Count() ; i++){
		m_Trail[i] = trail[i];
	}
	ComputeFitness();
}
