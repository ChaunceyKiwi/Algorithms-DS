# Divide and conquer
Divide and conquer algorithms is a recursive algorithm, it will call itself to solve sub-problem.

1. Split a problem into subproblems (Divide)
2. Solve subproblem recursively (Conquer)
3. Combine solutions to subproblems (Combine)

* Merge sort
* Closest pair
* Integer multiplication

## Content
* Merge sort
	* Split a given squence into halves
	* By calling itself to sort two halves
	* Merge two sorted arrays into one

* Closest pair
	* Brute-force algorithm runs in O(n^2) time
	* Divide conquer runs in O(n logn)
		* Split the set of points into two halves
		* Find the closest pairs in halves
		* Check if there is a close pair crossing the border 
 
* Integer multiplication
	* x = x1 * 2^(n/2) + x0
	* y = y1 * 2^(n/2) + y0
	* xy = x1y1 * 2^n + ((x1+x0)(y1+y0) - x1y1 - x0y0) + x0y0
	* Only need 3 recursive calls: x1y1, x0y0, (x1+x0)(y1+y0)
	* T(n) = 3 * T(n/2) + Cn
	* Thus time complexity is O(n^log3) = O(n^1.59)