# Exercises for Chapter4

### Solved Exercise1
Is your friends’ greedy algorithm (hiking as long as possible each day) optimal in the sense that it finds a valid set whose size is as small as possible?

#### Answer
Yes, it is optimal. 

Proof:

Denote the solution given by greedy algorithm is {a1, a2, ..., ak}, where ak is the index of the last stop at day k. And denote the solution given by optimial algorithm is {o1, o2, ..., om} (m <= k). To prove the greedy algorithm is optimal, firstly we prove for r <= m, ar >= or.

Base case: r = 1, it is obvious a1 >= o1 because on the first day the team will go though stops as many as possible.

Induction case: assume it holds for r = t - 1, we try to prove it holds for r = t as well. Since it holds for r = t - 1, a(t-1) >= o(t-1). On the t-th day, with optimial solution the team will go through stops of index o(t-1) + 1, o(t-1) + 2, ..., o(t). Due to the fact that r(t-1) >= o(t-1), on the t-th day it is feasible to go through r(t-1) + 1, r(t-1) + 2, ... o(t) as well, and because there are less stops it is possible for to go through more stops. Thus at >= ot.

From induction we know that for r <= m, ar >= or. Thus am >= om. If greedy algorithm is not optimal, then there exist a(m+1). However, since om is the index of last stop, am can be only equal to the index of last stop, there is no stop index available for a(m+1), which leads to a contradiction. Thus greedy algorithm is optimal.

### Solved Exercise2

#### Answer
The order to buy license is based on the price growth rate. The higher rate it is, the earlier it should be bought.

Proof: If there exist a optimal solution which is not ordered with algorithm above, there must exit a pair where the earlierly bought one has lower than price growth rate. By swapping these two, we can cut down the cost, which is contradict to it is a optimal solution. Thus the optimal solution must be obtained by algorithm described.

### Solved Exercise3

#### Answer
Skipped due to not learned yet in 405

### Exercise1
Skipped due to not learned yet in 405

### Exercise2
a). Skipped due to not learned yet in 405

b). True or false? P must still be a minimum-cost s-t path for this new instance.

#### Answer
No, it is false. 3 + 4 > 8, but 3^2 + 4^2 < 8^2.

### Exercise3
a). Skipped due to have done before

### Exercise4
Give an algorithm that takes two sequences of events—S′ of length m and S of length n, each possibly containing an event more than once—and decides in time O(m + n) whether S′ is a subsequence of S.

#### Answer
Denote subsequence of Si as first i events of S (i <= n) and denote subsequence of Qj as first events of S' (j <= m).  To prove if S'm is subsequence of Sn, we can compare the last event:

1. If last event is the same, then prove if S'(m-1) is subsequence of S(n-1).

2. If last event is different, then prove if S'(m) is subsequence of S(n-1).

Repeat above steps, if it ends up with S' having 0 length, there exists. Otherwise there do not exists.

Soundness analysis: **TODO: Consider later** 

Time complexity analysis: every time the length of S will be cut down by one, thus the time complexity is linearly as O(n). 

### Exercise5
Give an efficient algorithm that achieves this goal, using as few base stations as possible.

#### Answer
From eastern endpoint to western endpoint, along the way a base station is built only when it is necessary to build it.

Proof: stay ahead. **TODO: Format answer**