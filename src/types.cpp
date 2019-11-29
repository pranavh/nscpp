#include "types.h"

namespace nscpp
{

    // vector1d add (vector1d const &vec1, vector1d const &vec2 ) {
    //     if (!sizeequal(vec1, vec2))
    //     {
    //         throw std::runtime_error("Both vectors must be of the same size");
    //     }

    //     vector1d result(vec1);
    //     int nelem = vec1.size();
    //     for (int i = 0; i < nelem; i++)
    //     {
    //         result[i] += vec2[i];
    //     }
    //     return result;
    // }

    // vector1d subtract (vector1d const &vec1, vector1d const &vec2 ) {
    //     if (!sizeequal(vec1, vec2))
    //     {
    //         throw std::runtime_error("Both vectors must be of the same size");
    //     }

    //     vector1d result(vec1);
    //     int nelem = vec1.size();
    //     for (int i = 0; i < nelem; i++)
    //     {
    //         result[i] -= vec2[i];
    //     }
    //     return result;
    // }


    bool sizeequal(vector1d v1, vector1d v2) {
        int r1 = v1.size();
        int r2 = v2.size();
        return r1 == r2;
    }

    bool sizeequal(vector2d v1, vector2d v2) {
        int r1 = v1.size();
        int c1 = v1[0].size();
        int r2 = v2.size();
        int c2 = v2[0].size();
        return r1 == r2 && c1  == c2;
    }
}