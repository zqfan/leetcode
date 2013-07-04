/* Copyright 2013 <ZhiQiang Fan>

   Implement wildcard pattern matching with support for '?' and '*'.

   '?' Matches any single character.
   '*' Matches any sequence of characters (including the empty
   sequence).

   The matching should cover the entire input string (not partial).

   The function prototype should be:
   bool isMatch(const char *s, const char *p)

   Some examples:
   isMatch("aa","a") ? false
   isMatch("aa","aa") ? true
   isMatch("aaa","aa") ? false
   isMatch("aa", "*") ? true
   isMatch("aa", "a*") ? true
   isMatch("ab", "?*") ? true
   isMatch("aab", "c*a*b") ? false
*/
#include <cstdio>
#include <climits>  // INT_MIN

class Solution {
  public:
  bool isMatch(const char * s, const char * p) {
    int ps = INT_MIN;  // previous star
    int i = 0, j = 0, k;
    while (s[i] && p[j]) {
      if (s[i] == p[j] || p[j] == '?') {
        i++, j++;
      } else if (p[j] == '*') {
        ps = j;
        j++;
      } else {  // s[i] != p[j] && p[j] is not special character
        if (ps == INT_MIN)  // no star exist
          return false;
        // jump to latest character after '*'
        if (j == ps + 1) {  // j already behind *
          i++;  // forward i
        } else {  // j is a bit far away from ps
          // Recursive i, j to the beginning, but forward one step.
          // Actually, i think kmp may be used here, and perhaps
          // the whole solution can be a transformed kmp algorithm.
          // However, this ugly solution cost only 92 ms!
          i = i - (j-ps) + 2;
          j = ps + 1;
        }
      }
    }
    if (!s[i]) {  // s reaches its end
      while (p[j] && p[j] == '*')  // check p is left non star char
        j++;
      return !p[j];
    } else {  // s doesn't reach its end, and so far s is match p
      if (ps == INT_MIN)  // no star in p
        return false;
      if (p[j-1] == '*')  // since p reaches its end, if p ends with *
        return true;
      for (k = i; s[k]; k++) {}  // get end of s
      while (j > ps) {
        if (s[k] != p[j] && p[j] != '?')
          return false;
        k--, j--;
      }
      return true;  // the rest can match with *
    }
  }
};

int main() {
  Solution sol;
  char s[100] = "", p[100] = "";
  printf("input two string, i will judge whether they are match\n");
  scanf("%s %s", s, p);
  printf("%d\n", sol.isMatch(s, p));
  return 0;
}
