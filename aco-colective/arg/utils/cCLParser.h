/**
 * \class arg::cCLParser
 * \brief Program command line parser
 *
 * Parses the command line arguments in the form -key [value]
 *
 * \author Pavel Kromer, (c) 2009
 *
 * \b History:
 *	- initial version, 2009, pkromer
 *
 */
#ifndef CCLIPARSER_H_
#define CCLIPARSER_H_

#include <string>
#include <map>
#include <set>
#include <ostream>
#include <cstdlib>

namespace arg
{
	typedef std::map<std::string, std::string> ssmap;
	typedef std::set<std::string> sset;

	class cCLParser
	{
			friend std::ostream& operator<<(std::ostream& os, const cCLParser& cl);

		private:
			std::string mProgram; 	///< Program name
			ssmap mParams; 			///< Parameter map (key->value)
			sset mSwitches; 		///< Program line switches (without value, interpreted as true)

		public:
			cCLParser(int argc, const char* argv[]);

			bool Boolean(const char *) const; 					///< Checks if certain switch was present
			const char * String(const char *, const char * def = NULL) const; ///< Checks for value of certain argument
			int Integer(const char *, int def = -1) const; 		///< Checks for integer value of certain argument. Returns -1 if not present or not a number. Accepts default value as second argument.
			double Double(const char *, double def = -1) const; 	///< Checks for integer value of certain argument. Returns -1 if not present or not a number. Accepts default value as second argument.
			int Size(void) const;										///< Number of switches and parameters in command line.

			const char * Program(void) const;
	};
}

#endif /* CCLIPARSER_H_ */
