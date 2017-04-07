import numpy as np
import matplotlib.pyplot as plt

#lines3 = open("sandpile-model_N.txt").readlines()
#for i in range(len(lines3)):
#    lines3[i] = lines3[i].strip('\n')
#
#S3 = range (0,10000000,1)
#P3 = []
#
#for i in range(len(lines3)):
#    P3.append(int(lines3[i]))
#
#P3 =np.asarray(P3)
#
#plt.title(r"$Sandpile-Model:N \sim T$")
#plt.xlabel(r"$T$")
#plt.ylabel(r"$N$")
#plt.plot(S3,P3,'.b')
##plt.plot(S,P /100000)
#plt.plot(506652, 20436, 'or')
#plt.savefig("sandpile_model_N.png")
#plt.show()

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
    S2.append(int(lines2[i][0]))
    P2.append(int(lines2[i][1]))

S2 = np.asarray(S2)    
P2 = np.asarray(P2)

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
