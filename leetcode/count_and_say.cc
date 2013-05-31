/* Copyright 2013 <ZhiQiang Fan>

   The count-and-say sequence is the sequence of integers beginning as
   follows:
   1, 11, 21, 1211, 111221, ...

   1 is read off as "one 1" or 11.
   11 is read off as "two 1s" or 21.
   21 is read off as "one 2, then one 1" or 1211.

   Given an integer n, generate the nth sequence.

   Note: The sequence of integers will be represented as a string.
*/
#include <cstdio>
#include <string>
using std::string;

class Solution {
  public:
  string countAndSay(int n) {
    string r, t;
    int i, j, k;

    if (n <= 0)
      return r;

    r = "1";
    for (i = 1, t = "1"; i < n ; i++) {
      r = "";
      for (j = 0; j < t.size(); j++) {
        k = 1;
        while (j + 1 < t.size() && t[j] == t[j + 1]) {
          k++;
          j++;
        }
        r += std::to_string(k);
        r += std::to_string(t[j] - '0');
      }
      t = r;
    }

    return r;
  }
};

int main() {
  Solution sol;
  printf("%s\n", sol.countAndSay(5).c_str());
  return 0;
}
