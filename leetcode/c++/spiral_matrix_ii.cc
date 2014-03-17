/* Copyright 2013 <ZhiQiang Fan>

   Given an integer n, generate a square matrix filled with elements
   from 1 to n2 in spiral order.

   For example,
   Given n = 3,

   You should return the following matrix:
   [
   [ 1, 2, 3 ],
   [ 8, 9, 4 ],
   [ 7, 6, 5 ]
   ]
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  vector<vector<int> > generateMatrix(int n) {
    // initial direction is right
    int direction = 0;
    // direction action, for i.e. right is [row][col++]
    int direction_action[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // read limit number of element on this direction
    int direction_count_lim[4] = {0};
    int direction_count_cur = 0;
    // current accessed elements
    int count = 0;
    // the total count of matrix
    int target_count;
    int i = 0, j = 0;
    vector<vector<int> > result(n, vector<int>(n, 0));

    if (n < 1)
      return result;

    target_count = n * n;
    direction_count_lim[0] = n;
    direction_count_lim[1] = n - 1;
    direction_count_lim[2] = n - 1;
    direction_count_lim[3] = n - 2;
    while (count < target_count) {
      result[i][j] = ++count;
      direction_count_cur++;
      if (direction_count_cur == direction_count_lim[direction]) {
        direction_count_lim[direction] -= 2;
        direction = (direction + 1) % 4;
        direction_count_cur = 0;
      }
      i += direction_action[direction][0];
      j += direction_action[direction][1];
    }

    return result;
  }
};

int main() {
  Solution s;
  int n;
  scanf("%d", &n);
  vector<vector<int> > r = s.generateMatrix(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }
  return 0;
}
