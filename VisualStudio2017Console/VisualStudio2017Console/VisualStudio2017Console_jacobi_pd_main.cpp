#include <stdio.h>
#include <vector>
#include <iostream>
#include "jacobi_pd.hpp"

#define OUT

using namespace jacobi_pd;

void main()
{
    int n = 2;       // Matrix size
    std::vector<std::vector<double>> M;// A symmetric n x n matrix you want to diagonalize
    std::vector<double> evals{0,0}; // Store the eigenvalues here.
    std::vector<std::vector<double>> evects; // Store the eigenvectors here.
    // Allocate space for M, evals, and evects, and load contents of M (omitted)...

    // Now create an instance of Jacobi ("eigen_calc").  This will allocate space
    // for storing intermediate calculations.  Once created, it can be reused
    // multiple times without incurring the cost of allocating memory on the heap.

    Jacobi<double> eigen_calc(n);

    // Now, calculate the eigenvalues and eigenvectors of M

    // test data01
    //
    //M.push_back(std::vector<double>{9, 4});
    //M.push_back(std::vector<double>{4, 3});
    //0.894427, 0.447214, // (2,1), 11
    //-0.447214, 0.894427, // (-1,2), 1

    // test data02
    //
    M.push_back(std::vector<double>{2, 1});
    M.push_back(std::vector<double>{1, 2});
    //0.707107, 0.707107, // ( 1, 1), 3
    //0.707107, -0.707107, // (1, -1), 1

    evects.push_back(std::vector<double>{0, 0});
    evects.push_back(std::vector<double>{0, 0});

    eigen_calc.Diagonalize(M, OUT evals, OUT evects);
    std::cout << "eigen values: ";
    for (auto v : evals)
        std::cout << v << ",";
    std::cout << std::endl;
    std::cout << "eigen vectors " << std::endl;
    for (auto v : evects)
    {
        for (auto i : v)
            std::cout << i << ",";
        std::cout << std::endl;
    }
}
