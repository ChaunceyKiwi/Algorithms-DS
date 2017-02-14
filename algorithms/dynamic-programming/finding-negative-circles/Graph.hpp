#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <list>
#include <utility>
#include <iostream>
#include <climits>
#include <set>

using namespace std;

class Graph {
private:
  int verticesCount;
  list<pair<int, float>> *adjacencyLists;
public:
  Graph(int verticesCount);
  void addEdge(int index1, int index2, float cost);
  bool existShortestGraph();
  Graph getAugmentedGraph();
};

#endif /* Graph_hpp */
