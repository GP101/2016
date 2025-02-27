#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>

int main()
{
	using namespace std::complex_literals;
	std::cout << std::fixed << std::setprecision(1);

	std::complex<double> z1 = 1i * 1i;     // imaginary unit squared
	std::cout << "i * i = " << z1 << '\n';

	std::complex<double> z2 = std::pow(1i, 2); // imaginary unit squared
	std::cout << "pow(i, 2) = " << z2 << '\n';

	double PI = std::acos(-1);
	std::complex<double> z3 = std::exp(1i * PI); // Euler's formula
	std::cout << "exp(i * pi) = " << z3 << '\n';

	std::complex<double> z4 = 1. + 2i, z5 = 1. - 2i; // conjugates
	std::cout << "(1+2i)*(1-2i) = " << z4 * z5 << '\n';
}
/*
	i * i = (-1.0,0.0)
	pow(i, 2) = (-1.0,0.0)
	exp(i * pi) = (-1.0,0.0)
	(1+2i)*(1-2i) = (5.0,0.0)
*/
