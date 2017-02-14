#include "Graph.hpp"

Graph::Graph(int verticesCount) {
  this->verticesCount = verticesCount;
  this->adjacencyLists = new list<pair<int, float>>[verticesCount];
}

void Graph::addEdge(int index1, int index2, float cost) {
  this->adjacencyLists[index1].push_back(make_pair(index2, cost));
}

Graph Graph::getAugmentedGraph() {
  Graph g(this->verticesCount + 1);
  
  for (int i = 0; i < verticesCount; i++) {
    for (pair<int, float> cost : this->adjacencyLists[i]) {
      g.addEdge(i, cost.first, cost.second);
    }
    g.addEdge(i, this->verticesCount, 0);
  }
  return g;
}
