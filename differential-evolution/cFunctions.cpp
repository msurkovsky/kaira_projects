#include "cFunctions.h"

cFunctions::t_FunctionType cFunctions::m_FunctionType = cFunctions::FUNC_ACKLEY;

cFunctions::cFunctions()
{
}

double cFunctions::Evaluate(const double * data, const unsigned int dim) const
{
	double result = 10000;
	switch (m_FunctionType)
	{
	case FUNC_GRIEWANK:
		result = Griewank(data, dim);
		break;
	case FUNC_RASTRIGIN:
		result = Rastrigin(data, dim);
		break;
	case FUNC_DEJONG:
		result = Dejong(data, dim);
		break;
	case FUNC_EASOM:
		result = BnchFunc_USS_002_Easom(data, dim);
		break;
	case FUNC_SCHWEFEL:
		result = BnchFunc_USS_002_Schwefel(data, dim);
		break;
	case FUNC_ROSENBROCK:
		result = BnchFunc_USS_002_Rosenbrock(data, dim);
		break;
	case FUNC_ACKLEY:
	default:
		result = BnchFunc_USS_002_Ackley(data, dim);
		break;
	}
	return result;
}

double cFunctions::RangeMin(void) const
{
	double range = -100;
	switch (m_FunctionType)
	{
	case FUNC_GRIEWANK:
		range = -600;
		break;
	case FUNC_RASTRIGIN:
	case FUNC_DEJONG:
		range = -5.12;
		break;
	case FUNC_EASOM:
		range = -10;
		break;
	case FUNC_SCHWEFEL:
		range = -500;
		break;
	case FUNC_ROSENBROCK:
		range = -30;
		//range = -2;
		break;
	case FUNC_ACKLEY:
	default:
		range = -30;
		break;
	}
	return range;
}

double cFunctions::RangeMax(void) const
{
	double range = 100;
	switch (m_FunctionType)
	{

	// for all cases where it holds
	default:
		range = -RangeMin();
		break;
	}
	return range;
}

double cFunctions::BnchFunc_USS_002_Camel3(const double *position, const unsigned int dimension) const
{
	/// DEFINED FOR D=2

	///  Name               Camel Back-3 Three Hump Problem (CB3)
	///  Function           f(x)= ((2 + 0.166666666666667*POWER(x1,4) - 1.05*x1*x1)
	///                     *x1*x1 + x1*x2 + x2*x2 ) + objvar =E= 0;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///  Domain             [-5,5]^{2}
	///  Global Min Pos
	///  Global Min Val     0
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position
	///                     int    *dimension
	///
	///  Output             double  value
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue = 0.0;

	for (unsigned int index = 0; index < dimension - 1; index++)
	{
		fvalue = (2 - 1.05 * *(position + index) * *(position + index) + pow(*(position + index), 4) / 6.0)
				* *(position + index) * *(position + index) + *(position + index) * *(position + index + 1)
				+ *(position + index + 1) * *(position + index + 1);
	}

	return fvalue;
}

double cFunctions::BnchFunc_USS_002_Camel6(const double *position, const unsigned int dimension) const
{
	/// DEFINED FOR D=2

	///  Name               	Camel Back-6 Six Hump Problem (CB6)
	///  Function           f(x)= ((4 + 0.333333333333333*POWER(x1,4) -
	///                     2.1*x1*x1)*x1*x1 + x1*x2 + (-4 + 4*x2*x2)*x2*x2)
	///                     + objvar =E= 0;
	///
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///
	///  Domain             [-5,5]^{2}
	///  Global Min Pos
	///  Global Min Val     -1.0316
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position
	///                     int    *dimension
	///
	///  Output             double  value
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue;

	fvalue = 0.0;

	for (unsigned int index = 0; index < dimension - 1; index++)
	{
		fvalue = (4 - 2.1 * *(position + index) * *(position + index) + pow(*(position + index), 4) / 3)
				* *(position + index) * *(position + index) + *(position + index) * *(position + index + 1)
				+ (-4 + 4 * *(position + index + 1) * *(position + index + 1)) * *(position + index + 1)
						* *(position + index + 1);
	}

	return fvalue;
}

