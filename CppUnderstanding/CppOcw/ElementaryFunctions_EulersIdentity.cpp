#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>

int main()
{
    const double pi = std::acos(-1);
    const double e = std::exp(1);
    printf("%g,%g\n", pi, e);

    //std::cout << std::setprecision(6);
    std::cout << std::fixed;

    // 1. Power functions
    double x = std::pow(2, 3);
    double x1 = std::sqrt(2);
    double x2 = std::pow(2, 1 / 2.0);
    printf("%g,%g,%g\n", x, x1, x2);

    // complex number
    const std::complex<double> i(0, 1);
    std::complex<double>    c0;
    c0 = std::polar<double>(1.0, pi / 2.0);
    std::cout << c0 << std::endl;
    std::cout << std::arg(c0) << std::endl;
    std::cout << i * i << std::endl;

    // 2. Exponential functions
    std::cout << std::log(std::exp(2)) << std::endl;

    // 3. Trigonometric functions
    std::cout << std::cos(pi / 2) << std::endl;
    // Pythagorean theorem
    const double w = 1.2;
    std::cout << std::pow(std::cos(w), 2) + std::pow(std::sin(w), 2) << std::endl;

    // 4. Euler's Identity
    std::cout << std::exp(i * pi) << std::endl;

    /** Output:
        3.14159,2.71828
        8,1.41421,1.41421
        (0.000000,1.000000)
        1.570796
        (-1.000000,0.000000)
        2.000000
        0.000000
        1.000000
        (-1.000000,0.000000)
    */
    return 0;
}