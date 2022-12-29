#include <iostream>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>

// used as conversion
long double operator"" _deg(long double deg)
{
    return deg * 3.14159265358979323846264L / 180;
}

long double operator"" _km(unsigned long long km)
{
    return km * 1000.0;
}

int main() {
    // literals
    //
    std::cout << 0b10000000 << std::endl; // binary literal
    std::cout << 1.0e+2 << std::endl; // double
    std::cout << 1U << std::endl; // unsigned int

    // user defined literal
    //
    double x = 90.0_deg;
    std::cout << std::fixed << x << '\n';
    std::cout << 2_km << std::endl;

    // ex) complex number
    using namespace std::complex_literals;
    std::cout << std::fixed << std::setprecision(1);

    std::complex<double> z1 = 1i * 1i; // imaginary unit squared
    std::cout << "i * i = " << z1 << '\n';

    std::complex<double> z2 = std::pow(1i, 2); // imaginary unit squared
    std::cout << "pow(i, 2) = " << z2 << '\n';

    double PI = std::acos(-1);
    std::complex<double> z3 = std::exp(1i * PI); // Euler's formula
    std::cout << "exp(i * pi) = " << z3 << '\n';

    std::complex<double> z4 = 1. + 2i, z5 = 1. - 2i; // conjugates
    std::cout << "(1+2i)*(1-2i) = " << z4 * z5 << '\n';
}
