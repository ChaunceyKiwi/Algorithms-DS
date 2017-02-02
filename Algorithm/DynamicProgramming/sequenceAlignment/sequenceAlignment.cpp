#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Global variable
float mismatchPenalty = 1;
float gapPenalty = 1;

float getMismatchPenalty(char x, char y) {
  return x == y ? 0 : mismatchPenalty;
}

float calculateOptimal(string x, string y) {
  int m = x.length();
  int n = y.length();

  // Initialization
  float opt[m][n];
  for(int i = 0; i < m; i++) {
    opt[i][0] = i * gapPenalty;
  }
  for(int j = 0; j < n; j++) {
    opt[0][j] = j * gapPenalty;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      int case1 = opt[i-1][j-1] + getMismatchPenalty(x[i-1],y[j-1]);
      int case2 = opt[i-1][j] + gapPenalty;
      int case3 = opt[i][j-1] + gapPenalty;
      opt[i][j] = min(min(case1, case2), case3);
    }
  }
  return opt[m-1][n-1];
}

int main(void)
{
  string x = "ocurrance";
  string y = "occurrence";
  cout << calculateOptimal(x, y) << endl;
}
