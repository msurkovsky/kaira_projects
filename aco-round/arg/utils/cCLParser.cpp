#include "cCLParser.h"

using namespace std;

namespace arg
{
	cCLParser::cCLParser(int argc, const char* argv[])
	{
		if (argc > 0 && argv != NULL)
		{
			mProgram = argv[0];
		}

		for (int i = 1; i < argc; i++)
		{
			string key;
			const char * tmp = argv[i];
			if (tmp[0] == '-')
			{
				key = tmp + 1;
			}
			else
			{
				//skip
				continue;
			}
			i++;

			// it was the last switch
			if (i >= argc)
			{
				mSwitches.insert(key);
			}
			else
			{
				tmp = argv[i];
				//it was a switch
				if (tmp[0] == '-')
				{
					mSwitches.insert(key);
					i--;
				}
				else
				{
					mParams[key] = tmp;
				}
			}
		}
	}

	bool cCLParser::Boolean(const char * key) const
	{
		string tmp = key;

		if (mSwitches.size() == 0)
		{
			return false;
		}
		sset::iterator it = mSwitches.find(tmp);
		return it != mSwitches.end();
	}

	const char * cCLParser::String(const char * key, const char * def) const
	{
		string tmp = key;

		if (mParams.size() == 0)
		{
			return def;
		}

		ssmap::const_iterator it = mParams.find(tmp);

		if (it == mParams.end())
		{
			return def;
		}
		else
		{
			return it->second.c_str();
		}
	}

	int cCLParser::Integer(const char * key, int def) const
	{
		const char * tmp = String(key);
		if (tmp == NULL)
		{
			//convention
			return def;
		}
		else
		{
			return atoi(tmp);
		}
	}

	double cCLParser::Double(const char * key, double def) const
	{
		const char * tmp = String(key);
		if (tmp == NULL)
		{
			//convention
			return def;
		}
		else
		{
			return atof(tmp);
		}
	}

	const char * cCLParser::Program(void) const
	{
		return mProgram.c_str();
	}

	int cCLParser::Size(void) const
	{
		return mParams.size() + mSwitches.size();
	}

	ostream& operator<<(ostream& os, const cCLParser& cl)
	{
		os << cl.mProgram << " command line parameters :\n";
		os << "\tSwitches:\n";
		for (sset::iterator it = cl.mSwitches.begin(); it != cl.mSwitches.end(); it++)
		{
			os << "\t\t-" << *it << "\n";
		}
		os << "\tArguments:\n";
		for (ssmap::const_iterator it = cl.mParams.begin(); it != cl.mParams.end(); it++)
		{
			os << "\t\t-" << it->first << " " << it->second << "\n";
		}

		return os;
	}
}

