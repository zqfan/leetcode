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

Determine if a Sudoku is valid, according to:
Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are
filled with the character '.'.
*/
#include <cstdio>
#include <cstring>  // memset
#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
  public:
  bool isValidSudoku(const vector<vector<char> > &board) {
    bool r[9][9];  // numbers on each row
    bool c[9][9];  // numbers on each col
    bool g[3][3][9];  // numbers on each sub 9-grid
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int n = board[i][j] - '1';
          if (r[i][n] || c[j][n] || g[i/3][j/3][n])
            return false;
          r[i][n] = c[j][n] = g[i/3][j/3][n] = true;
        }
      }
    }
    return true;
  }
};

int main() {
  string str[] = {"1..", "456", "7.1"};
  vector<vector<char> > board;
  for (int i = 0; i < 3; i++)
    board.push_back(vector<char>(str[i].begin(), str[i].end()));
  Solution sol;
  printf("%d\n", sol.isValidSudoku(board));
  return 0;
}
