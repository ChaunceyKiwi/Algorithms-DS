#include <iostream>
using namespace std;

/* Quick-find algorithm may take about MN steps
 * to process M untion commands on N objects */

class QuickFind {
 private:
  vector<int> id;

 public:
  QuickFind(int N) {
    id = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
      id[i] = i;
    }
  }

  bool find(int p, int q) { return id[p] == id[q]; }

  void unite(int p, int q) {
    int pid = id[p];
    for (int i = 0; i < (int)id.size(); i++) {
      if (id[i] == pid) {
        id[i] = id[q];
      }
    }
  }
}