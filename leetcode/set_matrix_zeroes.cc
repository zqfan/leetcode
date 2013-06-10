/* Copyright 2013 <ZhiQiang Fan>

   Given a m x n matrix, if an element is 0, set its entire row and
   column to 0. Do it in place.
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
 public:
  void setZeroes(vector<vector<int> > &matrix) {
    bool clear_prev = false;
    bool clear_cur = false;
    int i, j, k;

    for (i = 0; i < matrix.size(); i++) {
      clear_cur = false;
      for (j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          // this row should be clear
          clear_cur = true;
          // this column should be clear, but i just clear above
          // leave the rest job to do later
          for (k = 0; k < i; k++)
            matrix[k][j] = 0;
        }
        // finish the undone job
        if (i >= 1 && matrix[i-1][j] == 0)
          matrix[i][j] = 0;
      }
      // if prev row should be cleard
      if (clear_prev) {
        for (k = 0; k < matrix[i-1].size(); k++)
          matrix[i-1][k] = 0;
      }
      clear_prev = clear_cur;
    }
    // handle last row
    if (clear_cur) {
      for (k = 0; k < matrix[i-1].size(); k++)
        matrix[i-1][k] = 0;
    }
  }
};

int main() {
  int a[][1] = {{0}, {1}};
  vector<vector<int> > matrix;
  Solution s;
  int i, j;
  for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    matrix.push_back(vector<int>(a[i],
                                 a[i] + sizeof(a[0])/sizeof(int)));
  for (i = 0; i < matrix.size(); i++) {
    for (j = 0; j < matrix[i].size(); j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  s.setZeroes(matrix);
  for (i = 0; i < matrix.size(); i++) {
    for (j = 0; j < matrix[i].size(); j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
