#include <iostream>
#include "Graph.hpp"
using namespace std;

int main (void) {
  Graph g(7);
  g.addEdge(0, 1, 1);
  g.addEdge(0, 2, 2);
  g.addEdge(1, 2, 3);
  g.addEdge(2, 3, 5);
  g.addEdge(3, 4, 7);
  g.addEdge(4, 6, 8);
  g.addEdge(3, 5, 9);
  g.calculate_shortest_path_from(0);
  cout << endl;
  cout << g.calculate_shortest_path_from_to(0, 6) << endl;
  cout << g.calculate_shortest_path_from_to2(0, 6) << endl;
  return 0;
}
