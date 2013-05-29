/*  Given a sorted array, remove the duplicates in place such that
    each element appear only once and return the new length.

    Do not allocate extra space for another array, you must do this in
    place with constant memory.

    For example,
    Given input array A = [1,1,2],

    Your function should return length = 2, and A is now [1,2]. */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int i, j, k;

    if (n <= 1)
      return n;
    for (i = 1, j = 0; i < n; i++) {
      if (A[i] != A[j])
        A[++j] = A[i];
    }
    return j + 1;
  }
};

int main() {
  int a[] = {1,1,2,3,4,4,5,6,6,7};
  Solution sol;
  int n = sol.removeDuplicates(a, sizeof(a)/sizeof(int));
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
