/* Copyright 2013 <ZhiQiang Fan>

   Given a string s consists of upper/lower-case alphabets and empty
   space characters ' ', return the length of last word in the string.

   If the last word does not exist, return 0.

   Note: A word is defined as a character sequence consists of
   non-space characters only.

   For example,
   Given s = "Hello World",
   return 5.
*/
#include <cstdio>

class Solution {
  public:
  int lengthOfLastWord(const char *s) {
    int len = 0;
    int i = -1;

    while (s[++i]) {
      if (s[i] == ' ') {
        // find next character
        while (s[++i] && s[i] == ' ') {}
        if (s[i])
          len = 1;
        // reach the end
        else
          return len;
      } else {
        len++;
      }
    }

    return len;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.lengthOfLastWord("hello hell"));
  return 0;
}
