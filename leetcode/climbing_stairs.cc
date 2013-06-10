/* Copyright 2013 <ZhiQiang Fan>

   You are climbing a stair case. It takes n steps to reach to the top.

   Each time you can either climb 1 or 2 steps. In how many distinct
   ways can you climb to the top?
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
 public:
  int climbStairs(int n) {
    // invalid input
    if (n < 1)
      return 0;

    vector<int> stairs(n, 0);
    stairs[0] = 1;
    if (n > 1)
      stairs[1] = 2;
    for (int i = 2; i < n; i++)
      stairs[i] = stairs[i-1] + stairs[i-2];

    return stairs[n-1];
  }
};

int main() {
  int n;
  scanf("%d", &n);
  Solution s;
  printf("%d\n", s.climbStairs(n));
  return 0;
}
