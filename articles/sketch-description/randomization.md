# Randomization
* Why randomize
* Contention resolution
* Global minimum cut
* Contraction algorithm
* Guessing cards
* Coupon collector 
* MaxSat
* Chernoff bound
* Closest pair
* Primes

## Content
* Why randomize
	* Can lead to simplest, fastest, or only know algorithm for a particular problem
 
* Contention resolution
	* Protocol: each process requests access to the database at time t with probability 1/n
	* Let probability S[i, t] denote the event that process i succeeds in accessing the database at time t. Then
		* 1/(en) <= Pr(S[i,t]) <= 1/2n
		* Proof: Pr(S[i,t]) = 1/n * (1 - 1/n)^(n-1)

* Contraction algorithm
	* Global minimum cut
	* Instance: A connectd, undirected graph G = (V, E)
	* Find a cut (A, B) of minimum cardinality 
	* The probability that none of edge on minimum cut is contracted is less than 2/(n^2)

* Guessing cards
	* Memoryless guessing
		* E[X\_i] = 1/n
		* E[X] = E[X\_1] + E[X\_2] + ... + E[X\_n] = n
	* Guessing with memory
		* E[E\_i] = 1/(n-i-1)
		* E[X] = E[X\_1] + E[X\_2] + ... + E[X\_n] = 1/n + 1/(n-1) ... + 1 = H(n) 
		* ln(n+1) < H(n) < ln(n) + 1
		
* Coupon collector 
	* Let X\_j denote the number of steps you spend in phase j
	* E[X] = E[X\_0] + E[X\_1] + ... + E[X\_n] = sum_{j=0}^{n-1}(n / (n-j)) = nH(n)
	 
* MaxSat
	* E[Z] = sum_{j=1}^{k}E\[Z\_j\]=7k/8
	* The probability that a random assignment satisfies more than 7/8 k clauses is k/8
	 
* Chernoff bound
* Closest pair
* Primes