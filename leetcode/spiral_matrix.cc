/* Copyright 2013 <ZhiQiang Fan>

   Given a matrix of m x n elements (m rows, n columns), return all
   elements of the matrix in spiral order.

   For example,
   Given the following matrix:

   [
   [ 1, 2, 3 ],
   [ 4, 5, 6 ],
   [ 7, 8, 9 ]
   ]

   You should return [1,2,3,6,9,8,7,4,5].
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
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
    vector<int> result;

    if (matrix.size() < 1 || matrix[0].size() < 1)
      return result;

    target_count = matrix.size() * matrix[0].size();
    direction_count_lim[0] = matrix[0].size();
    direction_count_lim[1] = matrix.size() - 1;
    direction_count_lim[2] = matrix[0].size() - 1;
    direction_count_lim[3] = matrix.size() - 2;
    while (count < target_count) {
      result.push_back(matrix[i][j]);
      count++;
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
  int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int> > m;
  int i;
  for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    m.push_back(vector<int>(a[i], a[i] + sizeof(a[i])/sizeof(int)));
  Solution s;
  vector<int> r = s.spiralOrder(m);
  for (i = 0; i < r.size(); i++)
    printf("%d ", r[i]);
  printf("\n");
  return 0;
}
