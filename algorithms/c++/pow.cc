/* Copyright 2013 <ZhiQiang Fan>

   Implement pow(x, n).
*/
#include <cstdio>
#include <cassert>
#include <cmath>

class Solution {
  public:
  double pow(double x, int n) {
    double r, rr;
    int i, nn;

    r = 1;
    if (n >= 0) {
      while (n > 0) {
        for (i = 0, rr = x, nn = 1; i < n; i = nn) {
          r *= rr;
          n -= nn;
          rr = rr * rr;
          nn *= 2;
        }
      }
    } else {
      while (n < 0) {
        for (i = 0, rr = 1/x, nn = -1; i > n; i = nn) {
          r *= rr;
          n -= nn;
          rr = rr * rr;
          nn *= 2;
        }
      }
    }

    return r;
  }
};

int main() {
  Solution s;
  double x;
  int n;
  scanf("%lf %d", &x, &n);
  assert(s.pow(x, n) - pow(x, n) < 0.00001);
  printf("%.5lf\n", s.pow(x, n));
  return 0;
}
