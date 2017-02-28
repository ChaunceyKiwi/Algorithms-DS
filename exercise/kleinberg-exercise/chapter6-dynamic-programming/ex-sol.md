# Exercises for Chapter6

### Solved Exercise1
Give an algorithm that takes an instance of this problem as input and returns the maximum total revenue that can be obtained from any valid subset of sites. The running time of the algorithm should be polynomial in n.

#### Answer

##### my version (seems wrong)
opt[n,m] = max{ opt[n-1, m], opt[n-1, m-1] + r_n }

##### stardard version
opt[j] = max{ opt[j-1], opt[e(j)] + r_j }

### Solved Exercise2
The problem is to find a concatenation over {Bi} for which the sequence alignment cost is as small as possible. (For the purpose of computing the sequence alignment cost, you may assume that you are given a gap cost δ and a mismatch cost αpq for each pair p, q ∈ S.)

#### Answer


