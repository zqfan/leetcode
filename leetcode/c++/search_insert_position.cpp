/* Given a sorted array and a target value, return the index if the
   target is found. If not, return the index where it would be if it
   were inserted in order.

   You may assume no duplicates in the array.

   Here are few examples.
   [1,3,5,6], 5 → 2
   [1,3,5,6], 2 → 1
   [1,3,5,6], 7 → 4
   [1,3,5,6], 0 → 0 */
#include <iostream>
using namespace std;

class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    int left, right, mid;

    if (n <= 0 ) // invalid input leading to invalid result
      return -1;

    if (target <= A[0]) // handle this exception, see following code
      return 0;

    // always find the max lower number
    // for i.e. [1,3,5,6], 5 -> will find 3, and return his index+1
    left = 0;
    right = n - 1;
    while (left <= right) {
      // always favorite right, or it may be infinite loop
      mid = (left + right + 1) / 2;
      // break condition
      if (left == right) // find the one
        return mid + 1;
      if (A[mid] >= target) // target must insert to left
        right = mid - 1;
      else // target must insert to right, note mid must include
        left = mid;
    }
  }
};

int main() {
  int a[] = {1,3,5,6};
  Solution sol;
  cout << sol.searchInsert(a, sizeof(a)/sizeof(int), 0) << endl;
  return 0;
}
