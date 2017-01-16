#include "Graph.hpp"

Graph::Graph(int verticesCount) {
  this->verticesCount = verticesCount;
  this->adjacencyLists = new list<pair<int, float>>[verticesCount];
}

void Graph::addEdge(int index1, int index2, float cost) {
  this->adjacencyLists[index1].push_back(make_pair(index2, cost));
  this->adjacencyLists[index2].push_back(make_pair(index1, cost));
}

/*
  Time complexity Analysis of Dijkstra's algorithm:
  Initialization: O(|V|)
  |V| iteration, each iteration check all edges |E|, thus O(|V|*|E|)
  Further improvement(to be done): using heaps and priority to O(|V|*log|E|)
*/
void Graph::calculate_shortest_path_from(int index) {
  // Initialization
  set<int> S;
  S.insert(index);
  int distance[this->verticesCount];
  int predecessor[this->verticesCount];
  for (int i = 0; i < verticesCount; i++) {
    distance[i] = INT_MAX;
    predecessor[i] = -1;
  }
  distance[index] = 0;

  // while S ≠ V
  while(S.size() < verticesCount) {
    pair<int, float> minimumDis = make_pair(-1, INT_MAX);
    int indexOfLastNode = -1;

    // for all pair (u,v) where node u from S and node v not from S
    // find (u', v') in which the distance is minimum
    for (int index1 = 0; index1 < verticesCount; index1++) {
      if (S.count(index1) == 1) {
        for (pair<int, float> cost : this->adjacencyLists[index1]) {
          if (S.count(cost.first) == 0) {
            if (distance[index1] != INT_MAX) {
              if (distance[index1] + cost.second < minimumDis.second) {
                minimumDis.first = cost.first;
                minimumDis.second = distance[index1] + cost.second;
                indexOfLastNode = index1;
              }
            }
          }
        }
      }
    }

    // set S := S ∪ {v}, and d(v) := d'(v)
    if (minimumDis.first != -1) {
      S.insert(minimumDis.first);
      distance[minimumDis.first] = minimumDis.second;
      predecessor[minimumDis.first] = indexOfLastNode;
    }
  }

  // Results
  cout << "Distance from node" << index << " to:" << endl;
  for (int i = 0; i < verticesCount; i++) {
    if (i != index) {
      cout << " node" << i
      << " is " << distance[i] << ", with last node as node"
      << predecessor[i] << "."<< endl;
    }
  }
}
