/* Given a roman numeral, convert it to an integer.
   Input is guaranteed to be within the range from 1 to 3999. */
#include <iostream>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int integer[] = {1000, 900, 500, 400,
                     100, 90, 50, 40,
                     10, 9, 5, 4, 1};
    string roman[] = {"M", "CM", "D", "CD",
                      "C", "XC", "L", "XL",
                      "X", "IX", "V", "IV", "I"};
    int n, i, len;
    len = sizeof(integer) / sizeof(int);
    n = 0;
    for (i = 0; i < len; i++) {
      while (s.find(roman[i]) == 0) {
        n += integer[i];
        s = s.substr(roman[i].size());
      }
    }
    return n;
  }
};

int main() {
  string r;
  cin >> r;
  Solution sol;
  cout << sol.romanToInt(r) << endl;
  return 0;
}
