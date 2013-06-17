/* Copyright 2013 <ZhiQiang Fan>

   Write a function to find the longest common prefix string amongst
   an array of strings.
*/
#include <cstdio>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
  public:
  string longestCommonPrefix(vector<string> &strs) {
    string result;
    int i, j;

    if (strs.size() < 1)
      return result;
    if (strs.size() == 1)
      return strs[0];

    for (i = 0; i < strs[0].size() && i < strs[1].size(); i++) {
      if (strs[0][i] != strs[1][i])
        break;
    }
    result = strs[0].substr(0, i);
    for (i = 2; i < strs.size(); i++) {
      for (j = 0; j < result.size() && j < strs[i].size(); j++) {
        if (result[j] !=  strs[i][j])
          break;
      }
      result = result.substr(0, j);
    }
    return result;
  }
};

int main() {
  string str[] = {"abc", "ade", "ade"};
  vector<string> strs;
  for (int i = 0; i < 3; i++)
    strs.push_back(str[i]);
  printf("%s\n", Solution().longestCommonPrefix(strs).c_str());
  return 0;
}
