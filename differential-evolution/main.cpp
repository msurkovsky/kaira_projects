
#include <iostream>
#include <string>
#include <stack>

#include <limits>

#include <arg/utils/cCLParser.h>
#include <arg/core/cAmphorA.h>
#include <arg/algorithms/de/cParallelDE.h>

#include "cFunctions.h"
#include "de/cFuncDE.h"

#include <arg/utils/rng/cRanlux.h>

using std::cout;
using std::endl;

arg::cAmphorA amphora;

void usage(arg::cCLParser & cl)
{
	cout << "\nProgram " << cl.Program() << " for bio-inspired search for function minima.\n";
	cout << "\nBuild " << __DATE__ << " " << __TIME__;
#ifdef SCM_VERSION
	cout << ", SCM version [" << QUOTE(SCM_VERSION) << "]";
#endif
	cout << ".\nFound AmphorA version " << amphora.Identify() << ".\n";
	cout << "Requires AmphorA version 3.4.0+.\n\n";
	cout << "Pavel Krömer <pavel.kromer@vsb.cz>, (c) 2012, 2013\n\n\n";

	cout << "Usage:\n\t" << cl.Program() << " [parameters]\n\n";

	cout << "Common parameters:\n";
	cout << "\t-d \t\tboolean\t Print debug information.\n";
	cout << "\t-h \t\tboolean\t Display this help.\n";
	cout << "\t-gen\t\tinteger\t Number of generations to process (1000).\n";
	cout << "\t-pop\t\tinteger\t Population size (max(4*dim, 100)).\n";
	cout << "\t-p\t\tinteger\t Print frequency (0xffff).\n";
	cout << "\t-eval\t\tinteger\t Number of fitness function evaluations (0; no limit).\n";

	cout << "\nDE parameters:\n";
	cout << "\t-F\t\tdouble\t Differential weight (0.9).\n";
	cout << "\t-C\t\tdouble\t Differential crossover (0.9).\n";

	cout << "\nFunc tool parameters:\n";
	cout << "\t-dim\t\tinteger\t Dimension of the function (10).\n";
	cout << "\t-f\t\tstring\t The test function to use: ackley, easom, rosenbrock, schwefel,\n";
	cout << "\t\t\t\t rastrigin, dejong, griewank (ackley).\n";

	cout << "\n\n\n\n";
}

void test_parallel_de(arg::cCLParser & cl)
{
	cFunctions func;
	func.SetFunction(cFunctions::FUNC_ACKLEY);

	const bool debug = cl.Boolean("d");

	arg::cParallelDE parde(200, 3, 1000);

	const unsigned int CNT = cl.Integer("K",3);

	for (unsigned int i = 0; i < CNT; i++)
	{
		cFuncDE * de = new cFuncDE(50, 150);
		de->Debug(debug);
		de->MaxGenerations(5000);
		de->SetRange(func.RangeMin(), func.RangeMax());
		parde.AddDE(de);
	}
	parde.Debug(debug);
	parde.Execute();

	arg::cArrayConst<double> winner = parde.Winner();
	cout << " Winner = \n " << winner << endl;
	parde.DeleteDEs();
}

void de(arg::cCLParser & cl)
{
	const int dim = cl.Integer("dim", 10);

	cFuncDE de(cl.Integer("pop", std::max(4 * dim, 100)), dim);
	de.Debug(cl.Boolean("d"));
	de.MaxGenerations(cl.Integer("gen", 1000));
	de.MaxEvaluations(cl.Integer("eval", 0));

	cFunctions func;

	de.SetRange(func.RangeMin(), func.RangeMax());
	de.PrintFrequency(cl.Integer("p", (unsigned int) -1));
	de.F(cl.Double("F", 0.9));
	de.C(cl.Double("C", 0.9));
	de.MaxTime(cl.Integer("time", 0));
	de.Execute();

	arg::cArrayConst<double> winner = de.Winner();

	std::cout << winner << std::endl;
}

int release(arg::cCLParser & cl)
{
	cFunctions func;
	func.SetFunction(cFunctions::FUNC_ACKLEY);

	if (!cl.Boolean("h"))
		cout << cl << endl;

	const bool randomized = cl.Boolean("R");

	if (!randomized)
	{
		// 	arg::cStaticRandom::Seed(12349990);
		unsigned int seed[] =
		{ 1, 2, 3, 4, 5, 10, 22, 35, 7, 1, 1 };
		arg::cStaticRandom::Seed((unsigned int *) seed, (unsigned int) sizeof(seed) / sizeof(unsigned int));
	}

	if (cl.StringValue("f", "rastrigin"))
	{
		func.SetFunction(cFunctions::FUNC_RASTRIGIN);
	}
	else if (cl.StringValue("f", "dejong"))
	{
		func.SetFunction(cFunctions::FUNC_DEJONG);
	}
	else if (cl.StringValue("f", "griewank"))
	{
		func.SetFunction(cFunctions::FUNC_GRIEWANK);
	}
	else if (cl.StringValue("f", "ackley"))
	{
		func.SetFunction(cFunctions::FUNC_ACKLEY);
	}
	else if (cl.StringValue("f", "easom"))
	{
		func.SetFunction(cFunctions::FUNC_EASOM);
	}
	else if (cl.StringValue("f", "schwefel"))
	{
		func.SetFunction(cFunctions::FUNC_SCHWEFEL);
	}
	else if (cl.StringValue("f", "rosenbrock"))
	{
		func.SetFunction(cFunctions::FUNC_ROSENBROCK);
	}
	else if (!cl.Boolean("h"))
	{
		cout << endl << "Unknown function " << cl.String("f", "<missing>") << ". Type \'" << cl.Program()
				<< " -h\' to display help." << endl << endl;
		return -1;
	}

	if (cl.Boolean("h") || !amphora.Require(30400))
	{
		usage(cl);
	}
	else
	{
		de(cl);
	}

	return 0;
}

int main(int argc, const char* argv[])
{
	cFunctions func;
	func.SetFunction(cFunctions::FUNC_ACKLEY);

	arg::cCLParser cl(argc, argv);

	if (cl.Boolean("-DEV"))
	{
		// run development branch. Switch --DEV is (on purpose) undocumented
		test_parallel_de(cl);
	}
	else
	{
		return release(cl);
	}

	return 0;
}
