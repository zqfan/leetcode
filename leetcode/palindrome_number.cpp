/* Determine whether an integer is a palindrome. Do this without extra
   space. */
#include "iostream"
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      // reverse it and compare with x can be wrong because for 16-bit
      // system, max int is 32767, which means reverse 32767 will
      // overflow, and may leading to wrong answer.

      // i still use two integer space
      int factor, tmp;

      // this is still danger, for 16-bit, -(-32768) != 32768
      // i think -101 is palindrome, but leetcode denies it.
      if (x < 0)
        return false;

      // get the highest digit factor, if x = 111, then factor = 100
      factor = 1;
      tmp = x;
      while (tmp >= 10) {
        factor *= 10;
        tmp /= 10;
      }

      // check digit from high to low, for i.e. x = 1221
      // first step:
      // (1221 / 1000) % 10 == (111 / 1) % 10
      // second loop:
      // (1221 / 100) % 10 == (1221 / 10) % 10
      tmp = 1;
      while (factor > tmp) {
        if ((x / factor) % 10 != (x / tmp) % 10)
          return false;
        factor /= 10;
        tmp *= 10;
      }
      return true;
    }
};

int main() {
  Solution sol;
  int n;
  cin >> n;
  cout << sol.isPalindrome(n) << endl;
  return 0;
}
