# Choice of table size on DP

## Problem introduction
When solving the Knapsack problem, we use formula:
	
	opt(i, W) = max{ opt(i - 1, W), opt(i - 1, W - w_i) + w_i }
	
However, when solving the weighted interval scheduling problem, we use formula:
	
	opt(i) = max { opt(i-1), opt(p(i)) + v_j }
	
It confuses me for a while on why the second problem need only a one dimension array while the first need a two dimension array.

The similarity is that both of problem needs to consider whether the last item should be taken or not. Thus the first parameter is actually the same. 

The difference lies in thier constraints. 

For the first problem, to solve the sub-problem, we need to update the weight limitation, which should be passed into function as parameter. And the change of constraints depends on your last choice. 

For the second problem, the change of constraints is always the same (compatible). Thus we only can directly get the range of sub-problem.