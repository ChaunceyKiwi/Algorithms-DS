#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Global variable
float mismatchPenalty = 100;
float gapPenalty = 1;

float getMismatchPenalty(char x, char y) {
  return x == y ? 0 : mismatchPenalty;
}

// Time complexity: O(m*n)
// Space complexity: O(m*n)
float calculateOptimal(string x, string y) {
  int m = (int)x.length();
  int n = (int)y.length();

  // Initialization
  float opt[m+1][n+1];
  for(int i = 0; i <= m; i++) {
    opt[i][0] = i * gapPenalty;
  }
  for(int j = 0; j <= n; j++) {
    opt[0][j] = j * gapPenalty;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int case1 = opt[i-1][j-1] + getMismatchPenalty(x[i-1],y[j-1]);
      int case2 = opt[i-1][j] + gapPenalty;
      int case3 = opt[i][j-1] + gapPenalty;
      opt[i][j] = min(min(case1, case2), case3);
    }
  }
  return opt[m][n];
}

// Time complexity: O(m*n)
// Space complexity: O(m*2)
float calculateOptimal2(string x, string y) {
  int m = (int)x.length();
  int n = (int)y.length();

  // Initialization
  float opt[m+1][2];
  for(int i = 0; i <= m; i++) {
    opt[i][0] = i * gapPenalty;
  }

  for (int j = 1; j <= n; j++) {
    opt[0][1] = j * gapPenalty;
    for (int i = 1; i <= m; i++) {
      int case1 = opt[i-1][0] + getMismatchPenalty(x[i-1],y[j-1]);
      int case2 = opt[i-1][1] + gapPenalty;
      int case3 = opt[i][0] + gapPenalty;
      opt[i][1] = min(min(case1, case2), case3);
    }
    for(int i = 0; i <= m; i++) {
      opt[i][0] = opt[i][1];
    }
  }

  return opt[m][0];
}

int main(void)
{
  string x = "ocurrance";
  string y = "occurrence";
  cout << calculateOptimal(x, y) << endl;
  cout << calculateOptimal2(x, y) << endl;
}
