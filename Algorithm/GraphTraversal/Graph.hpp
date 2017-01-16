#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <list>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Graph {
  private:
    int verticesCount;
    list<int> *adjacencyLists;
  public:
    Graph(int verticesCount);
    void addEdge(int index1, int index2);
    void DFS(int index);
    void BFS(int index);
};

#endif /* Graph_hpp */
