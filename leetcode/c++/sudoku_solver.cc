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

Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.
*/
#include <cstdio>
#include <cstring>  // memset
#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
  public:
  void solveSudoku(vector<vector<char> > &board) {
    bool r[9][9];  // appearance of 1-9 in row 1-9
    bool c[9][9];  // appearance of 1-9 in col 1-9
    bool g[3][3][9];  // appearance of 1-9 in grid 1-9
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(g, 0, sizeof(g));
    // init r, c
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          r[i][board[i][j]-'1'] = true;
          c[j][board[i][j]-'1'] = true;
          g[i/3][j/3][board[i][j]-'1'] = true;
        }
      }
    }
    // using dfs to check each possible number
    _sudoku_dfs(board, 0, 0, r, c, g);
  }

  bool _sudoku_dfs(vector<vector<char> > & board, int i, int j,
                   bool r[9][9], bool c[9][9], bool g[3][3][9]) {
    int m, n, k;
    for (m = i; m < 9; m++) {
      for (n = m == i ? j : 0; n < 9; n++) {
        if (board[m][n] == '.') {
          //printf("m=%d,n=%d\n",m,n);
          for (k = 0; k < 9; k++) {
            if (!r[m][k] && !c[n][k] && !g[m/3][n/3][k]) {
              r[m][k] = c[n][k] = g[m/3][n/3][k] = true;
              board[m][n] = '1' + k;
              if (_sudoku_dfs(board, m, n, r, c, g))
                return true;
              board[m][n] = '.';
              r[m][k] = c[n][k] = g[m/3][n/3][k] = false;
            }
          }
          if (k == 9)  // no such number possible, dead
            return false;
        }
      }
    }
    return true;
  }
};

int main() {
  string str[] = {"53..7....", "6..195...", ".98....6.", "8...6...3",
                  "4..8.3..1", "7...2...6", ".6....28.", "...419..5",
                  "....8..79"};
  vector<vector<char> > b;
  int i, j;
  for (i = 0; i < 9; i++)
    b.push_back(vector<char>(str[i].begin(), str[i].end()));
  Solution s;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++)
      printf("%c ", b[i][j]);
    printf("\n");
  }
  s.solveSudoku(b);
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++)
      printf("%c ", b[i][j]);
    printf("\n");
  }
  return 0;
}
