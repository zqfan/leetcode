/* Given a string, find the length of the longest substring without
   repeating characters. For example, the longest substring without
   repeating letters for "abcabcbb" is "abc", which the length is 3.
   For "bbbbb" the longest substring is "b", with the length of 1. */
#include "iostream"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ascii[128] = {0};
      int i, j, len, max_len = 0;
      for (i = 0; i < s.size(); i++) {
        len = 0;
        for (j = 0; j < 128; j++)
          ascii[j] = 0;
        for (j = 0; i + j < s.size(); j++) {
          if (ascii[s.at(i+j)])
            break;
          len++;
          ascii[s.at(i+j)] = 1;
        }
        if (len > max_len)
          max_len = len;
      }
      return max_len;
    }
};

int main() {
  Solution solution;
  string s;
  cin >> s;
  cout << solution.lengthOfLongestSubstring(s) << endl;
  return 0;
}
