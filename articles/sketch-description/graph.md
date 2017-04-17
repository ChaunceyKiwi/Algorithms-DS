
# Graph
* BFS, DFS

# Content
* Some concepts to do with graphs.

	* Regular graph: every vertex has the same degree
	* Handshaking lemma: every finite undirected graph has an even number of vertices with odd degree
	* Simple path: A path that does not have repeating vertices
	* Biparite: a graph is biparite if it does not contain odd circles
	* Eular graph: visit every edge exactly once
	* Hamilton graph: visit each vertex exactly once (NP-complete)

* Then algorithm on graph traversal: 

	* BFS: breadth first search. Using queue.
	* DFS: depth first search. Using stack.
	* Running time is O(|V| + |E|)
		* Initialization of discov is O(|V|)
		* Time spent scanning adjacency lists is O(|E|)


* Use BFS to check if a graph is bipartite: 
	1. Assign RED color to the source node. 
	2. Assign BLUE color to its neighbors. 
	3. Assign RED color to neighbors' neighbors. 
	4. Keep doing these until all vertice are colored. 
	5. During the process, if there is a vertex to be colored already has a color and its color is different with the color to be assigned, then the graph is not a biparte.