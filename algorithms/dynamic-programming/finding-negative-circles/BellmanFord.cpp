#include "Graph.hpp"

// Dynamic programming
// Version with time complexity as O(|V|*|E|)
// Space complexity is O(n^2)
bool Graph::existShortestGraph() {
  int n = this->verticesCount;
  // opt[i][v] denote the minimum weight of a path from v to t
  // using at most i arcs
  int opt[n+1][n];
  int predecessor[n];
  
  // all vertices cannot reach to the target with 0 arcs except for target itself
  for (int i = 0; i < n; i++) {
    opt[0][i] = INT_MAX;
    predecessor[i] = -1;
  }
  opt[0][n-1] = 0;
  
  for (int i = 1; i < n+1; i++) {
    for (int v = 0; v < n; v++) {
      int minimum = opt[i-1][v];
      int index = predecessor[v];
      
      for (pair<int, float> cost : this->adjacencyLists[v]) {
        int distance = opt[i-1][cost.first];
        if (distance != INT_MAX) {
          distance = opt[i-1][cost.first] + cost.second;
        }
        
        if (minimum > distance) {
          minimum = distance;
          index = cost.first;
        }
      }
      opt[i][v] = minimum;
      predecessor[v] = index;
    }
  }
  
//  // Code for checking the result 
//  cout << "Matrix: " << endl;
//  for (int i = 0; i < n+1; i++) {
//    for (int v = 0; v < n; v++) {
//      cout << min(opt[i][v], 99) << " ";
//    }
//    cout << endl;
//  }
  
  for (int i = 0; i < n; i++) {
    if (opt[n][i] != opt[n-1][i])
      return true;
  }
  return false;
}
