/* Copyright (C) 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

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
*/

/* Say you have an array for which the ith element is the price of a
given stock on day i.
Design an algorithm to find the maximum profit. You may complete as
many transactions as you like (ie, buy one and sell one share of the
stock multiple times). However, you may not engage in multiple
transactions at the same time (ie, you must sell the stock before you
buy again). */
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    for (size_t i = 0; i + 1 < prices.size(); i++) {
      if (prices[i+1] - prices[i] > 0) {
        max_profit += prices[i+1] - prices[i];
      }
    }
    return max_profit;
  }
};

int main() {
  int n[] = {1, 2, 1, 3};
  vector<int> p(n, n+sizeof(n)/sizeof(int));
  Solution s;
  printf("%d\n", s.maxProfit(p));
  return 0;
}
