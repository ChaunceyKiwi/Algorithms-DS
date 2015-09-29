// Sorting algorithm with Data structure Array
// Worst case performance О(n2) comparisons, swaps
// Best case performance Ω(n) comparisons, O(1) swaps
// Average case performance	О(n2) comparisons, swaps
// Worst case space complexity О(n) total, O(1) auxiliary

void insertionSort(int* arr,int n)
{
    int i,j,x;
    for(i = 1;i < n ;i++)
    {
        x = arr[i];
        j = i;
        while(j > 0 && arr[j-1] > x)
        {
            arr[j] = arr[j-1];
            j = j-1;
        }
        arr[j] = x;
    }
}
