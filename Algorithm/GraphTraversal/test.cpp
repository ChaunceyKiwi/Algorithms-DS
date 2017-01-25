#include <iostream>
#include "Graph.hpp"
using namespace std;

int main (void) {
  Graph g(6);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 5);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);

  cout << "Breath First Tranversal results:" << endl;
  g.BFS(0);
  cout << "Depth First Tranversal results:" << endl;
  g.DFS(0);
  cout << "Number of shortest path from node0 to node5 is:"<< endl;
  cout << g.countShortestPathFromTo(0, 5) << endl;
  
  return 0;
}
