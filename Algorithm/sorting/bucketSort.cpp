#include <iostream>
#include <vector>
using namespace std;
#define maxLength 30
void bucketSort(float* arr,int n);

int main(void)
{
    float a[8] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12};
    int i;

    for(i = 0;i < 8;i++)
        cout<<a[i]<<" ";

    cout<<endl;

    bucketSort(a, 8);

    for(i = 0;i < 8;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}

void bucketSort(float* arr,int n){
  vector <float> b[maxLength];
  int i;
  for(i = 0;i < n;i++){
    int bi = n*arr[i];
    b[bi].push_back(arr[i]);
  }

  for (int i = 0; i < n; i++)
    sort(b[i].begin(), b[i].end());

  int index = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < b[i].size(); j++)
        arr[index++] = b[i][j];
}
