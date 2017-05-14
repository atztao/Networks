import numpy as np
import matplotlib.pyplot as plt

lines3 = open("sandpile-model_N.txt").readlines()
for i in range(len(lines3)):
    lines3[i] = lines3[i].strip('\n')

S3 = range (0,50000,1)
P3 = []

for i in range(len(lines3)):
    P3.append(int(lines3[i]))

P3 =np.asarray(P3)

plt.title(r"$Sandpile-Model:N \sim T$")
plt.xlabel(r"$T$")
plt.ylabel(r"$N$")
plt.plot(S3,P3,'.b')
#plt.plot(S,P /100000)
# plt.plot(506652, 20629, 'or')
plt.savefig("sandpile_model_N.png")
plt.show()


