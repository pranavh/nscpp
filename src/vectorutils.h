#ifndef VECTORUTILS_H
#define VECTORUTILS_H

#include<iostream>
#include<vector>
#include "types.h"

namespace nscpp
{
    vector1d linspace(int nsteps, double start=0.0, double end=0.0);

    vector1d zeros(int size);
    vector2d zeros(int nrows, int ncols);

    vector1d ones(int size);
    vector2d ones(int nrows, int ncols);

    vector2d transpose(vector2d vec2d);

    void print(vector2d vec2d, std::string label="");
    void print(vector1d vec1d, std::string label="");
}
#endif
