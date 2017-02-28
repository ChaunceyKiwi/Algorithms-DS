# Exercises for Chapter3

### Solved Exercise1
Find all topological orderings in the graph given.

#### Answer
Skip

### Solved Exercise2

Give a polynomial-time algorithm that decides whether there exists an interference-free schedule by which each robot can get to its destination.

#### Answer

Construct the following graph H. Firstly set the nodes of H as all possible pairs of nodes in G. Then delete the pairs that will lead to the interference, which has the distance <= r. Then join two nodes of H by an edge if thet can be consecutive in a schedule: (u, v) and (u', v') can be connected if one of pairs u, u' and v, v' are equal, and another pair corresponds to an edge in G. Then we run connectivity algorithm (like DFS and BFS) from (a, b) to (c, d).

##### Analysis on soundness: 
Since the path in H corresponds to a schedule. And all nodes in H are interference-free. Thus we can guarantee that the schedule we derived from the path is feasible.

##### Analysis on time complexity:
1. To construct the H, firstly there are n^2 nodes. A node can be connected to another N nodes at most. When summing them up, the actual number is m = | E |. Thus the time complexity is O(mn).
2. To delete the nodes that are interfered with each other, we can apply BFS to each nodes in the original graph G. For example, from a point u, we find the nodes v that are within the distanec r. Then we delete all the node pairs (u, v) in H. Each BFS needs O(m+n), with n nodes to apply BFS we need O(mn+n^2) in all.
3. To find the path from (a, b) to (c, d) in graph H, since there are n^2 nodes and mn edges, when applying BFS we need O(n^2+mn).

All the steps above take polynomial time. Thus the whole algorithm can be run in polynomial time.