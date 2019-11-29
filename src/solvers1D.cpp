/**
 * solvers1D.cpp
 * Pranav Hosangadi
 * 2019-11-28
 * A one-dimensional linear convection equation solver
 * https://nbviewer.jupyter.org/github/barbagroup/CFDPython/blob/master/lessons/01_Step_1.ipynb
 * A one-dimensional nonlinear convection equation solver
 * https://nbviewer.jupyter.org/github/barbagroup/CFDPython/blob/master/lessons/02_Step_2.ipynb
 * A one-dimensional diffusion equation solver
 * https://nbviewer.jupyter.org/github/barbagroup/CFDPython/blob/master/lessons/04_Step_3.ipynb
 **/

#include "solvers1D.h"

namespace nscpp
{

    void demo_linconv() {
        std::cout << "One-dimensional linear convection equation solver" << std::endl;

        int nx = 41;
        vector1d x = linspace(nx, 0, 2);

        vector1d u_init = ones(nx);
        for (int i = 10; i < 21; i++)
        {
            u_init[i] = 2;
        }

        double c = 1;
        int nt = 250;
        double dt = 0.0025;
        dlmwrite("assets/linconv/linconv_xvals.dat", x);
        long int time = linconv(u_init, x, c, nt, dt, "assets/linconv/linconv_uvals.dat", 1, true);
        std::cout << "Finished solving " << nt << " timesteps in " << time << " ms." << std::endl;
    }

    long int linconv(vector1d u_init, vector1d x, double c, int nt, double dt, char* filespec/* ="linconv.dat" */, int writefreq/* =1 */, bool showstatus/* =false */) {

        int nx = x.size();
        vector1d u(u_init);
        vector1d u_old(u_init);

        if (writefreq > 0)
        {
            dlmwrite(filespec, u_init, '\t');
        }


        if (showstatus)
        {
            std::cout << "Solving linear convection equation for " << nt << " timesteps at " << nx << " spatial locations..." << std::endl;
            std::cout << "\t\tTimestep 0 written to " << filespec << std::endl;
        }

        auto start = std::chrono::high_resolution_clock::now();

        for (int t = 1; t <= nt; t++)
        {
            u_old = u;

            for (int i = 1; i < nx; i++)
            {
                // Backward difference
                u[i] = u_old[i] - c * dt / (x[i] - x[i-1]) * (u_old[i] - u_old[i-1]);
            }

            if (showstatus)
            {
                std::cout << "\tFinished calculating for timestep " << t << std::endl;
            }

            if (writefreq > 0 && nt % writefreq == 0)
            {
                dlmwrite(filespec, u, '\t', true);
                if (showstatus)
                {
                    std::cout << "\t\tTimestep " << t << " written to " << filespec << std::endl;
                }

            }

        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        return duration.count();

    }

    void demo_nonlinconv() {
        std::cout << "One-dimensional linear convection equation solver" << std::endl;

        int nx = 41;
        vector1d x = linspace(nx, 0, 2);

        vector1d u_init = ones(nx);
        for (int i = 10; i < 21; i++)
        {
            u_init[i] = 2;
        }

        double c = 1;
        int nt = 250;
        double dt = 0.0025;
        dlmwrite("assets/nonlinconv/nonlinconv_xvals.dat", x);
        long int time = nonlinconv(u_init, x, c, nt, dt, "assets/nonlinconv/nonlinconv_uvals.dat", 1, true);
        std::cout << "Finished solving " << nt << " timesteps in " << time << " ms." << std::endl;
    }

    long int nonlinconv(vector1d u_init, vector1d x, double c, int nt, double dt, char* filespec/* ="nonlinconv.dat" */, int writefreq/* =1 */, bool showstatus/* =false */) {
        int nx = x.size();
        vector1d u(u_init);
        vector1d u_old(u_init);

        if (writefreq > 0)
        {
            dlmwrite(filespec, u_init, '\t');
        }

        if (showstatus)
        {
            std::cout << "Solving nonlinear convection equation for " << nt << " timesteps at " << nx << " spatial locations..." << std::endl;
            std::cout << "\t\tTimestep 0 written to " << filespec << std::endl;
        }

        auto start = std::chrono::high_resolution_clock::now();

        for (int t = 1; t <= nt; t++)
        {
            u_old = u;

            for (int i = 1; i < nx; i++)
            {
                // Backward difference
                u[i] = u_old[i] - u_old[i] * dt / (x[i] - x[i-1]) * (u_old[i] - u_old[i-1]);
            }

            if (showstatus)
            {
                std::cout << "\tFinished calculating for timestep " << t << std::endl;
            }

            if (writefreq > 0 && nt % writefreq == 0)
            {
                dlmwrite(filespec, u, '\t', true);
                if (showstatus)
                {
                    std::cout << "\t\tTimestep " << t << " written to " << filespec << std::endl;
                }

            }

        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        return duration.count();
    }

} // namespace nscpp
