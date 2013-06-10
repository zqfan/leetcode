/* Copyright 2013 <ZhiQiang Fan>

   Given an array with n objects colored red, white or blue, sort them
   so that objects of the same color are adjacent, with the colors in
   the order red, white and blue.

   Here, we will use the integers 0, 1, and 2 to represent the color,
   white, and blue respectively.

   Note:
   You are not suppose to use the library's sort function for this
   problem.
*/
#include <cstdio>

class Solution {
  public:
  void sortColors(int A[], int n) {
    // try to make the following variable to have the right value
    // if there is no element is 1, then the tree var will be same
    int first_1_pos, last_1_pos;
    int cur;

    if (n < 1)
      return;
    last_1_pos = n - 1;
    // the last element not 2
    while (last_1_pos >= 0 && A[last_1_pos] == 2) {
      last_1_pos--;
    }
    first_1_pos = 0;
    // first_1
    while (first_1_pos <= last_1_pos) {
      if (A[first_1_pos] == 1)
        break;
      else if (A[first_1_pos] == 2) {
        A[first_1_pos] = A[last_1_pos];
        A[last_1_pos] = 2;
        while (last_1_pos >= 0 && A[last_1_pos] == 2) {
          last_1_pos--;
        }
        continue;
      }
      first_1_pos++;
    }
    cur = first_1_pos + 1;
    while (cur <= last_1_pos) {
      if (A[cur] == 0) {
        A[first_1_pos] = 0;
        A[cur] = 1;
        first_1_pos++;
      } else if (A[cur] == 2) {
        A[cur] = A[last_1_pos];
        A[last_1_pos] = 2;
        while (last_1_pos >= 0 && A[last_1_pos] == 2)
          last_1_pos--;
        continue;
      }
      cur++;
    }
  }
};

int main() {
  int a[] = {1, 0, 0};
  Solution s;
  s.sortColors(a, sizeof(a)/sizeof(int));
  for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}