double cFunctions::BnchFunc_USS_002_Ackley(const double *position, const unsigned int dimension) const
{

	///  Name               Ackley・s Problem (ACK)
	///  Function           f(x)= - (-20*exp(-0.02*sqrt(0.1*(sqr(x1) + sqr(x2) + sqr(x3) + sqr(x4) + sqr(x5 )
	///                           + sqr(x6) + sqr(x7) + sqr(x8) + sqr(x9) + sqr(x10)))) - exp(0.1*(cos( 6.28318530718*x1)
	///                           + cos(6.28318530718*x2) + cos(6.28318530718*x3) + cos( 6.28318530718*x4)
	///                           + cos(6.28318530718*x5) + cos(6.28318530718*x6) + cos( 6.28318530718*x7)
	///                           + cos(6.28318530718*x8) + cos(6.28318530718*x9) + cos( 6.28318530718*x10))))
	///                           + objvar =E= 22.718281828459;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///  Domain             [-30,30]^{D}
	///  Global Min Pos
	///  Global Min Val     0
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position  xyz
	///                     int    *dimension xyz
	///
	///  Output             double  value     xyz
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue;
	double gvalue;
	double hvalue;

	fvalue = 0.0;
	gvalue = 0.0;
	hvalue = 0.0;

	for (unsigned int index = 0; index < dimension; index++)
	{
		gvalue = gvalue + pow(*(position + index), 2.0);
		hvalue = hvalue + cos(*(position + index) * 2.0 * M_PI);

	}
	//						  V---- makes it more steep
	// fvalue = -20.0 * exp(-0.02 * pow((gvalue / dimension), 0.5)) - exp(hvalue / dimension) + 20.0 + exp(1.0);
	fvalue = -20.0 * exp(-0.2 * pow((gvalue / dimension), 0.5)) - exp(hvalue / dimension) + 20.0 + exp(1.0);

	return fvalue;
}

double cFunctions::BnchFunc_USS_002_AluffiPentini(const double *position, const unsigned int dimension) const
{

	///  Name               AluffiPentini
	///  Function           f(x)=(0.25*POWER(x1,4) - 0.5*x1*x1 + 0.1*x1 + 0.5*x2*x2) + objvar =E= 0;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///  Domain             [-10,10]^{2}
	///  Global Min Pos
	///  Global Min Val     -0.3523
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position  xyz
	///                     int    *dimension xyz
	///
	///  Output             double  value     xyz
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue;
	fvalue = 0.0;

	for (unsigned int index = 0; index < dimension - 1; index++)
	{
		fvalue = .25 * pow(*(position + index), 4) - .5 * *(position + index) * *(position + index)
				+ .1 * *(position + index) + .5 * *(position + index + 1) * *(position + index + 1);
	}

	return fvalue;
}

double cFunctions::BnchFunc_USS_002_BeckerLago(const double *position, const unsigned int dimension) const
{

	///  Name               BeckerLago
	///  Function           f(x)= ((-5 + sqrt(sqr(x1)))*(-5 + sqrt(sqr(x1))) + (-5 + sqrt(sqr(x2)))*
	///                           (-5 + sqrt(sqr(x2)))) + objvar =E= 0;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///  Domain             [-10,10]^{2}
	///  Global Min Pos
	///  Global Min Val     0
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position  xyz
	///                     int    *dimension xyz
	///
	///  Output             double  value     xyz
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue;

	fvalue = 0.0;

	for (unsigned int index = 0; index < dimension - 1; index++)
	{
		fvalue = pow(fabs(*(position + index)) - 5.0, 2) + pow(fabs(*(position + index + 1)) - 5.0, 2);
	}

	return fvalue;
}

double cFunctions::BnchFunc_USS_002_Bohachevsky1(const double *position, const unsigned int dimension) const
{

	///  Name               Bohachevsky1
	///  Function           f(x)= (sqr(x1) + 2*x2*x2 - 0.3*cos(9.42477796077*x1) -
	///                     0.4*cos(12.56637061436 *x2))
	///                     + objvar =E= 0.7;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///  Domain             [-50,50]^{2}
	///  Global Min Pos
	///  Global Min Val     0
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position  xyz
	///                     int    *dimension xyz
	///
	///  Output             double  value     xyz
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue;

	fvalue = 0.0;

	for (unsigned int index = 0; index < dimension - 1; index++)
	{
		fvalue = pow(*(position + index), 2) + 2. * *(position + index + 1) * *(position + index + 1)
				- .3 * cos(3 * 3.14159265359 * *(position + index))
				- .4 * cos(4 * 3.14159265359 * *(position + index + 1)) + .7;
	}
	return fvalue;
}

