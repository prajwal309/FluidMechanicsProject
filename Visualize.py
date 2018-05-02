import numpy as np
import matplotlib.pyplot as plt

'''
This module create the visualization for the output
'''

Data = np.genfromtxt("Data.txt", delimiter=',')
DIM = len(Data) #Dimension of the data

Rad = DIM*0.35
print
Theta = np.linspace(0,2.0*np.pi,500)

XCirc = Rad*np.sin(Theta)+ DIM/2.0-0.5
YCirc = Rad*np.cos(Theta)+ DIM/2.0-0.5

plt.figure()#figsize=(10,10),dpi=80)
plt.imshow(Data,  cmap=plt.cm.viridis, interpolation='nearest')
plt.plot(XCirc,YCirc,  "k:", lw=3 )
plt.colorbar()
plt.axis('off')
plt.tight_layout()
plt.show()

#Read the file
