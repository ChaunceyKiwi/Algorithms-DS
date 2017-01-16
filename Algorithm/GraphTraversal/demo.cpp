#include <iostream>
#include "Graph.hpp"
using namespace std;

int main (void) {
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 6);
  g.addEdge(3, 5);
  cout << "Breath First Tranversal results:" << endl;
  g.BFS(2);
  cout << "Depth First Tranversal results:" << endl;
  g.DFS(2);
  return 0;
}
