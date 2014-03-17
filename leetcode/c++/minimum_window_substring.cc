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

Given a string S and a string T, find the minimum window in S which
will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T,
return the emtpy string "".
If there are multiple such windows, you are guaranteed that there will
always be only one unique minimum window in S.
*/
#include <cstdio>
#include <string>
#include <unordered_map>  // -std=c++0x
#include <queue>
using std::string;
using std::unordered_map;
using std::queue;

class Solution {
  public:
  string minWindow(string S, string T) {
    // hash will record each character's frequency in T
    unordered_map<char, int> f;
    for (int i = 0; i < T.size(); i++) {
      if (f.find(T[i]) == f.end())
        f[T[i]] = 0;
      f[T[i]]++;
    }
    string ret = S+T;
    // queue stores index of characters appear in S
    queue<int> q;
    unordered_map<char, int> sf;  // frequency of character in S
    int count = 0;
    for (int i = 0; i < S.size(); i++) {
      // S[i] not in T
      if (f.find(S[i]) == f.end())
        continue;
      q.push(i);
      if (sf.find(S[i]) == sf.end())
        sf[S[i]] = 0;
      sf[S[i]]++;
      if (sf[S[i]] == f[S[i]])
        count++;
      if (count == f.size()) {  // there might be duplicate in T
        // remove extra elements by check the sf and f
        // but i just remove until first character without extra
        // elements, the new sequence may still has extra characters
        // but it holds the the characters needed, if i remove more,
        // then this sequence is no longer valid.
        while (sf[S[q.front()]] != f[S[q.front()]]) {
          sf[S[q.front()]]--;  // remove extra elements
          q.pop();
        }
        if (i-q.front()+1 < ret.size())
          ret = S.substr(q.front(), i-q.front()+1);
        sf[S[q.front()]]--;
        q.pop();
        count--;
      }
    }
    return ret.compare(S+T) == 0 ? "" : ret;
  }
};

int main() {
  string S = "ADOBECODEBANC";
  string T = "ABC";
  Solution s;
  printf("%s\n", s.minWindow(S, T).c_str());
  return 0;
}
