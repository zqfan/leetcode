/*
Copyright (C) 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Given a 2D binary matrix filled with 0's and 1's, find the largest
rectangle containing all ones and return its area.
*/
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
using std::vector;
using std::string;
using std::stack;

class Solution {
  public:
  int largestRectangleArea(vector<int> &height) {
    // NOTE(zqfan): this solution is learn from luckynoob@leetcode
    //
    // If we want to get the largest, we calculate rectangles from
    // the highest to lowest.
    // For height n, it will try it best to expand its left bound and
    // right bound, the left bound is the first position of n, the
    // right bound is last position larger or equal than n.
    // since the can be a lowest position between two higher, we need
    // to calculate in each ascend sequence.
    stack<int> ascend;
    int max = 0;
    int i = 0;
    while (i <= height.size()) {
      // new ascend sequence or ascend element found
      // Please note that to process all elements in this loop, the
      // index is just one out of height bound, so there need to check
      // index bound to prevent out of range error
      if (ascend.empty() || (i < height.size() &&
                             height[ascend.top()] <= height[i])) {
        ascend.push(i++);
      } else {  // non-ascend element or end of input
        int j = ascend.top();
        ascend.pop();
        // distance from last of ascend sequence to second largest
        int d = ascend.empty() ? i : i-1-ascend.top();
        max = std::max(max, height[j]*d);
      }
    }
    return max;
  }

  int maximalRectangle(vector<vector<char> > &matrix) {
    // This solution is based on largest rectangle in histogram
    // Let shape it: for each row i in matrix, the histogram is to
    // count number of '1' from i to 0, and the is any '0' is found
    // stop count immediately. Now for each row i, the maximal
    // rectangle of '1' is the largest rectangle in histogram. So
    // after all rows are calculated, we get the answer.
    int r = matrix.size();
    if (r == 0) return 0;
    int c = matrix[0].size();
    if (c == 0) return 0;
    vector<int> h(c, 0);  // histogram
    int i, j, ret = 0;
    for (i = 0; i < r; i++) {
      // generate histogram of row i
      for (j = 0; j < c; j++) {
        // if current row of j is '0', we need directly set it to 0
        // else we must add the previous histogram
        h[j] = matrix[i][j] == '0' ? 0 : h[j] + 1;
      }
      ret = std::max(ret, largestRectangleArea(h));
    }
    return ret;
  }
};

int main() {
  vector<string> str({"11", "01"});  // g++ -std=c++0x
  vector<vector<char> > m;
  for (int i = 0; i < str.size(); i++)
    m.push_back(vector<char>(str[i].begin(), str[i].end()));
  Solution s;
  printf("%d\n", s.maximalRectangle(m));
  return 0;
}
