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

Given n non-negative integers representing the histogram's bar height
where the width of each bar is 1, find the area of largest rectangle
in the histogram.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/
#include <cstdio>
#include <cstring>  // memset
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution {
  public:
  int largestRectangleArea(vector<int> &height) {
    // my previous solution is O(N^2), so get time limit exceed
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
};

int main() {
  int a[] = {2, 1, 5, 6, 2, 3};
  vector<int> h(a, a+sizeof(a)/sizeof(int));  // h({})
  Solution s;
  printf("%d\n", s.largestRectangleArea(h));
  return 0;
}
