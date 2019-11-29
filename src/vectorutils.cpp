#include "vectorutils.h"

namespace nscpp
{

    vector1d linspace(int nsteps, double start/* =0.0 */, double end/* =1.0 */) {
        double dx = (end - start) / (nsteps-1);
        vector1d vec;
        for (int i = 0; i < nsteps; i++)
        {
            vec.push_back(start + dx * i);
        }
        return vec;
    }

    vector1d zeros(int nelem) {
        vector1d vec;
        for (int i = 0; i < nelem; i++)
        {
            vec.push_back(0);
        }
        return vec;
    }

    vector2d zeros(int nrows, int ncols) {
        vector2d vec;
        for (int i = 0; i < nrows; i++)
        {
            vec.push_back(zeros(ncols));
        }
        return vec;
    }


    vector1d ones(int nelem) {
        vector1d vec;
        for (int i = 0; i < nelem; i++)
        {
            vec.push_back(1);
        }
        return vec;
    }

    vector2d ones(int nrows, int ncols) {
        vector2d vec;
        for (int i = 0; i < nrows; i++)
        {
            vec.push_back(ones(ncols));
        }
        return vec;
    }

    vector2d transpose(vector2d vec2d) {
        vector2d rval;
        int ncols = vec2d.size();
        int nrows = vec2d[0].size();

        for (int i = 0; i < nrows; i++)
        {
            vector1d row;
            row.reserve(ncols);
            for (int j = 0; j < ncols; j++)
            {
                row[j] = vec2d[j][i];
            }

        }

    }

    void print(vector2d vec2d, std::string label/* ="" */) {
        if (label.size() > 0) {
            std::cout << "vector2d " << label << std::endl;
        }

        int nrows = vec2d.size();
        int ncols = vec2d[0].size();
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                std::cout << vec2d[i][j] << '\t';
            }
            std::cout << std::endl;
        }
    }

    void print(vector1d vec1d, std::string label/* ="" */) {
        if (label.size() > 0) {
            std::cout << "vector1d " << label << std::endl;
        }

        int ncols = vec1d.size();
        for (int j = 0; j < ncols; j++)
        {
            std::cout << vec1d[j] << '\t';
        }
        std::cout << std::endl;

    }

} // namespace nscpp