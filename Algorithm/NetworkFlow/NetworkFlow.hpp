#include <stdio.h>
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class NetworkFlow {
private:
  int verticesCount;
  int source, sink;
  vector<vector<int>> adjacencyMatrix;
  vector<int> flow;
  int bottleneckOfFlow;
public:
  NetworkFlow(int verticesCount, int source, int sink);
  NetworkFlow (const NetworkFlow& other);
  void addEdge(int index1, int index2, int cost);

  int getVerticesCount() {return verticesCount;}
  
  int fordFulkerson();
  bool updateFlow();
  void updateBottleneckOfFlow();
  void argumentFlow();
};
