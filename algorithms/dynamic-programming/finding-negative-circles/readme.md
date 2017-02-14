# Finding negative circles in a graph
## Main idea
  * To find negative circles in a graph, firstly we augmented it to make it easier to handle, then apply Bellman-ford algorithm to the augumented graph.
## Lemma
  * There is no negative cycle with a path to t if and only of OPT(n, v) = OPT(n - 1, v).
  * If G has n nodes and OPT(n,v) != OPT(n-1,v), then a path P of weight OPT(n,v) contains a cycle C, and C is negative.
  * Chauncey's idea (roughly proved): If a graph contains a negative circle, then exists such a v that OPT(n, v) != OPT(n - 1, v).