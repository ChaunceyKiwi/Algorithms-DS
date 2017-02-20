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

### Solved Exercise3

#### Answer

