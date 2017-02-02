#include <iostream>
using namespace std;

// Recursive version
int knapSack(int limit, int *weight, int *value, int n)
{
  // If there is no item or limit is 0
  if (n == 0 || limit == 0) {
    return 0;
  }

  // If the last item is not heavy to carry
  if (weight[n-1] > limit) {
    return knapSack(limit, weight, value, n - 1);
  }

  else {
    // If carry last item
    int caseA = value[n - 1] +
      knapSack(limit-weight[n - 1], weight, value, n - 1);

    // If not carry last item
    int caseB = knapSack(limit, weight, value, n - 1);

    return max(caseA, caseB);
  }
}

// Non-recursive version
int knapSack2(int limit, int *weight, int *value, int n)
{
  // Initilization
  int opt[n+1][limit+1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < limit + 1; j++) {
      opt[i][j] = 0;
    }
  }

  // Build opt table
  // opt(i, j) denote the maximial value of a selection of objects out of
  // {1, ... i} such that the toal weight of the selection does not exceed j
  // opt(n, W) = max{opt(n-1, W), opt(n-1, W-Wn) + Vn}
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < limit + 1; j++) {
      if (j - weight[i-1] < 0) {
        opt[i][j] = opt[i-1][j];
      } else {
        int caseA = opt[i-1][j];
        int caseB = opt[i-1][j-weight[i-1]] + value[i-1];
        opt[i][j] = max(caseA, caseB);
      }
    }
  }

  return opt[n][limit];
}

int main()
{
  int value[4] = {60, 100, 120, 200};
  int weight[4] = {10, 20, 30, 5};
  int limit = 50;
  int n = sizeof(value)/sizeof(value[0]);
  cout << knapSack(limit, weight, value, n) << endl;;
  cout << knapSack2(limit, weight, value, n) << endl;
  return 0;
}
