/*
Copyright (C) 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

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

Given a string S and a string T, count the number of distinct
subsequences of T in S.
A subsequence of a string is a new string which is formed from the
original string by deleting some (can be none) of the characters
without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"
Return 3.
*/
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using std::string;
using std::vector;
using std::map;
using std::unordered_map;

class Solution {
  public:
  int numDistinct(string S, string T) {
    unordered_map<char, vector<int> > char_pos;
    unordered_map<char, vector<int> >::iterator umi;
    map<int, int> prev_status;
    map<int, int> cur_status;
    map<int, int>::iterator mip;  // prev_status iterator
    map<int, int>::iterator mic;  // cur_status iterator
    int i, j;
    for (i = 0; i < S.size(); i++) {
      if (char_pos.find(S[i]) != char_pos.end()) {
        char_pos[S[i]].push_back(i);
      } else {
        char_pos[S[i]] = vector<int>(1, i);
      }
    }
    // the first character
    umi = char_pos.find(T[0]);
    if (umi == char_pos.end())
      return 0;
    for (j = 0; j < umi->second.size(); j++)
        prev_status[umi->second[j]] = j + 1;
    for (i = 1; i < T.size(); i++) {
      umi = char_pos.find(T[i]);
      if (umi == char_pos.end())
        return 0;
      cur_status.clear();
      for (j = 0; j < umi->second.size(); j++) {
        cur_status[umi->second[j]] = 0;
      }
      mip = prev_status.begin();
      for (; mip != prev_status.end(); mip++) {
        mic = cur_status.upper_bound(mip->first);  // first larger
        if (mic == cur_status.end())
          break;
        mic->second = mip->second;
      }
      // iterator before cur_status current iterator
      mic = cur_status.begin();
      int p = mic->second;  // prev pos count
      int sum = p;
      for (mic++; mic != cur_status.end(); mic++) {
        // check the missing unset position
        // {{2,1},{3,0},{4,1}} should be {{2,1},{3,2},{4,4}}
        if (mic->second != 0)
          p = mic->second;
        else
          mic->second = p;
        mic->second += sum;
        sum = mic->second;
      }
      prev_status = cur_status;
    }
    // last non zero means the max distinct
    map<int, int>::reverse_iterator mric = prev_status.rbegin();
    for (; mric != prev_status.rend(); mric++)
      if (mric->second != 0)
        return mric->second;
    return 0;  // no such sub seq
  }
};

int main() {
  Solution s;
  printf("%d\n", s.numDistinct("rabbbiiitit", "rabbit"));
  return 0;
}
