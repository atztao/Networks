import numpy as np
import matplotlib.pyplot as plt

lines = open("sandpile-model_S.txt").readlines()
for i in range(len(lines)):
    lines[i] = lines[i].strip('\n')
    lines[i] = lines[i].split(':')
    
# lines

# print(lines[0][1])
#?lines[0][1]

S = []
P = []

for i in range(len(lines)):
    S.append(int(lines[i][0]))
    P.append(int(lines[i][1]))

S = np.asarray(S)    
P = np.asarray(P)

# for i in range(len(P)):
#     P[i] = P[i] / 100000
# print(P)

plt.title(r"$Sandpile-Model:D(S) \sim S^{- \alpha }$")
plt.xlabel(r"$S$")
plt.ylabel(r"$D(S)$")
plt.loglog(S,P /100000000,'.b')
#plt.plot(S,P /100000)
plt.savefig("sandpile_model_S.png")
plt.show()
# #S = np.array[S]

lines2 = open("sandpile-model_T.txt").readlines()
for i in range(len(lines2)):
    lines2[i] = lines2[i].strip('\n')
    lines2[i] = lines2[i].split(':')
    
#lines2

#print(lines2[0][1])
#?lines[0][1]

S2 = []
P2 = []

for i in range(len(lines2)):
    S.append(int(lines2[i][0]))
    P.append(int(lines2[i][1]))

S = np.asarray(S2)    
P = np.asarray(P2)

# for i in range(len(P)):
#     P[i] = P[i] / 100000
# print(P)

plt.title(r"$Sandpile-Model:D(S) \sim T^{- \beta }$")
plt.xlabel(r"$T$")
plt.ylabel(r"$D(S)$")
plt.loglog(S2,P2 /100000000,'.b')
#plt.plot(S,P /100000)
plt.savefig("sandpile_model_T.png")
plt.show()
# #S = np.array[S]
