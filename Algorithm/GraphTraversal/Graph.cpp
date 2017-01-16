//
//  Graph.cpp
//  temp
//
//  Created by Chauncey on 2017-01-15.
//  Copyright © 2017 Chauncey. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(int verticesCount) {
  this->verticesCount = verticesCount;
  this->adjacencyLists = new list<int>[verticesCount];
}

void Graph::addEdge(int index1, int index2) {
  this->adjacencyLists[index1].push_back(index2);
}

void Graph::BFS(int index1) {
  // set Discov[s] := true and Discov[v] := false for v≠s
  bool discovered[this->verticesCount];
  for (int i = 0; i < this->verticesCount; i++) {
    discovered[i] = false;
  }
  discovered[index1] = true;

  // BFS Tranversal
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

void Graph::DFS(int index1) {
  // set Discov[s] := true and Discov[v] := false for v≠s
  bool discovered[this->verticesCount];
  for (int i = 0; i < this->verticesCount; i++) {
    discovered[i] = false;
  }
  discovered[index1] = true;

  // DFS Tranversal
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
