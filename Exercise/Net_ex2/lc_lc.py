#!/usr/bin/env python
# -*- coding: utf-8 -*-

import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

l_average_list = []
c_average_list = []

l_average_max = nx.average_shortest_path_length(
    nx.watts_strogatz_graph(1000, 10, 0))
c_average_max = nx.average_clustering(nx.watts_strogatz_graph(1000, 10, 0))
p = [1,
     0.00016,
     0.00028900000000000003,
     0.0004913000000000001,
     0.0008352100000000001,
     0.001419857,
     0.0024137569,
     0.004103386729999999,
     0.006975757440999999,
     0.011858787649699998,
     0.020159939004489997,
     0.034271896307633,
     0.0582622237229761,
     0.09904578032905938,
     0.16837782655940095,
     0.2862423051509816,
     0.48661191875666865,
     0.8272402618863367,
     1]

for i in range(len(p)):
    l_avg_list = []
    c_avg_list = []
    for j in range(20):
        l_average = nx.average_shortest_path_length(
            nx.watts_strogatz_graph(1000, 10, p[i])) / l_average_max
        c_average = nx.average_clustering(
            nx.watts_strogatz_graph(1000, 10, p[i])) / c_average_max
        l_avg_list.append(l_average)
        c_avg_list.append(c_average)
    l_average_list.append(float(sum(l_avg_list) / len(l_avg_list)))
    c_average_list.append(float(sum(c_avg_list) / len(c_avg_list)))

print l_average_list
print c_average_list

plt.xlabel(r"$p$")
plt.semilogx(p, l_average_list, label=r"$L(p) / L(0)$",
             color="blue", linewidth=0, marker='o')
plt.semilogx(p, c_average_list, label=r"$C(p) / C(0)$",
             color="red", linewidth=0, marker='o')
plt.legend()  # make legend
plt.savefig("lc.png")
plt.show()
