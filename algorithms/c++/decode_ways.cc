/* Copyright 2013 <ZhiQiang Fan>

   A message containing letters from A-Z is being encoded to numbers
   using the following mapping:

   'A' -> 1
   'B' -> 2
   ...
   'Z' -> 26

   Given an encoded message containing digits, determine the total
   number of ways to decode it.

   For example,
   Given encoded message "12", it could be decoded as "AB" (1 2) or
   "L" (12).
   The number of ways decoding "12" is 2.
*/
#include <cstdio>
#include <string>
using std::string;

class Solution {
  public:
  int numDecodings(string s) {
    // i will not handle the invalid input
    // HAHA, leetcode says it will give me a invalid input,
    // are you boring?
    // Use g++ -std=c++0x to compile, because std::stoi
    int f1, f2;
    int i, tmp;

    if (s.size() < 1)
      return 0;

    f1 = 1;
    f2 = 1;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        // invalid input
        if (i < 1)
          return 0;
        // invalid input
        if (s[i - 1] == '0' || std::stoi(s.substr(i - 1, 2)) > 26)
          return 0;
        f2 = f1;
      } else {
        if (i == 0) {
          continue;
        } else if (s[i - 1] != '0' &&
                   std::stoi(s.substr(i - 1, 2)) <= 26) {
          // can be two digits
          tmp = f2;
          f2 = f1 + f2;
          f1 = tmp;
        } else {
          f1 = f2;
        }
      }
    }

    return f2;
  }
};

int main() {
  char s[100];
  scanf("%s", s);
  Solution sol;
  printf("%d\n", sol.numDecodings(s));
  return 0;
}
