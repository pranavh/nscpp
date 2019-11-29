/**
 * fileops.h
 * Pranav Hosangadi
 * 2019-11-28
 * File handling helper functions
**/

#ifndef FILEOPS_H
#define FILEOPS_H

#include<vector>
#include<string>
#include<fstream>
#include<sstream>
// #include<boost/algorithm/string.hpp>
#include "types.h"

namespace nscpp
{
    bool iscomment(char c);

    vector2d dlmread(char* filename, char delimiter='\t');
    vector2d dlmread(std::string filename, char delimiter='\t');

    vector1d dlmread1d(char* filename, char delimiter='\t');
    vector1d dlmread1d(std::string filename, char delimiter='\t');

    bool dlmwrite(const char* filename, vector2d vec2d, char delim='\t', bool append=false);
    // bool dlmwrite(std::string filename, vector2d vec2d, char delim='\t');

    bool dlmwrite(const char* filename, vector1d vec1d, char delim='\t', bool append=false);
    // bool dlmwrite(std::string filename, vector1d vec1d, char delim='\t');

} // namespace nscpp

#endif