/* Given a string S, find the longest palindromic substring in S. You
   may assume that the maximum length of S is 1000, and there exists
   one unique longest palindromic substring. */
/* This problem actually has O(n) algorithm, i just try O(n*n)
   algorithm first */
#include "iostream"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      int i, j, len, max_len, start;
      string ps; /* palindromic substring */
      start = 0;
      max_len = 1;
      for (i = 0; i < s.size(); i++) {
        len = 1;
        for (j = 1; i - j >= 0 && i + j < s.size(); j++) {
          if (s.at(i - j) != s.at(i + j))
            break;
          len += 2;
        }
        if (len > max_len) {
          start = i - j + 1;
          max_len = len;
        }
        /* even size of palindromic */
        if (i + 1 < s.size() && s.at(i) == s.at(i + 1)) {
          len = 2;
          for (j = 1; i - j >= 0 && i + 1 + j < s.size(); j++) {
            if (s.at(i - j) != s.at(i + 1 + j))
              break;
            len += 2;
          }
          if (len > max_len) {
            start = i - j + 1;
            max_len = len;
          }
        }
      } /* end for i */
      return s.substr(start, max_len);
    }
};

int main() {
  Solution s;
  string str;
  cin >> str;
  cout << s.longestPalindrome(str) << endl;
  return 0;
}
