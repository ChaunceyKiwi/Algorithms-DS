# Network flow
* Concept
* Ford-Falkerson algorithm
* Max flow vs Min cut
* Matchings
* Disjoint Paths
* Demands and Bounds
* Airline Scheduling
* Image Segmentation Problem

## Content
* Some concepts to do with network flows
	* Source s, sink t, capacity c\_e
	* Nodes other than s and t are called internal
	* Flow is a function f: E -> R+ such that
		* Capacity condition
		* Conservation condition
		* The value of flow: sum_{e out of s} f(e) 
	* Residual graph
		* Forward edge
		* Backward edge
		* Residual capacity: capacity of an edge in the residual graph
	* Cuts: 
		* A partition of G into two sets, A and B, so that s is in A, and t is in B.
		* The capacity of the cut is c(A, B) = sum_{e out of A} c\_e.
		

* Ford-Falkerson algorithm
	* A greedy algorithm that computes the maximum flow in a flow network
	* Running time O(mC) where C is the total capacity of arcs leaving s

* Max flow vs Min cut

* Matchings
	* Objective: find a matching in G of maximal size
	* Algorithms:
		* Orient all edges from X to Y
		* Add source s and sink t
		* Add arcs from s to X, and from Y to t
		* Set the capacity of all arcs as 1
	* Time complexity: O(mn)
	* Perfect matching and Hall's theorem
		* Perfect matching: a matching includes all vertices of the graph
		* Hall's theorem: If G is a bipartite graph, and for any A belongs to X and B belongs to Y, we have |A| <= |N(A)| and |B| >= |N(B)|, then there is a perfect matching of G.

* Disjoint Paths
	* A set of paths are said to be disjoint if they do not have common edges
	* The Directed Edge-Disjoint Paths Problem
		* Define a flow network by making s and t the source and the sink, and set the capacity of each arc to be 1 
		* Use Ford-Falkerson algorithm to find a maximal set of edge-disjoint paths in a digraph in O(mn) time 
	* The Undirected Edge-Disjoint Paths Problem
		* Replace every edge of G with two arcs going into opposite directions
		* Remove arcs coming into s, and going out of t 
		* In this way, the problem is translate to The Directed Edge-Disjoint Paths Problem

* Demands and Bounds
	* Flow network with multiple souces and sinks
	* Every vertex v has demand d\_v
		* If demand is positive, it acts like a sink.
		* If demand is negative, it acts like a source.
	* Conditions
		* Capacity condition
		* Demand condition
	* The idea is to add new source and sink
	* Lower Bounds
		* For the problem with lower bound, we can eliminate it by some translation.  


* Airline Scheduling

* Image Segmentation Problem