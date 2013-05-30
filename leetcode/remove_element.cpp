/* Given an array and a value, remove all instances of that value in
   place and return the new length.
   The order of elements can be changed. It doesn't matter what you
   leave beyond the new length. */
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
      int i, j;
      sort(A, A + n);
      for (i = 0; i < n && A[i] != elem; i++);
      for (j = i + 1; j < n && A[j] == elem; j++);
      for (; j < n; i++, j++)
        A[i] = A[j];
      return i;
    }
};

int main() {
  int a[] = {1,2,3,4,5,6,7,8,9};
  Solution sol;
  int n = sol.removeElement(a, 9, 2);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
