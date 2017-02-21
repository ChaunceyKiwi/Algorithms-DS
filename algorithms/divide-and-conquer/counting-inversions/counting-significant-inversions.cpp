#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int merge_and_count(vector <int> &arr, int first1,
                      int last1, int first2, int last2, int sensitivity) {
    int count = 0;
    int curr1 = first1, curr2 = first2;
    vector <int> arr2;
    while (curr1 <= last1 && curr2 <= last2) {
      
      if (arr[curr1] > sensitivity * arr[curr2]) {
        arr2.push_back(arr[curr2++]);
        count += (last1 - curr1 + 1);
      } else if (arr[curr1] > arr[curr2]) {
        arr2.push_back(arr[curr2]);
        curr1++;
      } else {
        arr2.push_back(arr[curr1++]);
      }
    }
    
    while (curr1 <= last1) {
      arr2.push_back(arr[curr1++]);
    }
    while (curr2 <= last2) {
      arr2.push_back(arr[curr2++]);
    }
    
    for (int i = first1, j = 0; i <= last2; i++, j++) {
      arr[i] = arr2[j];
    }
    
    return count;
  }
  
  int sort_and_count(vector <int> &arr, int start, int end, int sensitivity) {
    if (end == start) {
      return 0;
    } else {
      int count1 = sort_and_count(arr, start, (start + end) / 2, sensitivity);
      int count2 = sort_and_count(arr, (start + end) / 2 + 1, end, sensitivity);
      int count3 = merge_and_count(arr, start,
                                   (start + end) / 2, (start + end) / 2 + 1, end, sensitivity);
      return count1 + count2 + count3;
    }
  }
  
  int counting_significant_inversions(vector <int> &arr, int sensitivity) {
    return sort_and_count(arr, 0, (int)arr.size() - 1, sensitivity);
  }
};

int main(void)
{
  Solution sol;
  int myints[] = {2,4,1,3,5};
  vector<int> vec (myints, myints + sizeof(myints) / sizeof(int));
  cout << sol.counting_significant_inversions(vec, 3) << endl;
}
