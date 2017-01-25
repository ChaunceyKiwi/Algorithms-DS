#include "Graph.hpp"

// BFS Tranversal, queue based, with time complexity as O(|V|+|E|)
void Graph::BFS(int index1) {
  // set Discov[s] := true and Discov[v] := false for v≠s
  // Time complexity: O(|V|)
  bool discovered[this->verticesCount];
  for (int i = 0; i < this->verticesCount; i++) {
    discovered[i] = false;
  }
  discovered[index1] = true;
  
  // Undiscovered vertices are enqueued, marked as discovered, and dequeued
  // Each vertex is enqueued/dequeued at most once, thus time complexity: O(|E|)
  queue<int> myqueue;
  myqueue.push(index1);
  while(!myqueue.empty()) {
    int elem = myqueue.front();
    myqueue.pop();
    cout << elem << " ";
    for (int elemAdj : adjacencyLists[elem]) {
      if (discovered[elemAdj] == false) {
        discovered[elemAdj] = true;
        myqueue.push(elemAdj);
      }
    }
  }
  cout << endl;
}
