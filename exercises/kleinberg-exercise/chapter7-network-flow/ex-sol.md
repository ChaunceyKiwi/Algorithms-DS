# Exercises for Chapter7

### Solved Exercise1
 Show how to find a maximum flow in the resulting capacitated graph in time O(m + n), where m is the number of edges in G and n is the number of nodes.
 
#### Answer
By the Max-Flow Min-Cut Theorem, we know that there is a Min-Cut in the original flow network G that has a capacity of v(f). In G' all the edges crossing (A, B) has the same capacity as G, with the possible exception
that the cut cross the edge e. Since the capacity of e is only increased by 1, so the capacity of c(A, B) in G' is at most v(f) + 1.

Since the flow can only be cut down by at least one, we try to find a single augumenting path from s to t in the residual graph, which needs O(m+n).
 
### Solved Exercise2
Give a polynomial-time algorithm that takes this information and deter- mines whether it is possible to select a single doctor to work on each vacation day, subject to the following constraints.

The algorithm should either return an assignment of doctors satisfying these constraints or report (correctly) that no such assignment exists.

#### Answer
By adding a gadget.

