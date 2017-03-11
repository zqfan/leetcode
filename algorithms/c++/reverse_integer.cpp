/* Reverse digits of an integer.
   Example1: x = 123, return 321
   Example2: x = -123, return -321 */
#include "iostream"
#include "cassert"
using namespace std;

class Solution {
public:
    int reverse(int x) {
      int factor, n;
      factor = x > 0 ? 1 : -1;
      n = 0;
      x = x * factor;
      while (x != 0) {
        n = n * 10 + x % 10;
        x /= 10;
      }
      return n * factor;
    }
};

int main() {
  Solution sol;
  assert(0 == sol.reverse(0));
  assert(123 == sol.reverse(321));
  assert(123 == sol.reverse(+321));
  assert(-123 == sol.reverse(-321));
  return 0;
}
