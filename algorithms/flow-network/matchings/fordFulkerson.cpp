#include "NetworkFlow.hpp"

// main function
int NetworkFlow::fordFulkerson() {
  NetworkFlow rNetworkFlow = NetworkFlow(*this);
  int max_flow = 0;

  while(rNetworkFlow.updateFlow()) {
    rNetworkFlow.augmentFlow();
    max_flow += rNetworkFlow.bottleneckOfFlow;
  }

  return max_flow;
}

void NetworkFlow::updateBottleneckOfFlow() {
  int bottleneck = INT_MAX;
  for (int i = this->sink; i != this->source; i = this->flow[i]) {
    bottleneck = min(this->adjacencyMatrix[flow[i]][i], bottleneck);
  }
  this->bottleneckOfFlow = bottleneck;
}

void NetworkFlow::augmentFlow() {
  this->updateBottleneckOfFlow();

  for (int i = this->sink; i != this->source; i = this->flow[i]) {
    this->adjacencyMatrix[flow[i]][i] -= this->bottleneckOfFlow;
    this->adjacencyMatrix[i][flow[i]] += this->bottleneckOfFlow;
  }
}

// BFS to update flow
bool NetworkFlow::updateFlow() {
  bool discovered[this->verticesCount];
  for (int i = 0; i < this->verticesCount; i++) {
    discovered[i] = false;
  }
  discovered[this->source] = true;

  queue<int> myqueue;
  myqueue.push(source);
  while(!myqueue.empty()) {
    int elem = myqueue.front();
    myqueue.pop();
    for (int i = 0; i < this->verticesCount; i++){
      if (discovered[i] == false && this->adjacencyMatrix[elem][i] != 0) {
        discovered[i] = true;
        this->flow[i] = elem;
        myqueue.push(i);
      }
    }
  }
  return discovered[this->sink];
}
