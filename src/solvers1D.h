#ifndef LINCONV_H
#define LINCONV_H

#include<iostream>
#include<vector>
#include<chrono>

#include<boost/format.hpp>

#include "types.h"
#include "fileops.h"
#include "vectorutils.h"

namespace nscpp
{
    void demo_linconv();
    long int linconv(vector1d u_init, vector1d x, double c, int nt, double dt, char* filespec="linconv.dat", int writefreq=1, bool showstatus=false);

    void demo_nonlinconv();
    long int nonlinconv(vector1d u_init, vector1d x, double c, int nt, double dt, char* filespec="nonlinconv.dat", int writefreq=1, bool showstatus=false);
} // namespace nscpp

#endif