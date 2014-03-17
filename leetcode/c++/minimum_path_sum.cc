/* Copyright 2013 <ZhiQiang Fan>

   Given a m x n grid filled with non-negative numbers, find a path
   from top left to bottom right which minimizes the sum of all
   numbers along its path.

   Note: You can only move either down or right at any point in time.
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  int minPathSum(vector<vector<int> > &grid) {
    if (grid.size() < 1 || grid[0].size() < 1)
      return 0;

    vector<vector<int> > sum(grid.size(),
                             vector<int>(grid[0].size(), 0));
    int i, j, min;

    sum[0][0] = grid[0][0];
    for (i = 1; i < grid.size(); i++)
      sum[i][0] = sum[i-1][0] + grid[i][0];
    for (j = 1; j < grid[0].size(); j++)
      sum[0][j] = sum[0][j-1] + grid[0][j];
    for (i = 1; i < grid.size(); i++) {
      for (j = 1; j < grid[i].size(); j++) {
        min = sum[i-1][j] < sum[i][j-1] ? sum[i-1][j] : sum[i][j-1];
        sum[i][j] = min + grid[i][j];
      }
    }

    return sum[i-1][j-1];
  }
};

int main() {
  int a[][1] = {{0}};
  vector<vector<int> > grid;
  for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
    int len = sizeof(a[i])/sizeof(int);
    grid.push_back(vector<int>(a[i], a[i] + len));
  }
  Solution s;
  printf("%d\n", s.minPathSum(grid));
  return 0;
}
