// Class Sorting algorithm
// Running time depends on whether the partitioning is balanced or unbalanced.
// Worst case performance  O(n^2)
// Best case performance O(n * log n) (simple partition)
// or O(n) (three-way partition and equal keys)
// Average case performance    O(n log n)
// Worst case space complexity O(n) auxiliary (naive)
// O(log n) auxiliary (Sedgewick 1978)
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int* arr,int left,int right){
    int pivot;
    int wall = left; //wall is on the left of current index
    int current = left;

    if (left >= right)
        return;
    else if (left == right - 1){
        if(arr[left] > arr[right])
        {
            swap(&arr[left],&arr[right]);
        }
        return;
    }

    pivot = right;
    while(current < right){
        if(arr[pivot] > arr[current]){
            swap(&arr[current],&arr[wall]);
            wall++;
        }
        current++;
    }
    swap(&arr[wall],&arr[pivot]);
    quickSort(arr, left, wall - 1);
    quickSort(arr, wall + 1, right);
}
