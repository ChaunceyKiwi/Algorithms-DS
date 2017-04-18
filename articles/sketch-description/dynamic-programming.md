# Dynamic programming
Dynamic programming solves a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solutions.

The next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time at the expense of storage space.

* Knapsack
* Shortest path
* Sequence Alignment

## Content
* Knapsack
	* Let OPT(n, W) denote the maximal value of a selection of object out of {1, 2, ... n} such that the total weight of selection does not exceed W.
	* OPT(n, W) = max{ OPT(n-1, W), OPT(n-1, W - w\_n) + v\_n }

* Shortest path
	* If negative length is not allowed, just use greedy algorithm. 
	* There should be no negative circles, and in this way the number of arcs needed at most |V| - 1, since the path should be a simple
	* Let OPT(i, v) denote the minimum weight of a path from v to t using at most i arcs.
	* OPT(i, v) = min{ OPT(i-1, v), min_{w in V}{opt(i-1, w) + len(vw) }}
	* Time complexity: 
		* i < |V-1|, thus the table size is |V|^2
		* It takes O(n\_v) to compute each cell, where n\_v is number of edge connected to veretx n. 
		* Thus the time complexity is O(|V| * |V| * n\_v) = O(|V|*|E|)
	* Finding negative circle
		* Augument graph by connect each nodes to a new node t, with length as 0.
		* Run Bellman-Ford algorithm with source as t.
		* There is no negative cycle with a path to t if and only if OPT(n, v) = OPT(n-1, v).
	 
* Sequence Alignment
	* Let OPT(i, j) denote the minimum cost of an alignment between x\_1, x\_2, x\_3, ..., x\_i and y\_1, y\_2, y\_3, ..., y\_j.
	* OPT(i, j) = min { OPT(i-1, j-1) + alpha_{x\_i, j\_i}, OPT(i-1, j) + delta, OPT(i, j-1) + delta }
	* Time complexity: We fill up an m by n table and spend constant time on each entry. Thus the time complexity is O(mn).
	