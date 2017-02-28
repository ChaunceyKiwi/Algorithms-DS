# Exercises for Chapter3

### Exercise1
Find all topological orderings in the graph given.

#### Answer
1. a b c d e f
2. a b d c e f
3. a b d e c f
4. a d e b c f
5. a d b e c f
6. a d b c e f

### Exercise2
Give an algorithm to detect whether a given undirected graph contains a cycle.

#### Answer
##### Chauncey's version
Use DFS or BFS to traverse the graph, is we get to a node which is already discovered before, then we know there exists a circle. 

Soundness analysis: If we get to a node which is already discoverde before, this means we have 2 paths which can reach to the current nodes. Then the edges on these two paths can be used to form a circle.

Time complexity analysis: We can use the BFS or DFS, thus the time complexity is O(m+n). During the algorithm we will record the predecessors of each node so that we can use the back-tracking to regenerate two paths to form the circle.

##### Stardard answer
Firstly assume the graph is connected, otherwise we work with the connected components separately.

Then we run BFS to traverse the graph G and build a BFS tree T. Compare the edges of T and the edges of G. If every edge of G appears in the BFS tree, then G = T, which means that G is a tree and contains no cycles. Otherwise there is some edge e = (v, w) that belong to G but not to T. Then we find the least common ancestor u of v and w. Then we obtain a cycle from the edge e, together with the u-v and u-w paths in T.

### Exercise3
Find a cycle or a topological ording in a graph which may or may not be a DAG.

#### Answer
Run the same algorithm with following small modification. If in every iteration we find a node with no incomming edges, then we will succeed in producing a topological ordering. If in some iterations it happens that every node has at least one incomming edge, then we can infer that G must contain a cycle. By repeatedly follow an edge into the node we're currently at, we can find last node. Keep doing this until we re-vist a node for the first time. The set of nodes between these two visits is a cycles C.

### Exercise4
Give an algorithm with running time O(m+n) that determines whether the m judgments are consistent.

#### Answer

##### Chauncey's version
For each jugement with label 'different' on (u, v), we build a node for u and a node for v in a undirected graph and connect them. Then we use BFS to judge if the graph is a bipartite. If not, then the the jugements are not consistent. If it is birparite, we continue to the next step.

For each jugement with label 'same' (u, v), we check if v is in the other half in the biparite as u, if it is, then the jugements are not consistent. If it is, then we check if v is in the same half in the birparite as u. If not, we put it in. Keep doing this until all 'same' jugement is processed. If we end up with no conflicts, we can lead to the conclusion that the judgement is consistent.

Time complexity analysis: we use the BFS to check if it is a bipartite, which needs O(m + n), the later check needs O(n), thus the time complexity is O(m + n).

##### Standrd answer
Construct an undirected graph with each specimen as a node and each jugement as an edge. Note that G might not be connected.

For each connected component we designate an arbitrary node as start node, label it as A, and use graph traversal to label nodes remaining based on the jugements. If the label is 'same' and the current node is not labelled yet, we label it with the same label as its predecessor. If the label is 'different' and current node is not labelled yest, we label it with the other label compared with its predecessor. 

After that, for each edge on G, we check if each edge with label 'same' connects nodes with same labels and if each edge with label 'differnet' connects nodes with different labels. If after all checking there is no confliction found, the judgements are consistent.

Analysis: BFS needs O(m + n) and check needs O(m), thus the time complexity is O(m + n).

### Exercise5
A binary tree is a rooted tree in which each node has at most two children. Show by induction that in any binary tree the number of nodes with two children is exactly one less than the number of leaves.

#### Answer
Base case: when there is only one node in the tree. The number of nodes with two children is 0 and the number of leaves is 1. The assumption holds.

Induction case: when it holds for the current tree, which means that the tree has n nodes with two children and n + 1 leaves. When we add a node to the leave, it can have 2 cases:	

1. The new node is added to a leaf node. The number of nodes with 2 children and the number of leaves do not change. Thus the assumption still holds.

2. The new node is added to a one-child and non-leaf node. The number of nodes with 2 children and the number of leaves both increase by 1. Thus the the number of nodes with two children is still one less than the number of leaves.

Due to the fact that the assumption always holds when a new node is added to the tree. Thus the assumption always holds.
 