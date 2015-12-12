//Time complexity O(n)
//Fast because using certain assumptions about the input values

#include <iostream>
using namespace std;
void countingSort(int* a,int k,int length);
void radixsort(int arr[], int n);

int main(void)
{
  int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int i;

  int n = sizeof(arr)/sizeof(arr[0]);

  for(i = 0;i < n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  radixsort(arr, n);

  for(i = 0;i < n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;

}

// k is the range of number ,length is the length of array
void countingSort(int* a,int exp,int length){
  int i;
  int c[10],b[length];
  for(i = 0;i < 10;i++)
    c[i] = 0;
  for(i = 0;i < length;i++)
    c[(a[i]/exp)%10] += 1;

  for(i = 1;i < 10;i++)
    c[i] += c[i-1];

  for(i = length - 1;i > -1;i--){
    b[c[(a[i]/exp)%10]-1] = a[i];
    c[(a[i]/exp)%10]--;
  }

  for(i = 0;i< length;i++){
    a[i] = b[i];
  }
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
    countingSort(arr,exp,n);
}
