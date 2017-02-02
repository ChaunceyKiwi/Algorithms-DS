#include "Graph.hpp"

Graph::Graph(int verticesCount) {
  this->verticesCount = verticesCount;
  this->adjacencyLists = new list<pair<int, float>>[verticesCount];
}

void Graph::addEdge(int index1, int index2, float cost) {
  this->adjacencyLists[index1].push_back(make_pair(index2, cost));
  this->adjacencyLists[index2].push_back(make_pair(index1, cost));
}
