#include "NetworkFlow.hpp"

NetworkFlow::NetworkFlow(int verticesCount, int source, int sink) {
  this->verticesCount = verticesCount;
  this->adjacencyMatrix = vector<vector<int>>(verticesCount, vector<int>(verticesCount));
  this->flow = vector<int>(verticesCount);
  this->source = source;
  this->sink = sink;
  this->bottleneckOfFlow = 0;
}

void NetworkFlow::addEdge(int index1, int index2, int cost) {
  this->adjacencyMatrix[index1][index2] = cost;
}

NetworkFlow::NetworkFlow(const NetworkFlow& other) {
  this->verticesCount = other.verticesCount;
  this->adjacencyMatrix = vector<vector<int>>(other.verticesCount, vector<int>(other.verticesCount));
  this->flow = vector<int>(other.verticesCount);
  this->source = other.source;
  this->sink = other.sink;
  this->bottleneckOfFlow = 0;

  for (int i = 0; i < verticesCount; i++) {
    for (int j = 0; j < verticesCount; j++) {
      this->adjacencyMatrix[i][j] = other.adjacencyMatrix[i][j];
    }
  }
}
