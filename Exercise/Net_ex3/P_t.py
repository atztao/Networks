from scipy.integrate import odeint
import numpy as np
import matplotlib.pyplot as plt


def Net(P, t):
    a = 0.5
    return a * P

t = np.linspace(0.0, 100, 100)

y = odeint(Net, 1, t)

plt.plot(t, y)
plt.xlabel('t')
plt.ylabel('P(t)')
plt.savefig("P_t.png")
plt.show()
