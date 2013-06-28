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

Given a string s, partition s such that every substring of the
partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return
[
["aa","b"],
["a","a","b"]
]
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using std::vector;
using std::string;
using std::queue;

class Solution {
  public:
  vector<vector<string> > partition(string s) {
    vector<vector<string> > ret;
    int n = s.size();
    bool p[n][n];  // p[i][j] means s[i,j] is palindrome
    memset(p, 0, sizeof(p));
    int i, j, k;
    // make palindrome cache
    for (i = n-1; i >= 0; i--) {
      for (j = i; j < n; j++) {
        // s[i,j] is palindrome
        if (s[i] == s[j] && (j-i < 2 || p[i+1][j-1]))
          p[i][j] = true;
      }
    }
    queue<vector<int> > q;
    // there are n-1 possible cuts way
    for (i = 0; i < n; i++) {
      q.push(vector<int>(1, 0));
      q.push(vector<int>());  // bfs level stub
      // for each way's each cut
      for (j = 0; j < i; j++) {
        while (!q.empty()) {
          vector<int> f = q.front();
          q.pop();
          if (f.empty()) {
            q.push(vector<int>());
            break;
          }
          for (k = f.back(); k < n; k++) {
            if (p[f.back()][k]) {
              f.push_back(k+1);
              q.push(f);
              f.pop_back();
            }
          }
        }
      }
      // check the remain part, if they are palindrome, then it is a
      // valid cut, append it to result
      while (!q.empty()) {
        vector<int> f = q.front();
        q.pop();
        if (f.empty())
          break;  // it is bfs level stub
        if (!p[f.back()][n-1])
          continue;  // the remain part is not palindrome
        // append this cut to result
        vector<string> v;
        // generate each cut substr
        for (k = 0; k < f.size()-1; k++)
          v.push_back(s.substr(f[k], f[k+1]-f[k]));
        v.push_back(s.substr(f[k], n-f[k]));
        ret.push_back(v);
      }
    }
    return ret;
  }
};

int main() {
  string s = "aabbcc";
  Solution sol;
  vector<vector<string> > r = sol.partition(s);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++)
      printf("%s ", r[i][j].c_str());
    printf("\n");
  }
  return 0;
}
