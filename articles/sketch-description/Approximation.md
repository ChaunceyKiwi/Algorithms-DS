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
	* Greedy algorithm
		* Assign job to machine whose load is smallest so far
		* A 2-approximation algorithm
	* Longest Processing Time
		* Sort n jobs in descending order of processing time, and then run list scheduling algorithm
		* A 1.5-approximation algorithm

* Center Selection Problem
	* Select k centers C so that maximum distance from a site to the nearest center is minimized.
	* Greedy algorithm is a 2-approximation algorithm for center selection problem.

* Pricing Method
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
	* Knap-sack

* Inapproximability
	* Meteric center selection
	* Dominating set
	* Travelling saleman problem
	* Hamilton cycle
	* Maximum independent set
	* Maximum Clique
