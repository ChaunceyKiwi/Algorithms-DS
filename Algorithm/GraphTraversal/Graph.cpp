#include "Graph.hpp"

Graph::Graph(int verticesCount) {
  this->verticesCount = verticesCount;
  this->adjacencyLists = new list<int>[verticesCount];
}

void Graph::addEdge(int index1, int index2) {
  this->adjacencyLists[index1].push_back(index2);
}


