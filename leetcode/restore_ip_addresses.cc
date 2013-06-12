/* Copyright 2013 <ZhiQiang Fan>

   Given a string containing only digits, restore it by returning all
   possible valid IP address combinations.

   For example:
   Given "25525511135",

   return ["255.255.11.135", "255.255.111.35"]. (Order does not
   matter)
*/
#include <cstdio>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
  public:
  vector<string> restoreIpAddresses(string s) {
    // compile this with g++ -std=c++0x
    vector<string> result;
    string tmp;
    int i, j, k, l, m;

    if (s.size() < 4 || s.size() > 12)
      return result;

    for (i = 1; i < 4; i++) {
      tmp = s.substr(0, i);
      if (tmp[0] == '0' && tmp != "0")
        continue;
      m = std::stoi(tmp);
      if (0 > m || m > 255)
        continue;
      for (j = 1; j < 4; j++) {
        tmp = s.substr(i, j);
        if (tmp[0] == '0' && tmp != "0")
          continue;
        m = std::stoi(tmp);
        if (0 > m || m > 255)
          continue;
        for (k = 1; k < 4; k++) {
          if (i + j >= s.size() || i + j + k >= s.size())
            continue;
          tmp = s.substr(i + j, k);
          if (tmp[0] == '0' && tmp != "0")
            continue;
          m = std::stoi(tmp);
          if (0 > m || m > 255)
            continue;
          // check the rest
          tmp = s.substr(i + j + k);
          if (tmp[0] == '0' && tmp != "0")
            continue;
          m = std::stoi(tmp);
          if (0 > m || m > 255)
            continue;
          tmp = s;
          tmp.insert(i, 1, '.');
          tmp.insert(i + j + 1, 1, '.');
          tmp.insert(i + j + k + 2, 1, '.');
          result.push_back(tmp);
        }  // end for k
      }  // end for j
    }  // end for i

    return result;
  }
};

int main() {
  char s[100];
  scanf("%s", s);
  Solution sol;
  vector<string> r = sol.restoreIpAddresses(s);
  for (int i = 0; i < r.size(); i++)
    printf("%s\n", r[i].c_str());
  return 0;
}
