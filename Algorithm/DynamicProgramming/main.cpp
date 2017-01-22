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
  int table[n+1][limit+1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < limit + 1; j++) {
      table[i][j] = 0;
    }
  }

  // Build table
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < limit + 1; j++) {
      if (j - weight[i-1] < 0) {
        table[i][j] = table[i-1][j];
      } else {
        int caseA = table[i-1][j];
        int caseB = table[i-1][j-weight[i-1]] + value[i-1];
        table[i][j] = max(caseA, caseB);
      }
    }
  }

  return table[n][limit];
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
