/* Copyright 2013 <ZhiQiang Fan>

   Given a triangle, find the minimum path sum from top to bottom.
   Each step you may move to adjacent numbers on the row below.

   For example, given the following triangle
   [
   [2],
   [3,4],
   [6,5,7],
   [4,1,8,3]
   ]
   The minimum path sum from top to bottom is 11
   (i.e., 2 + 3 + 5 + 1 = 11).

   Note:
   Bonus point if you are able to do this using only O(n) extra space,
   where n is the total number of rows in the triangle.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
  public:
  int minimumTotal(vector<vector<int> > &triangle) {
    if (triangle.size() < 1)
      return 0;

    vector<int> min(triangle.back().begin(), triangle.back().end());
    int i, j, m, n;
    for (i = triangle.size() - 1; i > 0; i--) {
      for (j = 0; j < i; j++) {
        m = min[j] + triangle[i-1][j];
        n = min[j+1] + triangle[i-1][j];
        min[j] = std::min(m, n);
      }
    }

    return min[0];
  }
};

int main() {
  int a1[] = {2};
  int a2[] = {3, 4};
  int a3[] = {6, 5, 7};
  int a4[] = {4, 1, 8, 3};
  vector<vector<int> > t;
  t.push_back(vector<int>(a1, a1+1));
  t.push_back(vector<int>(a2, a2+2));
  t.push_back(vector<int>(a3, a3+3));
  t.push_back(vector<int>(a4, a4+4));
  printf("%d\n", Solution().minimumTotal(t));
  return 0;
}
