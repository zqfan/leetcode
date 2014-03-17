/* Copyright 2013 <ZhiQiang Fan>

   Given a number represented as an array of digits, plus one to the
   number.
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  vector<int> plusOne(vector<int> &digits) {
    int i, s, d = 0;

    digits.back()++;
    for (i = digits.size() - 1; i >= 0; i--) {
      s = digits[i] + d;
      digits[i] = s % 10;
      d = s / 10;
    }
    if (d > 0)
      digits.insert(digits.begin(), d);

    return digits;
  }
};

int main() {
  Solution s;
  vector<int> digits(1, 0);
  int i, j;
  for (i = 0; i < 1024; i++)
    digits = s.plusOne(digits);
  for (i = 0; i < digits.size(); i++)
    printf("%d", digits[i]);
  printf("\n");
  return 0;
}
