# Greedy algorithms
A greedy algorithm makes the locally optimal choice at each stage, with the hope of finding a global optimum.

Make sure algorithms stays ahead in each step.

* Dijsktra's algorithm

## Content
* Dijsktra's algorithm
	* Do a while loop, in each loop, add a undiscovered node to discovered set and its shorest distance to the source.
	* Time complexity
		* In straightfoward implmentation, require |V| iterations of the  while loop, each check |E| edges, thus given O(|V|*|E|)
		* Can achieve O(|E| * log|V|) with heaps to get closest node in each iteration. 