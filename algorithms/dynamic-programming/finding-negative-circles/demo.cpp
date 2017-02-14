#include <iostream>
#include "Graph.hpp"
using namespace std;

int main (void) {
  Graph g(7);
  g.addEdge(0, 1, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 3, 1);
  g.addEdge(3, 4, 1);
  g.addEdge(4, 5, 1);
  g.addEdge(5, 6, 1);
  g.addEdge(3, 0, -7);
  
  Graph g_au = g.getAugmentedGraph();
  
  cout << g_au.existShortestGraph() << endl;
  return 0;
}
