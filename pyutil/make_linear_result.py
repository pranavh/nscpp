#! /usr/bin/env python3

import sys
import os.path
import numpy as np

import matplotlib
matplotlib.use('Agg')
from matplotlib import pyplot as plt

wdir = sys.argv[1]

xvals_file = os.path.join(wdir, sys.argv[2])
uvals_file = os.path.join(wdir, sys.argv[3])

plotstyle = sys.argv[4]

imgfilespec = sys.argv[5]

print(f"Reading xvals from file {xvals_file}")
xvals = np.loadtxt(xvals_file)
print(f"Reading uvals from file {uvals_file}")
uvals = np.loadtxt(uvals_file)

n_timesteps = uvals.shape[0]

xlims = [np.min(xvals), np.max(xvals)]
ylims = [np.min(uvals), np.max(uvals)]

plt.figure()

for tt in range(n_timesteps):
    plt.plot(xvals, uvals[tt, :], plotstyle)
    plt.xlim(xlims)
    plt.ylim(ylims)
    plt.title("Timestep {:d}".format(tt))
    imname = os.path.join(wdir, imgfilespec.format(tt))
    plt.savefig(imname)
    plt.clf()
    print(f"Created image {imname} for timestep {tt}")


