/* Copyright 2013 <ZhiQiang Fan>

   Say you have an array for which the ith element is the price of a
   given stock on day i.
   Design an algorithm to find the maximum profit. You may complete as
   many transactions as you like (ie, buy one and sell one share of
   the stock multiple times). However, you may not engage in multiple
   transactions at the same time (ie, you must sell the stock before
   you buy again).
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;

    if (prices.size() < 1)
      return 0;

    for (int i = 0; i < prices.size() - 1; i++) {
      if (prices[i] - prices[i+1] < 0) {
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
