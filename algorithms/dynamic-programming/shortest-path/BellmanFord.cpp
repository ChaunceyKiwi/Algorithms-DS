#include "Graph.hpp"

// Dynamic programming
// Version with time complexity as O(|V|*|E|)
// Space complexity is O(n^2)
void Graph::calculate_shortest_path_from_to(int source, int target) {
  int n = this->verticesCount;
  // opt[i][v] denote the minimum weight of a path from v to t
  // using at most i arcs
  int opt[n][n];
  int predecessor[n];
  
  // all vertices cannot reach to the target with 0 arcs except for target itself
  for (int i = 0; i < n; i++) {
    opt[0][i] = INT_MAX;
    predecessor[i] = -1;
  }
  opt[0][target] = 0;
  
  for (int i = 1; i < n; i++) {
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
  cout << "Shortest path with length " << opt[n-1][source]<< ": " << endl;
  int i = source;
  while (i != -1) {
    cout << i << " ";
    i = predecessor[i];
  }
  cout << endl;
}

// Dynamic programming
// Version with time complexity as O(|V|*|E|)
// Space complexity is O(n)
void Graph::calculate_shortest_path_from_to2(int source, int target) {
  int n = this->verticesCount;
  // opt[i][v] denote the minimum weight of a path from v to t
  // using at most i arcs
  int opt[n];
  int predecessor[n];
  
  // all vertices cannot reach to the target with 0 arcs except for target itself
  for (int i = 0; i < n; i++) {
    opt[i] = INT_MAX;
    predecessor[i] = -1;
  }
  opt[target] = 0;
  
  for (int i = 1; i < n; i++) {
    for (int v = 0; v < n; v++) {
      int minimum = opt[v];
      int index = predecessor[v];

      for (pair<int, float> cost : this->adjacencyLists[v]) {
        int distance = opt[cost.first];
        if (distance != INT_MAX) {
          distance = opt[cost.first] + cost.second;
        }
        
        if (minimum > distance) {
          minimum = distance;
          index = cost.first;
        }
      }
      
      opt[v] = minimum;
      predecessor[v] = index;
    }
  }
  
  cout << "Shortest path with length " << opt[source] << ": " << endl;
  int i = source;
  while (i != -1) {
    cout << i << " ";
    i = predecessor[i];
  }
  cout << endl;
}
