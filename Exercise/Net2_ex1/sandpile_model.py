"""
Name:Sandpile-Model
Description:This Program Simulate Sandpile Model Since It
Has Self-Organized Criticality.
Author:ztao1991@gmail.com
Date:2017/06/12
Version:1.0
""""colorscheme desert
"set background =dark


import random
# import numpy as np
import matplotlib.pyplot as plt
from collections import Counter
# from timeit import timeit
import time

N = 10

# 定义网格的大小和形状并初始化为0,SOC应该与网格的形状是无关的
sandpile_A = [[0 for i in range(N)] for j in range(N)]
sandpile_B = [[0 for i in range(N)] for j in range(N)]
# print(sandpile_A)

Data_S = []  # 记录雪崩的规模的大小
Data_T = []  # 记录雪崩的持续的时间
Data_N = []  # 记录沙盒中沙子的多少

t1 = time.time()

# 开始实验
for Add in range(1000000):
    Avalanche = -1  # 初始化雪崩的规模为0
    Time = 0  # 初始化弛豫时间为0

    sandpile_x = random.randint(0, N-1)
    sandpile_y = random.randint(0, N-1)

    sandpile_A[sandpile_x][sandpile_y] = sandpile_A[sandpile_x][sandpile_y] + 1
    sandpile_B[sandpile_x][sandpile_y] = sandpile_A[sandpile_x][sandpile_y] + 1

    # print(sandpile_A,sandpile_B)

    # 判断雪崩是否存在
    for T in range(100000000):
        Number = 0  # 判断是否存在雪崩Number == 100则不存在否则有

        # 遍历所有格子判断是否雪崩
        for x in range(N):
            for y in range(N):
                if sandpile_A[x][y] > 4:
                    if x == 0:
                        if y == 0:
                            sandpile_B[x][y] = sandpile_B[x][y] - 4
                            sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1
                            sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1
                        elif y == 9:
                            sandpile_B[x][y] = sandpile_B[x][y] - 4
                            sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1
                            sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1
                        else:
                            sandpile_B[x][y] = sandpile_B[x][y] - 4
                            sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1
                            sandpile_B[x][y-2] = sandpile_B[x][y-1] + 1
                            sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1
                    elif x == 9:
                        if y == 0:
                            sandpile_B[x][y] = sandpile_B[x][y] - 4
                            sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1
                            sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1
                        elif y == 9:
                            sandpile_B[x][y] = sandpile_B[x][y] - 4
                            sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1
                            sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1
                        else:
                            sandpile_B[x][y] = sandpile_B[x][y] - 4
                            sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1
                            sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1
                            sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1
                    elif y == 0 and x != 0 and x != 9:
                        sandpile_B[x][y] = sandpile_B[x][y] - 4
                        sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1
                        sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1
                        sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1
                    elif y == 9 and x != 0 and x != 9:
                        sandpile_B[x][y] = sandpile_B[x][y] - 4
                        sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1
                        sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1
                        sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1
                    else:
                        sandpile_B[x][y] = sandpile_B[x][y] - 4
                        sandpile_B[x][y+1] = sandpile_B[x][y+1] + 1
                        sandpile_B[x][y-1] = sandpile_B[x][y-1] + 1
                        sandpile_B[x-1][y] = sandpile_B[x-1][y] + 1
                        sandpile_B[x+1][y] = sandpile_B[x+1][y] + 1
                else:
                    Number = Number + 1

        for i in range(N):
            for j in range(N):
                sandpile_A[i][j] = sandpile_B[i][j]

        if Number == 100:
            Time = T - 1
            break

        else:
            Avalanche = Avalanche + 100 - Number

    sandpile_number = 0
    for i in range(N):
        for j in range(N):
            sandpile_number = sandpile_number + sandpile_A[i][j]
    Data_N.append(sandpile_number)

    if Add < 200000:
        Data_S.append(Avalanche)
        Data_T.append(Time)
    else:
        break

t2 = time.time()

#  Data_S_sort = Counter()
#  Data_T_sort = Counter()

#  for i in Data_S:
#      Data_S_sort[i] += 1

#  for i in Data_T:
#      Data_T_sort[i] += 1

#  print(Data_T_sort)

arr_appear_1 = Counter(Data_S)
arr_appear_2 = Counter(Data_T)

# t3 = time.time()

print("Sandpile Model Run Time: %ds" % int(t2 - t1))

# print(t3 - t2)

#  print(arr_appear_1,arr_appear_2)

lists_1 = sorted(arr_appear_1.items())
x, y = zip(*lists_1)

plt.title(r"$Sandpile-Model:N \sim Sandpile_Number$")
plt.xlabel(r"$N$")
plt.ylabel(r"$Sandoile_Number$")
plt.loglog(Data_N, '.b')
# plt.plot(S,P /100000)
plt.savefig("sandpile_model_N.png")
plt.show()

plt.title(r"$Sandpile-Model:D(S) \sim S^{- \beta }$")
plt.xlabel(r"$S$")
plt.ylabel(r"$D(S)$")
plt.loglog(x, y, '.b')
# plt.plot(S,P /100000)
plt.savefig("sandpile_model_T.png")
plt.show()

lists_2 = sorted(arr_appear_2.items())
x1, y1 = zip(*lists_2)
plt.title(r"$Sandpile-Model:D(T) \sim T^{- \beta }$")
plt.xlabel(r"$T$")
plt.ylabel(r"$D(T)$")
plt.loglog(x1, y1, '.b')
plt.savefig("sandpile_model_T.png")
plt.show()
