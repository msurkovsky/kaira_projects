/**
 *
 * \mainpage AmphorA Core
 *
 *	This library contains the codebase for the AmphorA dynamic library.
 *
 * \section About Amphora
 * My version of base classes.
 *
 * \section Environment
 *  Built on Linux.
 *
 *  \section Authors
 *	Maintained by Pavel Krömer <pavel.kromer@vsb.cz>, VŠB Technical University of Ostrava.
 *	(c) 2011 - 2013
 *
 *  \section Changelog
 *  We have now a changelog in \ref hg_page.
 */

#ifndef __AMPHORA__
#define __AMPHORA__

#define QUOTE_(x) #x
#define QUOTE(x) QUOTE_(x)

#ifndef UNREFERENCED_PARAMETER
	#define UNREFERENCED_PARAMETER(P) (P)
#endif

#define _ARG_MAJOR 4		///< Major version.
#define _ARG_MINOR 2		///< Minor version.
#define _ARG_FIX	0		///< Fix.

#include <sstream>
#include <iostream>
#include <cstdlib>

namespace arg
{
	/**
	 * \class arg::cAmphorA
	 * \brief The version guard for AmphorA.
	 *
	 * Because sometimes the versions can be mixed up, this class can be used to query the AmphorA version at runtime.
	 *
	 * Intended use:
	 * \code
	  	arg::cAmphorA arg;

	  	if (!arg.Require(2,5,0))
	  	{
	 			cout << "This program requires AmphorA 2.5.0 but this is AmphorA " << arg.Identify() << endl;
	 			return 0;
	  	}
	 * \endcode
	 *
	 * Alternatively, you can use the RequireLatestAmphora() function:
	 * \code
	  	arg::cAmphorA arg;
		arg.RequireLatestAmphora();
	 * \endcode
	 *
	 * The function checks the runtime for the version of AmphorA it was compiled against. It exits the program with
	 * code -255 when the check is not passed. Pay attention, the function might not work with all compilers.
	 *
	 * \author Pavel Krömer (c) 2011
	 *
	 * \version 2.0
	 *
	 * \b History:
	 * 		- 2011-09,	pkromer,	second version, RequireLatesAmphorA
	 */
	class cAmphorA
	{
			const static unsigned int m_Major = _ARG_MAJOR;
			const static unsigned int m_Minor = _ARG_MINOR;
			const static unsigned int m_Fix = _ARG_FIX;

			static std::string m_Identification;		///< An id string returned by the library.

		public:
			cAmphorA(void);

			/**
			 * Tests the version of the library.
			 *
			 * \return 	true 	- if the shared library has greater version.
			 * \return 	false	- if the shared library has lower version.
			 */
			bool Require(const unsigned int major, const unsigned int minor, const unsigned int fix) const;

			/**
			 * Tests the version of the library using "version hash".
			 *
			 * The has contains 2 digits for each part of the version, e.g. 20501
			 * means the version must be grater than 2.5.1
			 *
			 * \return 	true 	- if the shared library has greater version.
			 * \return 	false	- if the shared library has lower version.
			 */
			bool Require(const unsigned int version_hash) const;

			/** Returns the id string. */
			inline const char* Identify(void) const;

			/** Checks for AmphorA version greater or equal than the program was compiled against.
			 *
			 *  This function relies on inlining, i.e. it is not guaranteed to work with all
			 *  compilers.
			 */
			inline void RequireLatest() const;
	};

	inline const char* cAmphorA::Identify(void) const
	{
		return m_Identification.c_str();
	}

	inline void cAmphorA::RequireLatest() const
	{
		if (!Require(_ARG_MAJOR, _ARG_MINOR, _ARG_FIX))
		{
			std::cerr << "This program requires AmphorA " << _ARG_MAJOR << "." << _ARG_MINOR << "."<< _ARG_FIX << " but this is AmphorA " << Identify() << std::endl;
			std::cerr << "Exiting." << std::endl;
			exit(-255);
		}
	}
}

#endif
