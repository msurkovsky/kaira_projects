/**
 * \class arg::cTimer
 * \brief An utility timer.
 *
 * Can measure time range in seconds, minutes, days
 *
 * \author Pavel Kromer, (c) 2007 - 2010
 *
 * \b History:
 *		- initial version, 2007, pkromer
 * 		- doxygen comments, 26-07-2007, pkromer
 * 		- 2011-01, 	pkromer,	for ms precision used sys/time.h. The use of new methods Cpu* highly suggested.
 *
 */
#ifndef __CTIMER__
#define __CTIMER__

#include <sys/time.h>
#include <ctime>

namespace arg
{
	class cTimer
	{
		protected:
			clock_t start, stop; 	///< Start and stop time
			timeval m_TickerStart;
			unsigned long m_TickerIntervalMS;
			timeval m_TStart, m_TStop;

		public:
			void Start(); 			///< Start measuring
			void Stop(); 			///< Stop measuring
			void Reset(); 			///< Reset (new Start required)
			long Ticks();
			long Milis(); 			///< Time since start in seconds (even if not stopped).
			long Seconds(); 		///< Time since start in seconds (even if not stopped).
			long Minutes(); 		///< Time since start in minutes (even if not stopped).
			long Days(); 			///< Time since start in days (even if not stopped).

			void CpuStart(void);			///< Start interval on host.
			cTimer & CpuStop(void);			///< Stop interval on host.
			double CpuMillis(void); 		///< Computes time interval on host.
			double CpuSeconds(void); 		///< Computes time interval on host.

			void StartTicking(const unsigned long sec);
			bool IsTicking(void) const;
	};

	inline double cTimer::CpuMillis(void)
	{
		return ((m_TStop.tv_sec * 1e6 + m_TStop.tv_usec) - (m_TStart.tv_sec * 1e6 + m_TStart.tv_usec)) / 1e3;
	}

	inline double cTimer::CpuSeconds(void)
	{
		return CpuMillis()/1e3;
	}
}

#endif
