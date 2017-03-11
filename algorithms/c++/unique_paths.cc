/* Copyright 2013 <ZhiQiang Fan>

   A robot is located at the top-left corner of a m x n grid (marked
   'Start' in the diagram below).

   The robot can only move either down or right at any point in time.
   The robot is trying to reach the bottom-right corner of the grid
   (marked 'Finish' in the diagram below).

   How many possible unique paths are there?

   Note: m and n will be at most 100.
*/
#include <cstdio>
#include <ctime>

class Solution {
  public:
  int uniquePaths(int m, int n) {
    // is this another problem of ctci?
    // and i think it can be solved in mathematical way
    int ** grid = NULL;
    int result = 0;
    int i, j;

    grid = new int *[m];
    for (i = 0; i < m; i++)
      grid[i] = new int[n];

    for (i = 0; i < m; i++)
      grid[i][0] = 1;
    for (j = 0; j < n; j++)
      grid[0][j] = 1;

    for (i = 1; i < m; i++) {
      for (j = 1; j < n; j++) {
        grid[i][j] = grid[i][j-1] + grid[i-1][j];
      }
    }

    result = grid[m-1][n-1];

    for (i = 0; i < m; i++)
      delete grid[i];
    delete grid;

    return result;
  }
};

int main() {
  Solution s;
  int m, n;
  scanf("%d %d", &m, &n);
  time_t tm;
  tm = time(0);
  printf("%d\n", s.uniquePaths(m, n));
  printf("time=%ds\n", static_cast<int>(time(0) - tm));
  return 0;
}
