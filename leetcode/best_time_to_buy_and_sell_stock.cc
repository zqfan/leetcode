/* Copyright 2013 <ZhiQiang Fan>

   Say you have an array for which the ith element is the price of a
   given stock on day i.
   If you were only permitted to complete at most one transaction (ie,
   buy one and sell one share of the stock), design an algorithm to
   find the maximum profit.
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 1)
      return 0;

    int max_price = prices.back();
    int max_profit = 0;

    for (int i = prices.size() - 2; i >= 0; i--) {
      if (prices[i] > max_price) {
        max_price = prices[i];
      } else if (max_price - prices[i] > max_profit) {
        max_profit = max_price - prices[i];
      }
    }

    return max_profit;
  }
};

int main() {
  int n[] = {4, 1, 2};
  vector<int> p(n, n+sizeof(n)/sizeof(int));
  Solution s;
  printf("%d\n", s.maxProfit(p));
  return 0;
}
