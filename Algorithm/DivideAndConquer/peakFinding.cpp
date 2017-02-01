#include <iostream>
using namespace std;

int peak1d(int* array, int i ,int j) {
  int m = (i + j) / 2;
  if (array[m] >= array[m-1] && array[m] >= array[m+1]) {
    return m;
  } else if (array[m] < array[m-1]) {
    return peak1d(array, i, m - 1);
  } else {
    return peak1d(array, m + 1, j);
  }
}

int main(void)
{
  int array[7] = {1, 2, 0, 5, 6, 7, 4};
  cout << peak1d(array, 0, 7) << endl;
}
