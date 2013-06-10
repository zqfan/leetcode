/* Copyright 2013 <ZhiQiang Fan>

   Write an efficient algorithm that searches for a value in an m x n
   matrix. This matrix has the following properties:

   Integers in each row are sorted from left to right.
   The first integer of each row is greater than the last integer of
   the previous row.
   For example,

   Consider the following matrix:

   [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
   ]
   Given target = 3, return true.

   This problem is used by Baidu Inc.
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    // use binary search
    int start, end, mid, row;

    // locate the row
    // find the max number less or equal than target
    start = 0, end = matrix.size() - 1;
    while (start <= end) {
      // + 1 to avoid infinite loop
      mid = (start + end + 1) / 2;
      if (start == end)
        break;
      if (matrix[mid][0] == target)
        return true;
      else if (matrix[mid][0] < target)
        start = mid;
      else
        end = mid - 1;
    }

    // find the col
    row = start;
    start = 0, end = matrix[row].size() - 1;
    while (start <= end) {
      mid = (start + end) / 2;
      if (matrix[row][mid] == target)
        return true;
      else if (matrix[row][mid] < target)
        start = mid + 1;
      else
        end = mid - 1;
    }
  }
};

int main() {
  int a[][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  vector<vector<int> > matrix;
  int i;
  for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    matrix.push_back(vector<int>(a[i], a[i]+sizeof(a[0])/sizeof(int)));
  Solution s;
  printf("%d\n", s.searchMatrix(matrix, 35));
  return 0;
}
