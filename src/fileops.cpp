/**
 * fileops.cpp
 * Pranav Hosangadi
 * 2019-11-28
 * File handling helper functions
**/

#include "fileops.h"

namespace nscpp
{

    bool iscomment(char c) {
        return c == '%' || c == '#';
    }

    vector2d dlmread(std::string filename, char delimiter/* ='\t' */) {
        return dlmread(filename.c_str(), delimiter);
    }

    vector2d dlmread(char* filename, char delimiter/* ='\t' */) {
        std::string line;
        std::ifstream inf;
        vector2d rval;

        inf.open(filename);

        while(std::getline(inf, line)) {
            if (line.size() > 0 && !iscomment(line[0])) {
                std::stringstream line_str(line);
                std::string elem_s;
                vector1d row;
                while(std::getline(line_str, elem_s, delimiter)) {
                    // std::cout << "element read: " << elem_s << std::endl;
                    row.push_back(std::stod(elem_s));
                }
                rval.push_back(row);
            }
        }

        inf.close();
        return rval;

    }

    vector1d dlmread1d(std::string filename, char delimiter/* ='\t' */) {
        return dlmread1d(filename.c_str(), delimiter);
    }

    vector1d dlmread1d(char* filename, char delimiter/* ='\t' */) {
        std::string elem_s;
        std::ifstream inf;
        vector1d rval;

        inf.open(filename);

        while(std::getline(inf, elem_s, delimiter)) {

            // std::cout << "element read: " << elem_s << std::endl;

            rval.push_back(std::stod(elem_s));
        }

        inf.close();
        return rval;

    }

    // bool dlmwrite(std::string filename, vector2d vec2d, char delimiter/* ='\t' */) {
    //     return dlmwrite(filename.c_str(), vec2d, delimiter);
    // }

    bool dlmwrite(const char* filename, vector2d vec2d, char delimiter/* ='\t' */, bool append/* =false */) {

        auto filemode = std::ios::out;
        if (append)
        {
            filemode = filemode | std::ios::app;
        }

        std::ofstream outf;
        outf.open(filename, filemode);
        int nrows = vec2d.size();
        int ncols = vec2d[0].size();
        for (int i = 0; i < nrows; i++)
        {
            vector1d row = vec2d[i];
            for (int j = 0; j < ncols; j++)
            {
                outf << row[j];
                if (j < ncols-1) {
                    outf << delimiter;
                }
            }
            outf << "\n";
        }

        outf.flush();
        outf.close();
        return true;

    }


    // bool dlmwrite(std::string filename, vector1d vec1d, char delimiter/* ='\t' */) {
    //     return dlmwrite(filename.c_str(), vec1d, delimiter);
    // }

    bool dlmwrite(const char* filename, vector1d vec1d, char delimiter/* ='\t' */, bool append/* =false */) {
        std::ofstream outf;

        auto filemode = std::ios::out;
        if (append)
        {
            filemode = filemode | std::ios::app;
        }


        outf.open(filename, filemode);
        int nelem = vec1d.size();
        for (int j = 0; j < nelem; j++)
        {
            outf << vec1d[j];
            if (j < nelem-1) {
                outf << delimiter;
            }
        }
        outf << "\n";
        outf.flush();
        outf.close();
        return true;
    }


} // namespace nscpp
