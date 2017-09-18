/* 
 * Sorting algorithm with Data structure Array
 * Worst case performance O(n^2)
 * Best case performance  O(n)
 * Average case performance O(n^2)
 * Worst case space complexity  O(1) auxiliary
 */

/* In each iteration the maxmium will be put at the rear of array */
/* Some number will bubble up until meet a larger number */

#include <iostream>
#include <vector>

void bubbleSort(vector<int> &nums) {
  int len = (int)nums.size();
  
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (nums[j] > nums[j+1]) {
        swap(nums[j], nums[j+1]);
      }
    }
  }
}
