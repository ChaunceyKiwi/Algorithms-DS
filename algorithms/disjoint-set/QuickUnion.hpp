#include <iostream>
using namespace std;

class NormalUnion {
 private:
  vector<int> id;

 public:
  NormalUnion(int N) {
    id = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
      id[i] = i;
    }
  }

  int root(int i) {
    while (i != id[i]) {
      i = id[i];
    }
    return i;
  }

  bool find(int, p, int q) { return root(p) == root(q); }

  void unite(int p, int q) {
    int i = root(p);
    int j = root(q);
    id[i] = j;
  }
}

class QuickUnion {
 private:
  vector<int> id;
  vector<int> size;

 public:
  QuickUnion(int N) {
    id = vector<int>(N, 0);
    size = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
      id[i] = i;
      size[i] = 1;
    }
  }

  int root(int i) {
    while (i != id[i]) {
      id[i] = id[id[i]];  // optimization
      i = id[i];
    }
    return i;
  }

  bool find(int, p, int q) { return root(p) == root(q); }

  void unite(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (size[i] < size[j]) {
      id[i] = j;
      size[j] += size[i];
    } else {
      id[j] = i;
      size[i] += size[j];
    }
  }
}