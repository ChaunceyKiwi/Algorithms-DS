#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
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
  float predecessor[m+1][n+1]; // -1: unknown, 0:diag, 1:left, 2:down
  
  for(int i = 0; i <= m; i++) {
    opt[i][0] = i * gapPenalty;
    if (i != 0) {
      predecessor[i][0] = 2;
    }
  }
  for(int j = 0; j <= n; j++) {
    opt[0][j] = j * gapPenalty;
    if (j != 0) {
      predecessor[0][j] = 1;
    }
  }
  
  predecessor[0][0] = -1;
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      predecessor[i][j] = -1;
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int case1 = opt[i-1][j-1] + getMismatchPenalty(x[i-1],y[j-1]);
      int case2 = opt[i-1][j] + gapPenalty;
      int case3 = opt[i][j-1] + gapPenalty;
      opt[i][j] = min(min(case1, case2), case3);
      if (case1 == opt[i][j]) {
        predecessor[i][j] = 0;
      } else if (case2 == opt[i][j]) {
        predecessor[i][j] = 2;
      } else {
        predecessor[i][j] = 1;
      }
    }
  }
  
  stack<int> operation;
  int x_ = m;
  int y_ = n;
  int i = predecessor[x_][y_];
  while(i != - 1) {
    operation.push(i);
    if (i == 0) {
      x_--;
      y_--;
    } else if (i == 1) {
      y_--;
    } else {
      x_--;
    }
    i = predecessor[x_][y_];
  }
  
  int index_x = 0;
  int index_y = 0;
  string str1 = "";
  string str2 = "";
  while(operation.size() > 0) {
    if (operation.top() == 0) {
      str1 += x[index_x++];
      str2 += y[index_y++];
    } else if (operation.top() == 1) {
      str1 += "-";
      str2 += y[index_y++];
    } else {
      str1 += x[index_x++];
      str2 += "-";
    }
    operation.pop();
  }
  
  cout << str1 << endl;
  cout << str2 << endl;

  return opt[m-1][n-1];
}

int main(void)
{
  string x = "abbbaabbbbaab";
  string y = "ababaaabbbbbab";
  cout << calculateOptimal(x, y) << endl;
}
