/* Copyright 2013 <ZhiQiang Fan>

   Determine if a Sudoku is valid, according to:
   Sudoku Puzzles - The Rules.

   The Sudoku board could be partially filled, where empty cells are
   filled with the character '.'.
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  bool isValidSudoku(const vector<vector<char> > &board) {
    vector<int> flag(10, 0);
    int i, j, k, l, m;

    // check each row
    for (i = 0; i < board.size(); i++) {
      for (m = 0; m < flag.size(); m++)  // clear flag vector
        flag[m] = 0;
      for (j = 0; j < board[i].size(); j++) {
        if (board[i][j] != '.') {
          flag[board[i][j] - '0']++;
        }
      }
      for (m = 0; m < flag.size(); m++)  // check flag vector
        if (flag[m] > 1)
          return false;
    }  // end for i
    // check each col
    for (j = 0; j < board[0].size(); j++) {
      for (m = 0; m < flag.size(); m++)  // clear flag vector
        flag[m] = 0;
      for (i = 0; i < board.size(); i++) {
        if (board[i][j] != '.') {
          flag[board[i][j] - '0']++;
        }
      }
      for (m = 0; m < flag.size(); m++)  // check flag vector
        if (flag[m] > 1)
          return false;
    }  // end for i
    // check each sub block
    for (i = 0; i < board.size(); i += 3) {
      for (j = 0; j < board[0].size(); j += 3) {
        for (m = 0; m < flag.size(); m++)  // clear flag vector
          flag[m] = 0;
        for (k = i; k < i + 3; k++) {
          for (l = j; l < j + 3; l++) {
            if (board[k][l] != '.')
              flag[board[k][l] - '0']++;
          }
        }
        for (m = 0; m < flag.size(); m++)  // check flag vector
          if (flag[m] > 1)
            return false;
      }  // end for j
    }  // end for i
    return true;
  }
};

int main() {
  int a[3][3] = {{'1', '2', '3'},
                 {'4', '5', '6'},
                 {'7', '8', '9'}};
  vector<char> b1;
  b1.push_back('1'); b1.push_back('.'); b1.push_back('.');
  vector<char> b2;
  b2.push_back('4'); b2.push_back('5'); b2.push_back('6');
  vector<char> b3;
  b3.push_back('7'); b3.push_back('.'); b3.push_back('1');
  vector<vector<char> > board;
  board.push_back(b1);
  board.push_back(b2);
  board.push_back(b3);
  Solution sol;
  printf("%d\n", sol.isValidSudoku(board));
  return 0;
}
