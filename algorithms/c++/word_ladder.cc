/*
Copyright 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

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

Given two words (start and end), and a dictionary, find the length
of shortest transformation sequence from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is
"hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <cstdio>
#include <string>
#include <unordered_set>
#include <queue>
using std::string;
using std::unordered_set;
using std::queue;

class Solution {
  public:
  int ladderLength(string start, string end,
                   unordered_set<string> &dict) {
    typedef unordered_set<string>::iterator s_iter;
    // i don't want to modify the parameter dict,
    // because it may be used again
    // directly use dict.erase() can optimize resource
    unordered_set<string> visited;
    int level = 0;  // bfs level
    queue<s_iter> candidate;
    string s = start;
    s_iter p = dict.find(s);
    if (p != dict.end())
      visited.insert(*p);
    candidate.push(dict.end());
    while (true) {
      for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        for (int j = 'a'; j <= 'z'; j++) {
          if (j == c)
            continue;
          s[i] = j;
          // find it
          if (s.compare(end) == 0)
            return level + 2;
          p = dict.find(s);
          // new candidate
          if (p != dict.end() && visited.find(*p) == visited.end()) {
            candidate.push(p);
            visited.insert(*p);
          }
          s[i] = c;
        }
      }
      // normal candidate
      if (candidate.front() != dict.end()) {
        s = *candidate.front();
      } else {  // level end stub
        if (candidate.size() == 1)  // only has a stub
          break;
        candidate.pop();  // use next candidate, that one must be normal
        s = *candidate.front();
        candidate.push(dict.end());  // next level stub
        level++;
      }
      candidate.pop();
    }

    return 0;  // no such solution
  }
};

int main() {
  unordered_set<string> d({"hot","dot","dog","lot","log"});
  Solution s;
  printf("%d\n", s.ladderLength("hit", "cog", d));
  return 0;
}
