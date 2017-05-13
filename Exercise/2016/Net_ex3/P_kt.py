import networkx as nx
import numpy as np
import matplotlib.pyplot as plt
import math

h = 1
k_average = 1
N = 100


def p(k):
    return np.exp(-k_average) * k_average**k / math.factorial(k)


def f(k):
    return k + 1


def f_avg(k):
    sum_f_k_avg = []
    for i in range(k):
        f_k = f(k) * p(k)
        sum_f_k_avg.append(f_k)
    f_avg = sum(sum_f_k_avg)
    return f_avg


def pt(k, t):
    p_k0 = []
    p_kt = []
    for i in range(-t, t + 1, 1):
        p_k0.append(p(k + i))
    for i in range(t):
        kt = []
        for l in range(-t + i, t - i + 1, 1):
            kt.append(k + l)
        for j in range(2 * (t - i) - 1):
            p_kt.append((h / N) * ((-f_avg(kt[j + 1]) * (f(kt[j]) * p_k0[j] - f(kt[j + 1]) * p_k0[j + 1]) + (
                1 / k_average) * (-kt[j + 1] * p_k0[j + 1] + (kt[j + 2]) * p_k0[j + 2])) + p_k0[j + 1]))
        p_k0 = []
        p_k0 = p_kt
        p_kt = []
    return p_k0

print(pt(100, 56))
