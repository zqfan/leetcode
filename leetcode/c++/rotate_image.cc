/* Copyright 2013 <Zhiqiang Fan>

   You are given an n x n 2D matrix representing an image.

   Rotate the image by 90 degrees (clockwise).

   Follow up:
   Could you do this in-place?
*/
// yet another question of ctci, actually, n*90 is not harder
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  void rotate(vector<vector<int> > &matrix) {
    int i, j, n, tmp;

    n = matrix.size();
    // just part of elements need to be accessed
    // the others will be accessed in the loop
    for (i = 0; i < n; i++) {
      for (j = i; j < n - i - 1; j++) {
        tmp = matrix[i][j];
        matrix[i][j] = matrix[n-1-j][i];
        matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        matrix[j][n-1-i] = tmp;
      }
    }
  }
};

int main() {
  int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8},
                {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int> > m;
  int i, j;
  for (i = 0; i < sizeof(a[0])/sizeof(int); i++)
    m.push_back(vector<int>(a[i], a[i]+sizeof(a[i])/sizeof(int)));
  for (i = 0; i < sizeof(a[0])/sizeof(int); i++) {
    for (j = 0; j < sizeof(a[0])/sizeof(int); j++)
      printf("%d ", m[i][j]);
    printf("\n");
  }
  Solution s;
  s.rotate(m);
  for (i = 0; i < sizeof(a[0])/sizeof(int); i++) {
    for (j = 0; j < sizeof(a[0])/sizeof(int); j++)
      printf("%d ", m[i][j]);
    printf("\n");
  }
  return 0;
}