double cFunctions::BnchFunc_USS_002_Bohachevsky2(const double *position, const unsigned int dimension) const
{

	///  Name               Bohachevsky2
	///  Function           f(x)= (sqr(x1) + 2*x2*x2 - 0.3*cos(9.42477796077*x1)
	///                      *cos(12.56637061436*x2)) + objvar =E= 0.3;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///  Domain             [-50,50]^{2}
	///  Global Min Pos
	///  Global Min Val     0
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position  xyz
	///                     int    *dimension xyz
	///
	///  Output             double  value     xyz
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue;

	fvalue = 0.0;

	for (unsigned int index = 0; index < dimension - 1; index++)
	{

		fvalue = pow(*(position + index), 2) + 2. * *(position + index + 1) * *(position + index + 1)
				- .3 * cos(3 * 3.14159265359 * *(position + index)) * cos(4 * 3.14159265359 * *(position + index + 1))
				+ .3;
	}

	return fvalue;
}

double cFunctions::BnchFunc_USS_002_Branin(const double *position, const unsigned int dimension) const
{

	///  Name               branin
	///  Function           f(x)= (sqr((-6) + 1.59154943091885*x1 -
	///                        0.129184509143964*x1*x1 + x2) + 9.60211264227029*cos(x1))
	///                        + objvar =E= 10;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///  Domain             [-5,10]^[10,15]
	///  Global Min Pos
	///  Global Min Val     0.3979
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position
	///                     int    *dimension
	///
	///  Output             double  value
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue;

	fvalue = 0.0;

	for (unsigned int index = 0; index < dimension - 1; index++)
	{
		double a = 1., b = 5.1 / (4 * 3.14159265359 * 3.14159265359), c = 5 / 3.14159265359;
		double d = 6., e = 10., f = 1 / (8 * 3.14159265359);

		fvalue = a
				* pow(
						(*(position + index + 1) - b * *(position + index) * *(position + index)
								+ c * *(position + index) - d), 2) + e * (1 - f) * cos(*(position + index)) + e;
	}

	return fvalue;
}

double cFunctions::BnchFunc_USS_002_Easom(const double *position, const unsigned int dimension) const
{

	///  Name               	Easom Problem (EP)
	///  Function           f(x)= cos(x1)*cos(x2)*exp((-sqr((-3.14159265359) + x1))
	///                      - sqr((-3.14159265359) + x2)) + objvar =E= 0;

	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///
	///
	///
	///
	///  Domain             [-10,10]^{D}
	///  Global Min Pos
	///  Global Min Val     -1
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position
	///                     int    *dimension
	///
	///  Output             double  value
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	double fvalue;

	fvalue = 0.0;

	for (unsigned int index = 0; index < dimension - 1; index++)
	{
		fvalue = -cos(*(position + index)) * cos(*(position + index + 1))
				* exp(-pow(*(position + index) - 3.14159265359, 2) - pow(*(position + index + 1) - 3.14159265359, 2));

	}

	return 1 + fvalue;
}

double cFunctions::BnchFunc_USS_002_Schwefel(const double *position, const unsigned int dimension) const
{

	///  Name               		Schwefel Problem (SWF)
	///  Function           f(x)= sin(sqrt(abs(x1)))*x1 + sin(sqrt(abs(x2)))*x2
	///                     + sin(sqrt(abs(x3)))*x3 + sin(sqrt(abs(x4)))*x4
	///                     + sin(sqrt(abs(x5)))*x5 + sin(sqrt(abs(x6)))*x6
	///                     + sin(sqrt(abs(x7)))*x7 + sin(sqrt(abs(x8)))*x8
	///                     + sin(sqrt(abs(x9)))*x9 + sin(sqrt(abs(x10)))*x10 + objvar =E= 0;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///
	///
	///
	///
	///  Domain             [-500,500]^{10}
	///  Global Min Pos
	///  Global Min Val     -4189.8289
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position
	///                     int    *dimension
	///
	///  Output             double  value
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	unsigned int j;
	double sum = 0;

	for (j = 0; j < dimension; j++)
	{
		sum -= *(position + j) * sin(sqrt(fabs(*(position + j))));
	}

	return 418.98289 * dimension + (sum);
}

