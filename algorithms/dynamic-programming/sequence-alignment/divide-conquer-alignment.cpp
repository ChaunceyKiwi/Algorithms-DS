#include <iostream>
#include <string>
#include <algorithm>
#include <cfloat>
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
  return opt[m-1][n-1];
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

float calculateOptimal_backward(string x, string y) {
  int m = (int)x.length();
  int n = (int)y.length();
  
  // Initialization
  float opt[m+1][n+1];
  for(int i = 0; i <= m; i++) {
    opt[i][n] = (m - i) * gapPenalty;
  }
  for(int j = 0; j <= n; j++) {
    opt[m][j] = (n - j) * gapPenalty;
  }
  
  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      int case1 = opt[i+1][j+1] + getMismatchPenalty(x[i],y[j]);
      int case2 = opt[i+1][j] + gapPenalty;
      int case3 = opt[i][j+1] + gapPenalty;
      opt[i][j] = min(min(case1, case2), case3);
    }
  }
  return opt[m][n];
}

float divide_conquer_alignment(string x, string y, int startX, int startY) {
  int m = (int)x.length();
  int n = (int)y.length();
  
  if (m <= 2 || n <= 2) {
    return calculateOptimal(x, y);
  }
  
  float opt = FLT_MAX;
  int q = 1;
  for (int i = 0; i < m; i++) {
    float a = calculateOptimal2(x.substr(0, i), y.substr(0, n/2));
    float b = calculateOptimal_backward(x.substr(i, m-i), y.substr(n/2, n/2));
    
    if (a + b < opt) {
      opt = a + b;
      q = i;
    }
  }
  
  cout << "(" << q + startX<< "," << n/2 + startY<< ")" << endl;
  
  divide_conquer_alignment(x.substr(0, q), y.substr(0, n/2), 0, 0);
  divide_conquer_alignment(x.substr(q, m-q), y.substr(n/2, n/2), q, n/2);
  return 0;
}

int main(void)
{
  string x = "abbbaabbbbaab";
  string y = "ababaaabbbbbab";
  divide_conquer_alignment(x, y, 0, 0);
}
