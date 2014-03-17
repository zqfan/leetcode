/* Copyright 2013 <ZhiQiang Fan>

   The n-queens puzzle is the problem of placing n queens on an n�n
   chessboard such that no two queens attack each other.

   Given an integer n, return all distinct solutions to the n-queens
   puzzle.

   Each solution contains a distinct board configuration of the
   n-queens' placement, where 'Q' and '.' both indicate a queen and
   an empty space respectively.

   For example,
   There exist two distinct solutions to the 4-queens puzzle:

   [
   [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],

   ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
   ]
*/
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
using std::vector;
using std::string;
using std::stack;

class Solution {
  public:
  vector<vector<string> > solveNQueens(int n) {
    stack<int> rows;
    stack<vector<string> > states;
    vector<vector<string> > result;
    vector<string> state, next_state;
    int col, row, i, j;

    if (n < 1)
      return result;

    /*for (i = 0; i < n; i++) {
      states.push_back(string(n, '0'));
      }*/
    // push initial state
    states.push(vector<string>(n, string(n, '0')));
    rows.push(0);
    while (!states.empty()) {
      // get a indicator
      state = states.top();
      states.pop();
      row = rows.top();
      rows.pop();
      // check current state
      for (col = 0; col < n; col++) {
        // find a slot
        if (state[row][col] == '0') {
          // copy it to modify
          next_state = state;
          // set row to unavailable
          for (j = 0; j < n; j++)
            next_state[row][j] = '.';
          // set col to unavailable
          for (i = 0; i < n; i++)
            next_state[i][col] = '.';
          // put a queen
          next_state[row][col] = 'Q';
          // set 45 degree line to unavailable
          for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            next_state[i][j] = '.';
          // set 135 degree line to unavailable
          for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            next_state[i][j] = '.';
          // set 225 degree line to unavailable
          for (i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
            next_state[i][j] = '.';
          // set 315 degree line to unavailable
          for (i = row + 1, j = col + 1; i < n && j < n; i++, j++)
            next_state[i][j] = '.';
          // find a solution
          if (row == n - 1) {
            result.push_back(next_state);
          } else {
            // push cur state
            states.push(next_state);
            rows.push(row+1);
          }
        }  // end of if state[row][col] != '0'
      }  // end of for col 0->n
    }  // end of while stack.empty()
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<string> > r = s.solveNQueens(4);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      printf("%s\n", r[i][j].c_str());
    }
    printf("\n");
  }
  return 0;
}

