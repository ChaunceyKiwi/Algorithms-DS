#include <iostream>
using namespace std;
void countingSort(int* a,int k,int length);

int main(void)
{
  int a[8] = {4,7,1,11,3,8,2,6};
  int i;
  int b[8];

  for(i = 0;i < 8;i++)
    cout<<a[i]<<" ";
  cout<<endl;

  countingSort(a,12,8);

  for(i = 0;i < 8;i++)
    cout<<a[i]<<" ";
  cout<<endl;

}

// k is the range of number ,length is the length of array
void countingSort(int* a,int k,int length){
  int i;
  int c[k],b[length];
  for(i = 0;i < k;i++)
    c[i] = 0;
  for(i = 0;i < length;i++)
    c[a[i]] += 1;

  for(i = 1;i < k;i++)
    c[i] += c[i-1];

  for(i = length - 1;i > -1;i--){
    b[c[a[i]]-1] = a[i];
    c[a[i]]--;
  }

  for(i = 0;i< length;i++){
    a[i] = b[i];
  }
}
