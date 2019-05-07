import numpy as np
import matplotlib.pyplot as plt
import os

os.system ("g++ JuanVelasquez_Ejercicio29.cpp")
os.system ("./a.out")

a = np.loadtxt("data.dat")

figura = plt.figure(figsize = (20,15))
plt.subplot(1,2,1)
x = np.linspace(1,len(a[0]),1000)
plt.plot(x/100,a[0],label = 'Tiempo inicial')
plt.plot(x/100,a[-1],label = 'Tiempo final')
plt.xlabel("Posición[metros]")
plt.ylabel("Desplazamiento[metros]")
plt.legend(loc = 0)

ax = figura.add_subplot(1,2,2,projection = '3d')
x,y = np.mgrid[0:a.shape[0], 0:a.shape[1]]
plot = ax.plot_surface[x,y,a]
plt.savefig("grafica.png")
               


