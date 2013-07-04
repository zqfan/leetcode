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

Given an array of words and a length L, format the text such that
each line has exactly L characters and is fully (left and right)
justified.

You should pack your words in a greedy approach; that is, pack as
many words as you can in each line. Pad extra spaces ' ' when
necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as
possible. If the number of spaces on a line do not divide evenly
between words, the empty slots on the left will be assigned more
spaces than the slots on the right.

For the last line of text, it should be left justified and no extra
space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text",
"justification."]
L: 16.

Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

Corner Cases:
A line other than the last line might contain only one word. What
should you do in this case?
In this case, that line should be left-justified.
*/
#include <cstdio>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
  public:
  vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> ret;
    int s = 0;  // start index
    int i, j, k, len = 0;
    string t;
    for (i = 0; i < words.size(); i++) {
      // number of characters + spaces + next word's length
      if (len+i-s+words[i].size() > L) {
        int ts = L - len;  // total space
        int as = i-1 == s ? ts : ts / (i-1-s);  // average space
        int es = i-1 == s ? 0 : ts % (i-1-s);  // extra space for left
        t = string(L, ' ');
        for (j = s, k = 0; j < i; j++) {
          t.replace(k, words[j].size(), words[j]);
          k += words[j].size() + as;
          if (j - s < es) k++;
        }
        ret.push_back(t);
        // start new line
        s = i;
        len = 0;
      }
      // continue to add words
      len += words[i].size();
    }
    // last line
    t = string(L, ' ');
    for (i = s, j = 0; i < words.size(); i++) {
      t.replace(j, words[i].size(), words[i]);
      j += words[i].size() + 1;
    }
    ret.push_back(t);
    return ret;
  }
};

int main() {
  vector<string> words({"This", "is", "an", "example", "of", "text",
        "justification."});  // g++ -std=c++0x
  vector<string> r = Solution().fullJustify(words, 16);
  for (int i = 0; i < r.size(); i++)
    printf("%s$\n", r[i].c_str());
  return 0;
}
