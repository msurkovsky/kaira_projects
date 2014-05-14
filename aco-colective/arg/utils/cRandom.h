/**
 * \class arg::cRandom
 * \brief An implementation of simple adjustable pseudo-random number generator.
 *
 * Provides static utility methods.
 *
 * \author Pavel Kromer, (c) 2005 - 2010
 *
 * \b History:
 *	- initial version, 2005, pkromer
 *	- more methods added, 2006, pkromer
 * 	- doxygen comments, 26-07-2007, pkromer (non-functional change)
 *
 */
#ifndef __CRANDOMH__
#define __CRANDOMH__

#include <stdlib.h>
#include <ctime>

namespace arg
{
	class cRandom
	{
		public:
			static void Init(); 				///< Initialize the generator.
			static int Next(); 					///< Next integer.
			static double Next(double); 		///< Next double lower equal to argument
			static double Next(double, double); ///< Next double from a range
			//	static double Next(unsigned int, unsigned int);
			static int NextInt(int); 			///< Next integer lower equal to argument
	};
}

#endif

