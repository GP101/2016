#include <stdio.h>
#include <cmath>

double EulerNumber(double a, double h = 0.0001)
{
    return (std::pow(a, h) - 1.0 ) / h;
}

int main()
{
    double bmin = 1.0;
    double bmax = 3.0;
    double error = 0.0;
    double bcenter = 0.0;
    int iteration = 0;
    while (iteration < 100)
    {
        bcenter = bmin + (bmax - bmin) / 2.0;
        double result = EulerNumber(bcenter);
        if (result > 1.0)
            bmax = bcenter;
        else
            bmin = bcenter;
        error = std::abs(result - 1.0);
        if (error < 0.0001)
            break;
        iteration += 1;
    }
    printf("%g,%g\n", bcenter,error);
}
