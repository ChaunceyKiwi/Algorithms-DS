#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Graph {
 private:
  int vertexCount;
  vector<vector<int>> adjacencies;

 public:
  Graph(int vertexCount);
  void addEdge(int idx1, int idx2);
  void DFS(int idx);
  void BFS(int idx);
  int countShortestPath(int idxFrom, int idxTo);
};

Graph::Graph(int vertexCount) {
  this->vertexCount = vertexCount;
  this->adjacencies = vector<vector<int>>(vertexCount, vector<int>());
}

void Graph::addEdge(int idx1, int idx2) {
  this->adjacencies[idx1].push_back(idx2);
  this->adjacencies[idx2].push_back(idx1);
}

// DFS Tranversal, stack based, with time complexity as O(|V|+|E|)
void Graph::DFS(int idx) {
  stack<int> s;
  s.push(idx);

  // set Discov[s] := true and Discov[v] := false for v≠s
  // Time complexity: O(|V|)
  vector<bool> discovered = vector<bool>(this->vertexCount, false);
  discovered[idx] = true;

  // Undiscovered vertices are enqueued, marked as discovered, and dequeued
  // Each vertex is enqueued/dequeued at most once, thus time complexity: O(|E|)
  while (!s.empty()) {
    int curr = s.top();
    s.pop();
    cout << curr << " ";
    for (int i = 0; i < (int)this->adjacencies[curr].size(); i++) {
      if (!discovered[this->adjacencies[curr][i]]) {
        s.push(this->adjacencies[curr][i]);
        discovered[this->adjacencies[curr][i]] = true;
      }
    }
  }

  cout << endl;
}

// BFS Tranversal, queue based, with time complexity as O(|V|+|E|)
void Graph::BFS(int idx) {
  queue<int> q;
  q.push(idx);

  // set Discov[s] := true and Discov[v] := false for v≠s
  // Time complexity: O(|V|)
  vector<bool> discovered = vector<bool>(this->vertexCount, false);
  discovered[idx] = true;

  // Undiscovered vertices are enqueued, marked as discovered, and dequeued
  // Each vertex is enqueued/dequeued at most once, thus time complexity: O(|E|)
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << " ";
    for (int i = 0; i < (int)this->adjacencies[curr].size(); i++) {
      if (!discovered[this->adjacencies[curr][i]]) {
        q.push(this->adjacencies[curr][i]);
        discovered[this->adjacencies[curr][i]] = true;
      }
    }
  }

  cout << endl;
}

int Graph::countShortestPath(int idxFrom, int idxTo) {
  queue<int> q;
  q.push(idxFrom);

  // set Discov[s] := true and Discov[v] := false for v≠s
  // Time complexity: O(|V|)
  vector<int> count = vector<int>(this->vertexCount, 0);
  vector<int> level = vector<int>(this->vertexCount, 0);
  vector<bool> discovered = vector<bool>(this->vertexCount, false);
  discovered[idxFrom] = true;
  count[idxFrom] = 1;

  // Undiscovered vertices are enqueued, marked as discovered, and dequeued
  // Each vertex is enqueued/dequeued at most once, thus time complexity: O(|E|)
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int i = 0; i < (int)this->adjacencies[curr].size(); i++) {
      int currAdj = this->adjacencies[curr][i];
      if (!discovered[this->adjacencies[curr][i]]) {
        q.push(currAdj);
        discovered[currAdj] = true;
        level[currAdj] = level[curr] + 1;
      }
      if (level[currAdj] == level[curr] + 1) {
        count[currAdj] += count[curr];
      }
    }
  }

  return count[idxTo];
}

/* Test */
int main(int argc, const char* argv[]) {
  Graph g(6);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 5);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);

  cout << "Breath First Tranversal results:" << endl;
  g.DFS(0);
  cout << endl;

  cout << "Depth First Tranversal results:" << endl;
  g.BFS(0);
  cout << endl;

  cout << "Number of shortest path from vertex0 to vertex5 is:" << endl;
  cout << g.countShortestPath(0, 5) << endl;
  cout << endl;

  return 0;
}