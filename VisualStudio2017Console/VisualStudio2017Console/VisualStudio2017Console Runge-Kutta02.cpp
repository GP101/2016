#include <iostream>
#include <iomanip>
#include <valarray>

// Function prototypes
void step(double dx, double &x, std::valarray<double> &Y);
std::valarray<double> F(double x, std::valarray<double> Y);

void step(double dx, double& x, std::valarray<double>& Y)
{
	int ndep = Y.size();
	std::valarray<double> dY1(ndep), dY2(ndep), dY3(ndep), dY4(ndep);

	dY1 = F(x, Y) * dx;
	dY2 = F(x + 0.5 * dx, Y + 0.5 * dY1) * dx;
	dY3 = F(x + 0.5 * dx, Y + 0.5 * dY2) * dx;
	dY4 = F(x + dx, Y + dY3) * dx;
	Y += (dY1 + 2.0 * dY2 + 2.0 * dY3 + dY4) / 6.0;

	x += dx;
}

std::valarray<double> F(double x, std::valarray<double> Y)
{
	std::valarray<double> f(Y.size()); // this will be returned as F in the output

	f[0] = x + Y[0] - 3 * Y[1];			// ****************************************
	f[1] = 2.0 * x - 6 * Y[0] + Y[1];	// just encode derivative components here *
										// ****************************************
	return f;
}

int main()
{
    int nstep;
	double x = 0;
	double dx = 0;

    // Set number of variables
    int ndep = 2;
	std::valarray<double> Y(ndep);

    // Set initial values
    x = 0; Y[0] = 2.5; Y[1] = -1.2;

    // Set step size and number of steps
    dx = 0.1;
    nstep = 10;

    // Write header and initial conditions
#define SP << std::setw( 12 ) << std::fixed << std::setprecision( 4 ) << // save some repetition when writing
	std::cout << 'x' SP 'u'  SP 'v' << std::endl;
	std::cout << x  SP Y[0] SP Y[1] << std::endl;

    // Solve the differential equation using nstep intervals
    for (int n = 1; n <= nstep; n++)
    {
        step(dx, x, Y); // main Runge-Kutta step
		std::cout << x SP Y[0] SP Y[1] << std::endl; // output
    }
}
