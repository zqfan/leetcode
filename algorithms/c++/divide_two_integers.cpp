/* Divide two integers without using multiplication, division and mod
   operator. */
/* it seems appear in cracking the coding interview */
#include <iostream>
using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    int r = 0;
    int factor = 1;
    long int d = 0;
    int t = 0;

    if (divisor == 0)
      return 0; // actually, you should raise exception

    if (dividend < 0)
      factor = -1;
    if (divisor < 0 && factor < 0)
      factor = 1;
    else if (divisor < 0 && factor > 0)
      factor = -1;
    // we can change INT_MAX to -INT_MAX
    // but cannot change INT_MIN to -INT_MIN
    dividend = dividend > 0 ? 0 - dividend : dividend;
    divisor = divisor > 0 ? 0 - divisor : divisor;

    while (dividend != 0 && dividend <= divisor) {
      d = divisor;
      t = 1;
      while (dividend != 0 && dividend <= d) {
        r += t;
        dividend -= d;
        d += d;
        if (d >= 0) // overflow means should end this loop
          break;
        t += t;
      }
    }
    return factor > 0 ? r : 0 - r;
  }
};

int main() {
  Solution sol;
  int i, j;
  cin >> i >> j;
  cout << sol.divide(i, j) << endl;
  return 0;
}
