#include "Graph.hpp"

int Graph::countShortestPathFromTo(int indexFrom, int indexTo) {
  
  // Initialization
  int count[verticesCount];
  int level[verticesCount];
  bool discovered[verticesCount];
  for (int i = 0; i < verticesCount; i++) {
    level[i] = 0;
    count[i] = 0;
    discovered[i] = false;
  }
  count[indexFrom] = 1;
  discovered[indexFrom] = true;
  
  queue<int> myqueue;
  myqueue.push(indexFrom);
  
  while(!myqueue.empty()) {
    int elem = myqueue.front();
    myqueue.pop();
    int currLevel = level[elem];
    
    for (int elemAdj : adjacencyLists[elem]) {
      if (discovered[elemAdj] == false) {
        discovered[elemAdj] = true;
        myqueue.push(elemAdj);
        level[elemAdj] = currLevel + 1;
      }
      if (level[elemAdj] == level[elem] + 1) {
        count[elemAdj] += count[elem];
      }
    }
  }
  return count[indexTo];
}
