/* Copyright 2013 <ZhiQiang Fan>

   Follow up for "Unique Paths":

   Now consider if some obstacles are added to the grids. How many
   unique paths would there be?

   An obstacle and empty space is marked as 1 and 0 respectively in
   the grid.

   For example,

   There is one obstacle in the middle of a 3x3 grid as illustrated
   below.

   [
   [0,0,0],
   [0,1,0],
   [0,0,0]
   ]
   The total number of unique paths is 2.

   Note: m and n will be at most 100.
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    // is this another problem of ctci?
    int ** grid = NULL;
    int result = 0;
    int i, j, m, n;

    if (obstacleGrid.size() < 1 || obstacleGrid[0].size() < 1)
      return 0;

    m = obstacleGrid.size();
    n = obstacleGrid[0].size();
    grid = new int *[m];
    for (i = 0; i < m; i++)
      grid[i] = new int[n];

    grid[0][0] = 1 - obstacleGrid[0][0];
    for (i = 1; i < m; i++)
      grid[i][0] = obstacleGrid[i][0] ? 0 : grid[i-1][0];
    for (j = 1; j < n; j++)
      grid[0][j] = obstacleGrid[0][j] ? 0 : grid[0][j-1];

    for (i = 1; i < m; i++) {
      for (j = 1; j < n; j++) {
        if (obstacleGrid[i][j])
          grid[i][j] = 0;
        else
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
  int a[][2] = {{1, 0}, {0, 0}};
  vector<vector<int> >obstacleGrid;
  for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
    int len = sizeof(a[i])/sizeof(int);
    obstacleGrid.push_back(vector<int>(a[i], a[i] + len));
  }
  Solution s;
  printf("%d\n", s.uniquePathsWithObstacles(obstacleGrid));
  return 0;
}
