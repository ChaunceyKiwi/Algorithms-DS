# Approximation

* Introduction
* Loading Balancing
* Center Selection Problem
* Pricing Method
* LP-rounding
	* Weighted vertex cover
	* Integer programming
	* Generalized load balancing
* FPTAS
	* Knap-sack
* Inapproximability
	* Meteric center selection
	* Dominating set
	* Travelling saleman problem
	* Hamilton cycle
	* Maximum independent set
	* Maximum Clique

## Content
* Introduction
	* Approximation algorithms are algorithms used to find approximate solutions to optimization problems.
	* Since it is unlikely that there can ever be efficient polynomial time algorithms to solve NP-hard problems, approximation algorithms are often used to solve this kind of problem.

* Loading Balancing
	* Load: the total time needs for a machine to finsh job assigned
	* Makespan: the maximal load on any machine
	* Greedy algorithm
		* Assign job to machine whose load is smallest so far
		* A 2-approximation algorithm
			* Key idea: L\_i - t\_j <= L\*, t\_j <= L\*
	* (LPT) Longest Processing Time
		* Sort n jobs in descending order of processing time, and then run list scheduling algorithm
		* A 1.5-approximation algorithm
			* Key idea: t\_j <= L\*/2

* Center Selection Problem
	* Select k centers C so that maximum distance from a site to the nearest center is minimized
	* Greedy algorithm is a 2-approximation algorithm for center selection problem
		* Repeatly choose the next center to be the site farthest form any existing center
		* Unless P = NP, there is no approximation algorithm with rho less than 2 

* Pricing Method 
	* Weighted vertex cover 
		* Each edge must be covered by some vertex i 
		* Instance: A graph G with vertex weights
		* Objective: Find a vertex cover of minimum weight  
	* Pricing method is a 2-approximation algorithm

* LP-rounding
	* Weighted vertex cover
		* Linear programing gives a 2-approximation algorithm for weighted vertex cover
	* Integer programming
	* Generalized load balancing

* FPTAS(Fully polynomial approximation scheme)
	* PTAS: polynomial approximation scheme
		* An approximation algorithm for any constant relative error 1 +|- epsilon
		* PTAS produces arbitarily high quailty solution, but trade off accuracy for time. 
		* Used to solve the problem that is pseudo-polynomial.

	* Basic idea
		* 
		 
	* Knap-sack
		* Let OPT(i,v) denote the minimal weight subset of items 1, 2, ..., i of value exactly v
			* OPT(i, v) = 0 if v = 0
			* OPT(i, v) = postive infinity  if i = 0, v > 0
			* OPT(i, v) = OPT(i-1, v) if v\_i > v
			* OPT(i, v) = min { OPT(i-1, v), w\_i + OPT(i-1, v-v\_i) }
		* Running time: O(nV*)
		 
* Inapproximability
	* Meteric center selection
	* Dominating set
	* Travelling saleman problem
	* Hamilton cycle
	* Maximum independent set
	* Maximum Clique
