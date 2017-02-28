# Exercises for Chapter4

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