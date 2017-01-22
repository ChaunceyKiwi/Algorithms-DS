# Djikstra's Algorithm Soundness Analysis
* Theorem: For any node v, the path s, ..., P(v), v is a shortest s-v path
* Proof:
  * Base case: If |S| = 1, then S = {s}, and d(s) = 0. (The set only contains the start point itself and it is obvious the path to itself is staying at original place)
  * Induction case:
    * Denote P(v) as u, and suppose the caim holds for path s, ..., u, which means it is the shorest path for any points in S.
    * Using the algorihm v is added to S. Due to the selection of the algorithm we know 
        * For any points a in S:
            * min(len(s->a)) + dis(a,v) <= len(s->u) + dis(u,v).
        * For any points x in S, y not in S
            * min(len(s->x)) + dis(x,y) <= len(s->x) + dis(x,y).
    * Thus we can not find a path from s to v which has a length less than the path through u we used above.