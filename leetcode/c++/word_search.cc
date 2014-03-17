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

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent
cell, where "adjacent" cells are those horizontally or vertically
neighboring. The same letter cell may not be used more than once.

For example, Given board =
[
["ABCE"],
["SFCS"],
["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include <cstdio>
#include <cstring>  // memset
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
  public:
  bool exist(vector<vector<char> > &board, string word) {
    int r = board.size();
    if (r == 0) return false;  // avoid board[0] error
    int c = board[0].size();
    if (c == 0) return false;
    int n = word.size();
    if (n == 0 || n > r*c) return false;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        // check each element
        if (_exist_dfs(board, i, j, word.c_str(), 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool _exist_dfs(vector<vector<char> > &board, int i, int j,
                  const char * word, int index) {
    if (word[index] == '\0') return true;  // reach the end
    if (i < 0 || i >= board.size()) return false;  // out of bound
    if (j < 0 || j >= board[0].size()) return false;
    if (board[i][j] != word[index]) return false;  // not match
    char c = board[i][j];  // i modify the input but i will recover it
    board[i][j] = 0;  // mark visited
    // short circuit calculation will do some prune
    bool neighbour = _exist_dfs(board, i-1, j, word, index+1) ||
      _exist_dfs(board, i, j+1, word, index+1) ||
      _exist_dfs(board, i+1, j, word, index+1) ||
      _exist_dfs(board, i, j-1, word, index+1);
    board[i][j] = c;  // recover now for next recursive
    return neighbour;
  }
};

int main() {
  string str[] = {"ABCE", "SFCS", "ADEE"};
  vector<vector<char> > board;
  for (int i = 0; i < 3; i++)
    board.push_back(vector<char>(str[i].begin(), str[i].end()));
  Solution s;
  string w("ABCCED");
  printf("%d\n", s.exist(board, string(w)));
  return 0;
}
