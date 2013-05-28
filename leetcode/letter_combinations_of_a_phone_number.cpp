/* Given a digit string, return all possible letter combinations that
   the number could represent.
   A mapping of digit to letters (just like on the telephone buttons)
   is given below.
   Note:
   Although the above answer is in lexicographical order, your answer
   could be in any order you want. */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    char a[10][4] = {{' ', 0, 0, 0},        // 0
                     {0, 0, 0, 0},          // 1
                     {'a', 'b', 'c', 0},    // 2
                     {'d', 'e', 'f', 0},    // 3
                     {'g', 'h', 'i', 0},    // 4
                     {'j', 'k', 'l', 0},    // 5
                     {'m', 'n', 'o', 0},    // 6
                     {'p', 'q', 'r', 's'},  // 7
                     {'t', 'u', 'v', 0},    // 8
                     {'w', 'x', 'y', 'z'}}; // 9
    vector<string> r;
    int i, j, k, len;
    r.push_back(string(""));
    for (i = 0; i < digits.size(); i++) {
      len = r.size();
      for (j = 0; j < len; j++) {
        for (k = 0; k < 4; k++) {
          if (a[digits[i] - '0'][k] == 0)
            continue;
          r.push_back(r[j] + a[digits[i] - '0'][k]);
        }
      }
      // remove the previous ones, if expand happens
      if (r.size() != len)
        r.erase(r.begin(), r.begin() + len);
    }
    return r;
  }
};

int main() {
  string s = "1234";
  //cout << s+'c' << endl << s << endl;return 0;
  Solution sol;
  vector<string> r = sol.letterCombinations(s);
  for (int i = 0; i < r.size(); i++)
    cout << r[i] << endl;
  return 0;
}
