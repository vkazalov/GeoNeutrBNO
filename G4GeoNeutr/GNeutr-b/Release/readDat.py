print "START!"

from ROOT import *
import matplotlib.pyplot as plt
import numpy as np
from scipy import signal


r1 =TRandom();

SpcE1=np.loadtxt("e:/GeoNutr/G4GeoNeutr/GNeutr-b/Release/Cs137.dat",usecols=[0], unpack=True)
SpcE2=np.loadtxt("e:/GeoNutr/G4GeoNeutr/GNeutr-b/Release/Cs137.dat",usecols=[1], unpack=True)






plt.figure(1)
plt.plot(SpcE1,'r',linewidth = 1.5,label="LS")
plt.plot(SpcE2,'b',linewidth = 1.5,label="Water")
plt.grid(True)
plt.legend()



plt.show()



