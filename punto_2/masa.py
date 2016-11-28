import numpy as np
import matplotlib.pyplot as plt
import corner

data=np.loadtxt("datos.dat")
plt.figure(figsize=(20,20))
corner.corner(data,37,labels=[r"$log(M)$",r"$\alpha$"],show_titles=True)
plt.savefig("distribucion.pdf")
plt.close()