double cFunctions::BnchFunc_USS_002_Rosenbrock(const double *position, const unsigned int dimension) const
{

	///  Name               	Rosenbrock Problem (RB)
	///  Function           f(x)= ((100*x1*x1 - 100*x2)*(x1*x1 - x2) + (1 - x1)*(1 - x1)
	///                      + (100*x2*x2 - 100*x3)*(x2*x2 - x3) + (1 - x2)*(1 - x2)
	///                      + (100*x3*x3 - 100*x4)*(x3*x3 - x4) + (1 - x3)*(1 - x3)
	///                      + (100*x4*x4 - 100*x5)*(x4*x4 - x5) + (1 - x4)*(1 - x4)
	///                      + (100*x5*x5 - 100*x6)*(x5*x5 - x6) + (1 - x5)*(1 - x5)
	///                      + (100*x6* x6 - 100*x7)*(x6*x6 - x7) + (1 - x6)*(1 - x6)
	///                      + (100*x7*x7 - 100*x8)*(x7* x7 - x8) + (1 - x7)*(1 - x7)
	///                      + (100*x8*x8 - 100*x9)*(x8*x8 - x9) + (1 - x8 )*(1 - x8)
	///                      + (100*x9*x9 - 100*x10)*(x9*x9 - x10) + (1 - x9)*(1 - x9)) + objvar =E= 0;
	///  Reference          A numerical evaluation of several stochastic
	///                     algorithms on selected continuous global
	///                     optimizattion test problems.
	///                     M. Montaz Ali, Charoenchai Khompatraporn,
	///                     and Zelda B. Zabinsky.
	///
	///
	///
	///
	///  Domain             [-30,30]^{10}
	///  Global Min Pos
	///  Global Min Val     0
	///  Local  Min Pos
	///  Local  Min Val
	///
	///  Input              double *position
	///                     int    *dimension
	///
	///  Output             double  value
	///
	///  Author             Wanching Chou
	///  Affiliation        Dept. of Mathematics, National Taiwan University
	///  Date               2009/03/24
	///
	///  Change Log         2009/03/24 first version

	unsigned int j;
	double sum = 0, a = 0., b = 0.;

	// fixed EXTENDED rosenbrock

	for (j = 0; j < dimension - 1; j++)
	{
		//a = *(position + j + 1) * *(position + j + 1) - *(position + j);
		a = *(position + j + 1) - *(position + j) * *(position + j);
		b = 1.0 - *(position + j);
		sum += 100. * a * a + b * b;
	}

	return (sum);
}

double cFunctions::Rastrigin(const double * position, const unsigned int dimension) const
{
	// http://www.geatbx.com/docu/fcnindex-01.html#P89_3085
	// f6(x)=10·n+sum(x(i)^2-10·cos(2·pi·x(i))), i=1:n; -5.12<=x(i)<=5.12.

	double result = 10 * dimension;

	for (unsigned int i = 0; i < dimension; i++)
	{
		result += position[i] * position[i] - 10 * cos(2 * M_PI * position[i]);
	}
	return result;
}

double cFunctions::Dejong(const double * position, const unsigned int dimension) const
{
	// http://www.geatbx.com/docu/fcnindex-01.html#P89_3085
	// f1(x)=sum(x(i)^2), i=1:n, -5.12<=x(i)<=5.12.

	double result = 0;

	for (unsigned int i = 0; i < dimension; i++)
	{
		result += (position[i] * position[i]);
	}
	return result;
}

double cFunctions::Griewank(const double * position, const unsigned int dimension) const
{
	// http://www.geatbx.com/docu/fcnindex-01.html#P89_3085
	// f8(x)=sum(x(i)^2/4000)-prod(cos(x(i)/sqrt(i)))+1, i=1:n  -600<=x(i)<= 600.
	// has minima in x(i) = 0, f(min) = 0

	double a = 0;
	double b = 0;

	for (unsigned int i = 0; i < dimension; i++)
	{
		a += position[i] * position[i] / 4000.0;
		b *= cos(position[i] / sqrt(i + 1));
	}
	// return a - b + 1;
	return a - b;
}

cFunctions::~cFunctions()
{
}
