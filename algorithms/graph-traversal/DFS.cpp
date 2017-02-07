#include "Graph.hpp"

// DFS Tranversal, stack based, with time complexity as O(|V|+|E|)
void Graph::DFS(int index1) {
  // set Discov[s] := true and Discov[v] := false for v≠s
  // Time complexity: O(|V|)
  bool discovered[this->verticesCount];
  for (int i = 0; i < this->verticesCount; i++) {
    discovered[i] = false;
  }
  discovered[index1] = true;
  
  // Undiscovered vertices are enqueued, marked as discovered, and dequeued
  // Each vertex is enqueued/dequeued at most once, thus time complexity: O(|E|)
  stack<int> mystack;
  mystack.push(index1);
  while(!mystack.empty()) {
    int elem = mystack.top();
    mystack.pop();
    cout << elem << " ";
    for (int elemAdj : adjacencyLists[elem]) {
      if (discovered[elemAdj] == false) {
        discovered[elemAdj] = true;
        mystack.push(elemAdj);
      }
    }
  }
  cout << endl;
}
