// Sorting algorithm with Data structure Array
// Worst case performance О(n2) comparisons, swaps
// Best case performance Ω(n) comparisons, O(1) swaps
// Average case performance	О(n2) comparisons, swaps
// Worst case space complexity О(n) total, O(1) auxiliary


// divide array into two parts:sorted and unsorted.
// Each time add the first element of unsorted array into sorted array.

void insertionSort(vector<int> &nums) {
  int len = (int)nums.size();
  
  for (int i = 1; i < len ; i++) {
    int j = i - 1;
    int temp = nums[i];
    
    while (j >= 0 && nums[j] > temp) {
      nums[j+1] = nums[j];
      j--;
    }
    
    nums[j+1] = temp;
  }
}
