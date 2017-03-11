/* Copyright 2013 <ZhiQiang Fan>

   Given a 2D board containing 'X' and 'O', capture all regions
   surrounded by 'X'.
   A region is captured by flipping all 'O's into 'X's in that
   surrounded region .
   For example,
   X X X X
   X O O X
   X X O X
   X O X X
   After running your function, the board should be:
   X X X X
   X X X X
   X X X X
   X O X X
*/
#include <cstdio>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
  public:
  void solve(vector<vector<char> > &board) {
    // If a 'O' is in the bound of board, itself and all connected
    // 'O' shall not be flipped, all other 'O's cannot connect to
    // bound 'O' should be flipped
    // If a 'O' can connect to bound, i will set it to 0, in the end
    // all element is 0 will set to 'O', other will be 'X'
    vector<int> pos_x;  // vector<vector<int> > pos
    vector<int> pos_y;
    int direction[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int i, j, x, y, xx, yy;

    if (board.size() < 1 || board[0].size() < 1)
      return;
    // check four bound
    for (j = 0; j < board[0].size(); j++) {
      if (board[0][j] == 'O') {
        board[0][j] = 0;
        pos_x.push_back(0);
        pos_y.push_back(j);
      }
      if (board.back()[j] == 'O') {
        board.back()[j] = 0;
        pos_x.push_back(board.size() - 1);
        pos_y.push_back(j);
      }
    }
    for (i = 0; i < board.size(); i++) {
      if (board[i][0] == 'O') {
        board[i][0] = 0;
        pos_x.push_back(i);
        pos_y.push_back(0);
      }
      if (board[i].back() == 'O') {
        board[i].back() = 0;
        pos_x.push_back(i);
        pos_y.push_back(board[i].size() - 1);
      }
    }
    // check all element can connect to bound
    while (!pos_x.empty()) {
      x = pos_x.back();
      pos_x.pop_back();
      y = pos_y.back();
      pos_y.pop_back();
      // check four direction
      for (i = 0; i < 4; i++) {
        xx = x + direction[i][0];
        yy = y + direction[i][1];
        if (xx < 0 || xx >= board.size())
          continue;
        if (yy < 0 || yy >= board[0].size())
          continue;
        if (board[xx][yy] == 'O') {
          board[xx][yy] = 0;
          pos_x.push_back(xx);
          pos_y.push_back(yy);
        }
      }
    }
    // flip region 'O' to 'X', which means set element not equal to 0
    // to 'X'
    for (i = 0; i < board.size(); i++) {
      for (j = 0; j < board[i].size(); j++) {
        if (board[i][j] != 0)
          board[i][j] = 'X';
        else
          board[i][j] = 'O';
      }
    }
  }
};

int main() {
  string c[] = {"XXXX", "XOOX", "XXOX", "XOXX"};
  vector<vector<char> > b;
  int i, j;
  for (i = 0; i < sizeof(c)/sizeof(c[0]); i++)
    b.push_back(vector<char>(c[i].begin(), c[i].end()));
  for (i = 0; i < b.size(); i++) {
    for (j = 0; j < b[i].size(); j++)
      printf("%c ", b[i][j]);
    printf("\n");
  }
  printf("after:\n");
  Solution().solve(b);
  for (i = 0; i < b.size(); i++) {
    for (j = 0; j < b[i].size(); j++)
      printf("%c ", b[i][j]);
    printf("\n");
  }
  return 0;
}
