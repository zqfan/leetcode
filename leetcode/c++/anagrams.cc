/* Copyright (C) 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/* Given an array of strings, return all groups of strings that are
anagrams.
Note: All inputs will be in lower-case. */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>  // g++ -std=c++0x
using std::string;
using std::vector;

class Solution {
  public:
  vector<string> anagrams(vector<string> & strs) {
    // using hash to accelerate
    // Accepted: 176ms
    vector<string> ret;
    // int stores the position of first string added to hash
    std::unordered_map<string, int> hash;
    for (int i = 0; i < strs.size(); i++) {
      string s = strs[i];
      std::sort(s.begin(), s.end());
      if (hash.count(s)) {  // is anagram
        // the first string not add to result yet
        if (hash[s] != -1) {
          ret.push_back(strs[hash[s]]);
          hash[s] = -1;  // mark it
        }
        ret.push_back(strs[i]);  // add current anagram
      } else {
        hash[s] = i;  // insert it
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s[] = {"123", "213", "324"};
  vector<string> strs;
  int i;
  for (i = 0; i < 3; i++)
    strs.push_back(s[i]);
  vector<string> r = sol.anagrams(strs);
  for (i = 0; i < r.size(); i++)
    printf("%s\n", r[i].c_str());
  return 0;
}
