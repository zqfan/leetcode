/* Copyright 2013 <ZhiQiang Fan>

   Given two numbers represented as strings, return multiplication of
   the numbers as a string.

   Note: The numbers can be arbitrarily large and are non-negative.
*/
#include <cstdio>
#include <string>
using std::string;

class Solution {
  public:
  string multiply(string num1, string num2) {
    string result, tmp;
    int i, j, k, m, h;

    if (num1 == "0" || num2 == "0")
      return string("0");

    for (i = num2.size() - 1; i >= 0; i--) {
      /* calculate single digit */
      //if (num2[i] == '0')
      //  continue;
      tmp = "";
      h = 0;
      for (j = num1.size() - 1; j >= 0; j--) {
        m = (num1[j] - '0') * (num2[i] - '0') + h;
        h = m / 10;
        tmp = string(1, m % 10 + '0') + tmp;
      }
      if (h > 0)
        tmp = string(1, h + '0') + tmp;
      /* add tmp to result */
      h = 0;
      k = result.size() - 1 - (num2.size() - 1 - i);
      for (j = tmp.size() - 1; j >= 0; j--, k--) {
        if (k >= 0)
          m = (tmp[j] - '0') + (result[k] -'0') + h;
        else
          m = tmp[j] - '0' + h;
        h = m / 10;
        if (k >= 0)
          result[k] = m % 10 + '0';
        else
          result = string(1, m % 10 + '0') + result;
      }
      if (h > 0 && k < 0)
        result = string(1, h + '0') + result;
    }
    return result;
  }
};

int main() {
  Solution sol;
  printf("%s\n", sol.multiply(string("6"), string("1001")).c_str());
  return 0;
}
