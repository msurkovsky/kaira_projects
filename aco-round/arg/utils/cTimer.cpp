#include "cTimer.h"

using namespace arg;

void cTimer::Start()
{
	start = clock();
	stop = 0;
}

void cTimer::Stop()
{
	stop = clock();
}

void cTimer::Reset()
{
	stop = start = 0;
}

long cTimer::Ticks()
{
	clock_t curr;
	if (stop == 0)
		curr = clock();
	else
		curr = stop;

	return (curr - start);
}

long cTimer::Milis()
{
	return Ticks() / (CLOCKS_PER_SEC / 1000);
}

long cTimer::Seconds()
{
	return Ticks() / CLOCKS_PER_SEC;
}

long cTimer::Minutes()
{
	return Seconds() / 60;
}

long cTimer::Days()
{
	return Seconds() / 86400;
}

void cTimer::CpuStart(void)
{
	gettimeofday(&m_TStart, NULL);
}

cTimer& cTimer::CpuStop(void)
{
	gettimeofday(&m_TStop, NULL);
	return *this;
}

void cTimer::StartTicking(const unsigned long sec)
{
	gettimeofday(&m_TickerStart, NULL);
	m_TickerIntervalMS = sec*1000;
}

bool cTimer::IsTicking(void) const
{
	timeval now;
	gettimeofday(&now, NULL);

	double millis = ((now.tv_sec * 1e6 + now.tv_usec) - (m_TickerStart.tv_sec * 1e6 + m_TickerStart.tv_usec)) / 1e3;
	//std::cout << "Time is " << millis << " interval is " << m_TickerInterval << std::endl;

	return (m_TickerIntervalMS > 0) && (millis < m_TickerIntervalMS);
}

