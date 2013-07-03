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

You are given a string, S, and a list of words, L, that are all of
the same length. Find all starting indices of substring(s) in S
that is a concatenation of each word in L exactly once and without
any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). */
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <queue>
using std::vector;
using std::string;
using std::map;
using std::queue;

class Solution {
  public:
  vector<int> findSubstring(string S, vector<string> &L) {
    // i search word in S in every L[0].size and compare it to any
    // word in L, to accelerate, i use hash
    vector<int> ret;
    if (L.size() == 0) return ret;
    int m = S.size();
    int n = L[0].size();
    int count = 0;  // count of sub words of S found in L
    map<string, int> fl;  // words frequency in l
    map<string, int> fs;  // words frequency in s
    map<string, queue<int> > sp;  // words in S's pos
    int i, j;
    // init fl
    for (i = 0; i < L.size(); i++) {
      if (fl.find(L[i]) == fl.end())
        fl[L[i]] = 0;
      fl[L[i]]++;
    }
    // divide S to L[0].size width trip, and each divide may start
    // at [0,...,L[0].size]
    for (i = 0; i < n; i++) {
      count = 0;
      fs.clear();
      sp.clear();
      for (j = i; j + n <= m; j += n) {
        string s = S.substr(j, n);
        if (fl.find(s) != fl.end()) {  // s in L
          if (fs.find(s) == fs.end()) {  // s is new for fs
            fs[s] = 0;
            sp[s] = queue<int>();
          }
          fs[s]++;
          sp[s].push(j);
          if (fs[s] <= fl[s])  // avoid duplicate str in L
            count++;
          if (count == L.size())  // bingo
            ret.push_back(j-n*L.size()+n);
        }
        if (fl.find(s) == fl.end()) {  // no such word in L
          count = 0;
          fs.clear();
          sp.clear();
        } else if (count == L.size()) {
          // remove first word and start next round
          count--;
          string first = S.substr(j-n*L.size()+n, n);
          fs[first] = fs[first] - 1;
          sp[first].pop();
        } else if (fs[s] > fl[s]) {  // more duplicate word found
          // check distance to current position, if it is close to
          // current, then initialize a round
          if (j-sp[s].front() < count*n/2) {
            j = sp[s].front();
            sp.clear();
            count = 0;
            fs.clear();
          } else {
            // if it is close to the beginning, remove all the word
            // before the duplicated word (include itself)
            int t = sp[s].front();
            for (int k = j-count*n; k <= t; k += n) {
              string d = S.substr(k, n);
              printf("%s\n", d.c_str());
              fs[d]--;
              sp[d].pop();
              count--;
            }
            count++;  // start to count, include current pos
          }
        }
      }
    }
    return ret;
  }
};

int main() {
  string S = "barfoothefoobarman";
  vector<string> T({"foo", "bar"});  // g++ -std=c++0x
  vector<int> r = Solution().findSubstring(S, T);
  for (int i = 0; i < r.size(); i++)
    printf("%d ", r[i]);
  printf("\n");
  return 0;
}
