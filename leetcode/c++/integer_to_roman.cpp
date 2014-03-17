/* Given an integer, convert it to a roman numeral.
   Input is guaranteed to be within the range from 1 to 3999. */
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
      int integer[] = {1000, 900, 500, 400,
                     100, 90, 50, 40,
                     10, 9, 5, 4, 1};
      string roman[] = {"M", "CM", "D", "CD",
                      "C", "XC", "L", "XL",
                      "X", "IX", "V", "IV", "I"};
      string r;
      int len = sizeof(integer) / sizeof(int);
      for (int i = 0; i < len; i++) {
        while (num >= integer[i]) {
          r += roman[i];
          num -= integer[i];
        }
      }
      return r;
    }
};

int main() {
  int i;
  Solution sol;
  cin >> i;
  cout << sol.intToRoman(i) << endl;
  return 0;
}
