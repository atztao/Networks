#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Cal the ER_Random of betweenness_centrality and edge_betweenness_centrality
import itertools
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
G = nx.random_graphs.erdos_renyi_graph(100, 0.5)

degree = nx.degree_histogram(G)
k = range(len(degree))

sigma_m1 = nx.betweenness_centrality(G)
#sigma_m2 = nx.edge_betweenness_centrality(G)
#sigma_m3 = nx.betweenness_centrality_subset(G)
#sigma_m4 = nx.edge_betweenness_centrality_subset(G)

print "betweenness_centrality = %s" % sigma_m1
# print "\n \n \n edge_betweenness_centrality = %s" % sigma_m2
# print sigma_m3
# print sigma_m4
#plt.bar(range(len(sigma_m1)), sigma_m1.values(), align='center')
#plt.xticks(range(len(sigma_m1)), sigma_m1.keys())
#plt.plot(sigma_m1[:,0],sigma_m1[:,0],label=r"\bar l",color="blue",linewidth=0,marker= 'o')

plt.title(r"$k- \sigma (m)$")
plt.xlabel(r"$k$")
plt.ylabel(r"$\sigma (m)$")
plt.plot(*zip(*sorted(sigma_m1.items())), color="red", linewidth=0, marker='o')
plt.legend()
plt.savefig("betweenness_centrality.png")
plt.show()
