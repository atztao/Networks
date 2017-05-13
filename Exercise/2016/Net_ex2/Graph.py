#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np  # Import modules
import networkx as nx
import matplotlib.pyplot as plt

G = nx.watts_strogatz_graph(100, 10, 0.1)  # Make graph
plt.figure(3, figsize=(12, 12), dpi=720)
nx.draw_circular(G, with_labels=False, node_size=30)
plt.savefig("G.png")
plt.show()

l_average = nx.average_shortest_path_length(G)  # Cal parameter
c_average = nx.average_clustering(G)

print "average_shortest_path_length = %s" % l_average  # Print
print "average_clustering = %s" % c_average
