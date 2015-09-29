// Sorting algorithm with Data structure Array
// Worst case performance	O(n^2)
// Best case performance	O(n)
// Average case performance	O(n^2)
// Worst case space complexity	O(1) auxiliary

#include <stdio.h>

void bubbleSort(int* arr,int n)
{
    bool swapped = true;
    int j = 0;
    int tmp;
    while(swapped)
    {
        swapped = false;
        j++;
        for(int i = 0;i < n- j;i++)
        {
            if(arr[i] > arr[i+1])
            {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = true;
            }
        }
    }
}