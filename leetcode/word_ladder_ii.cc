/*
Copyright 2013 <ZhiQiang Fan>

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

Given two words (start and end), and a dictionary, find all shortest
transformation sequence(s) from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::unordered_multimap;
using std::queue;

class Solution {
  public:
  vector<vector<string> > findLadders(string start, string end,
                                      unordered_set<string> &dict) {
    vector<vector<string> > result;
    typedef unordered_set<string>::iterator iter;
    typedef unordered_multimap<string, string>::iterator mmiter;
    // queue<iter> is more efficient but i get some logical problem
    // in loop, so i use string
    queue<string> candidates;
    // each candidate's parent
    queue<string> cand_pars;
    // parent to parent, can use it to generate a list
    // i'd like to use iter, but "collect2: ld returned 1 exit status"
    // g++ refuse to work
    unordered_multimap<string, string> p2p;
    // int means in the bfs, the candidate's level
    unordered_map<string, int> visited;
    int level = 0;

    candidates.push(start);
    candidates.push("");  // level end
    cand_pars.push("");
    while (!candidates.empty()) {
      string s = candidates.front();
      candidates.pop();
      // reach level end
      if (s.empty()) {
        // result is not empty means shortest solution already found
        if (!result.empty())
          break;
        // no more candidates, must break
        if (candidates.empty())
          break;
        // next level stub
        candidates.push("");
        level++;
        continue;
      }
      string par = cand_pars.front();
      cand_pars.pop();
      for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        for (int j = 'a'; j <= 'z'; j++) {
          if (j == c)
            continue;
          s[i] = j;
          // bingo
          if (s.compare(end) == 0) {
            queue<vector<string> > sr;  // temp sub result queue
            queue<string> qs;  // queue of string path front
            vector<string> p(1, end);  // one of the path
            if (!par.empty()) {
              qs.push(par);
              p.push_back(par);
            } else {
              p.push_back(start);
            }
            sr.push(p);
            // find all the path
            while (!qs.empty()) {
              p = sr.front();
              sr.pop();
              std::pair<mmiter, mmiter> r = p2p.equal_range(qs.front());
              qs.pop();
              for (mmiter it = r.first; it != r.second; it++) {
                if (!it->second.empty()) {
                  qs.push(it->second);
                  p.push_back(it->second);
                } else {
                  p.push_back(start);
                }
                sr.push(p);
                p.pop_back();
              }
            }
            while (!sr.empty()) {
              std::reverse(sr.front().begin(), sr.front().end());
              result.push_back(sr.front());
              sr.pop();
            }
            s[i] = c;
            continue;
          }
          iter pos1 = dict.find(s);
          // in dict
          if (pos1 != dict.end()) {
            unordered_map<string, int>::iterator pos2 = visited.find(*pos1);
            // if not visited or it is parent level visited
            if (pos2 == visited.end()) {
              candidates.push(s);
              visited[*pos1] = level;
              cand_pars.push(*pos1);
              p2p.insert(std::make_pair(*pos1, par));
            } else if (pos2->second == level) {
              // same level visited this word means multiple path
              p2p.insert(std::make_pair(*pos1, par));
            }
          }
          s[i] = c;
        }
      }
    }
    return result;
  }
};

int main() {
  unordered_set<string> d({"hot","dot","dog","lot","log"});
  vector<vector<string> > r = Solution().findLadders("hit", "cog", d);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++)
      printf("%s ", r[i][j].c_str());
    printf("\n");
  }
  return 0;
}
