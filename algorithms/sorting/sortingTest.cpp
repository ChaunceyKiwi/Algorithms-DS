#include <iostream>
#include "quickSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"

using namespace std;

int main(void)
{
    int a[8] = {4,7,1,11,3,8,2,6};
    int i;
    
    for(i = 0;i < 8;i++)
        cout<<a[i]<<" ";
    
    cout<<endl;
    
    //quicksort(a, 8);
    //insertionSort(a, 8);
    //bubbleSort(a, 8);
    //merge(a,0,7);
    
    for(i = 0;i < 8;i++)
        cout<<a[i]<<" ";
}
