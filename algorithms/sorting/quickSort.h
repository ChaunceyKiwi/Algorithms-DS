// Class Sorting algorithm
// Running time depends on whether the partitioning is balanced or unbalanced.
// Worst case performance  O(n^2)
// Best case performance O(n * log n) (simple partition)
// or O(n) (three-way partition and equal keys)
// Average case performance    O(n log n)
// Worst case space complexity O(n) auxiliary (naive)
// O(log n) auxiliary (Sedgewick 1978)
void quickSort(vector<int>& nums, int L, int R) {
  if (L >= R) {
    return;
  }
  
  int pivot = L + rand() % (R - L + 1);
  
  /* put pivot at the end */
  swap(nums[pivot], nums[R]);
  
  int wall = L;
  for (int i = L; i < R; i++) {
    if (nums[i] < nums[R]) {
      swap(nums[i], nums[wall]);
      wall++;
    }
  }
  
  /* put pivot back to correct position */
  swap(nums[wall], nums[R]);
  
  quickSort(nums, L, wall - 1);
  quickSort(nums, wall + 1, R);
}
