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

class Solution {
  public:
  bool isMatch(const char *s, const char *p) {
    int i, j;
    bool exactly_match = true;

    i = j = 0;
    while (true) {
      // s is empty now, check if p is *
      if (!s[i]) {
        while (p[j] && p[j] == '*')
          j++;
        return p[j] == 0;
      }
      // p is empty now, but s is not empty
      if (!p[j])
        return star_dis <= 1;
      // p[j] is ?, s, p just forward a single step
      if (p[j] == '?') {
        i++;
        j++;
      } else if (p[j] == '*') {
        // p[j] is *, forward a single step of p
        j++;
        exactly_match = false;
      } else {
        
        // find p[j] in s[i]
        while (s[i] && s[i] != p[j])
          i++;
        // cannot find p[j]
        if (!s[i])
          return false;
        i++;
        j++;
        cc++;
      }
    }  // end of while true
  }
};

int main() {
  Solution sol;
  char s[100], p[100];
  scanf("%s %s", s, p);
  printf("%d\n", sol.isMatch(s, p));
  return 0;
}
