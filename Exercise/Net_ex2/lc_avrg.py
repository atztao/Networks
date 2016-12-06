#!/usr/bin/env python
# -*- coding: utf-8 -*-

import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

l_average_list = []
c_average_list = []

p = np.linspace(0.01, 0.1, 20)

for i in range(len(p)):
    l_avg_list = []
    c_avg_list = []
    for j in range(20):
        l_average = nx.average_shortest_path_length(
            nx.watts_strogatz_graph(1000, 10, p[i]))
        c_average = nx.average_clustering(
            nx.watts_strogatz_graph(1000, 10, p[i]))
        l_avg_list.append(l_average)
        c_avg_list.append(c_average)
    l_average_list.append(float(sum(l_avg_list) / len(l_avg_list)))
    c_average_list.append(float(sum(c_avg_list) / len(c_avg_list)))

plt.title(r"$p-\bar l$")
plt.xlabel(r"$p$")
plt.ylabel(r"$\bar l$")
plt.legend()
plt.plot(p, l_average_list, label=r"$\bar l$",
         color="blue", linewidth=0, marker='o')
plt.legend()
plt.savefig("l_average.png")
plt.show()

plt.title(r"$p-\bar c$")
plt.xlabel(r"$p$")
plt.ylabel(r"$\bar c$")
plt.plot(p, c_average_list, label=r"$\bar l$",
         color="red", linewidth=0, marker='o')
plt.legend()
plt.savefig("c_average.png")
plt.show()

print "p = %s" % p
print "average_shortest_path_length = %s " % l_average_list
print "average_clustering = %s" % c_average_list
