#ifndef TYPES_H
#define TYPES_H

#include<vector>
#include<stdexcept>

namespace nscpp
{
    typedef std::vector<double> vector1d;
    // typedef std::vector<int> vector1i;

    typedef std::vector<vector1d> vector2d;

    bool sizeequal(vector1d v1, vector1d v2);
    // bool sizeequal(vector1i v1, vector1i v2);
    bool sizeequal(vector2d v1, vector2d v2);

    // vector1d add(vector1d &obj, vector1d &obj2);
}
#endif