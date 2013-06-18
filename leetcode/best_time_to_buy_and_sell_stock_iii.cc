/*
Copyright 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

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

Say you have an array for which the ith element is the price of a
given stock on day i.
Design an algorithm to find the maximum profit. You may complete at
most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you
must sell the stock before you buy again).
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
  public:
  int maxProfit(vector<int> & prices) {
    // NOTE(zqfan): original author of this solution
    //              Ark@leetcode
    //              http://discuss.leetcode.com/questions/287/\
    //              best-time-to-buy-and-sell-stock-iii
    // let d[i] = p[i+1] - p[i], we get a int seq
    // find the max sum of 2 segments in this seq is the answer
    // let max[i] to be the answer of first i numbers
    // let end[i][2] is include d[i], and has 2 segments
    // end[i][2]' = end[i-1][2] + d[i]
    // if d[i] is individual segment, then find max of max[i-1][1]
    // end[i][2]'' = maximum(max[i-1][1])) + d[i]
    // end[i][2] = maximum(end[i][2]', end[i][2]'')
    // since d[i] can be negative, we need the max sum
    // max[i] = maximum(end[i][2], max[i-1])
    // for i = 0, end[0][2] is not valid,
    // just has end[0][1] and max[1]
    // note that each i just need i-1 data, so we don't need a array
    int max[3] = {0};
    int end[3] = {0};
    int n, i, j, m, d;

    // this is necessary because size() return size_type, which is
    // unsigned type, and if prices is empty, i < prices.size() - 1
    // will cause segment fault
    n = prices.size() - 1;
    for (i = 0; i < n; i++) {
      m = std::min(i+1, 2);
      d = prices[i+1] - prices[i];
      for (j = m; j > 0; j--) {
        end[j] = std::max(end[j], max[j-1]) + d;
        max[j] = std::max(end[j], max[j]);
      }
    }
    return std::max(max[1], max[2]);
  }
};

int main() {
  int n[] = {};
  vector<int> p(n, n+sizeof(n)/sizeof(int));
  Solution s;
  printf("%d\n", s.maxProfit(p));
  return 0;
}
