/* Copyright 2013 <ZhiQiang Fan>

   Implement int sqrt(int x).
   Compute and return the square root of x.
*/
#include <cstdio>
#include <cmath>
#include <cassert>
using std::abs;

class Solution {
  public:
  int sqrt(int x) {
    // I think sqrt(8) == 3 because it is more close to the answer.
    // However, leetcode think sqrt(8) == 2, i modify source code to
    // pass the test.
    // But here i insist this solution is right
    int left = 1, right = x, mid;

    // invalid input
    if (x < 0)
      return -1;

    // find the max number which less or equal to sqrt(x)
    while (left <= right) {
      // favorite right side to avoid infinite loop
      mid = (left + right + 1) / 2;
      if (x / mid == mid || left == right)
        break;
      else if (mid < x / mid)
        left = mid;
      else
        right = mid - 1;
    }

    // not (mid + 1)*(mid + 1) to avoid overflow
    if (abs(x - mid * mid) < abs(x - mid * mid - 2 * mid - 1))
      return mid;
    else
      return mid + 1;
  }
};

int main() {
  Solution s;
  int x;
  scanf("%d", &x);
  printf("%d\n", static_cast<int>(s.sqrt(x)));
  return 0;
}
