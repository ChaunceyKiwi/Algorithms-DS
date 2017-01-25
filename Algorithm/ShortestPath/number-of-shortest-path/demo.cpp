#include <iostream>
#include "Graph.hpp"
using namespace std;

int main (void) {
  Graph g(8);
  g.addEdge(0, 1, 98);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 5, 2);
  g.addEdge(0, 3, 99);
  g.addEdge(3, 4, 1);
  g.addEdge(4, 5, 1);
  g.addEdge(0, 6, 3);
  g.addEdge(6, 7, 1);
  g.addEdge(7, 5, 97);
  g.addEdge(3, 2, 0);
  g.calculate_shortest_path_from_to(3, 5);
  return 0;
}
