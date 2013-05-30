/* Given a sorted array of integers, find the starting and ending
   position of a given target value.

   Your algorithm's runtime complexity must be in the order of
   O(logn).

   If the target is not found in the array, return [-1, -1].

   For example,
   Given [5, 7, 7, 8, 8, 10] and target value 8,
   return [3, 4]. */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(int A[], int n, int target) {
    vector<int> r(2, -1); //result
    int left, right, mid;

    // find the first one
    left = 0;
    right = n - 1;
    while (left <= right) {
      mid = (left + right) / 2;
      if (A[mid] < target)
        left = mid + 1;
      else if (A[mid] > target)
        right = mid - 1;
      else if (left == right) { // && A[mid] == target, bingo
        r[0] = left;
        break;
      }
      else
        right = mid; // try to find in left
    }
    // find the last one
    left = 0;
    right = n - 1;
    while (left <= right) {
      mid = (left + right + 1) / 2; // let mid close to right
      if (A[mid] < target)
        left = mid + 1;
      else if (A[mid] > target)
        right = mid - 1;
      else if (left == right) { // && A[mid] == target, bingo
        r[1] = left;
        break;
      }
      else
        left = mid; // try to find in right
    }
    return r;
  }
};

int main() {
  int a[] = {5,7,7,8,8,10};
  Solution sol;
  vector<int> r = sol.searchRange(a, sizeof(a)/sizeof(int), 1);
  cout << r[0] << " " << r[1] << endl;
  return 0;
}
