/* Copyright 2013 <ZhiQiang Fan>

   Given a 2D board and a word, find if the word exists in the grid.

   The word can be constructed from letters of sequentially adjacent
   cell, where "adjacent" cells are those horizontally or vertically
   neighboring. The same letter cell may not be used more than once.

   For example,
   Given board =

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
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
  public:
  bool exist(vector<vector<char> > &board, string word) {
    // pos[i][0]=x and pos[i][1]=y means board[x][y]
    // pos[i][2]=z means word[z]
    vector<vector<int> > pos;
    vector<int> tmp_pos, new_pos;
    // path[i][j][0]=x and path[i][j][1]=y means board[x][y]
    // path[i] stores all previous path for pos[i]
    // For each step storing a board state is slower than this way
    // Both methods' worst case may down to O(n^4)
    vector<vector<vector<int> > > path;
    vector<vector<int> > tmp_path, new_path;
    int i, j, x, y, z;
    // direction, up, right, bottom, left
    int d[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // invalid input
    if (word.size() < 1)
      return false;

    // find the word[0] in board
    for (i = 0; i < board.size(); i++) {
      for (j = 0; j < board[i].size(); j++) {
        if (board[i][j] == word[0]) {
          tmp_pos.clear();
          tmp_pos.push_back(i);
          tmp_pos.push_back(j);
          // store this step of pos
          path.push_back(vector<vector<int> >(1, tmp_pos));
          // index of current word
          tmp_pos.push_back(0);
          pos.push_back(tmp_pos);
        }
      }
    }

    // there is a single character in board
    if (word.size() == 1)
      return path.size() != 0;

    while (pos.size() > 0) {
      tmp_pos = pos[pos.size()-1];
      tmp_path = path[path.size()-1];
      pos.pop_back();
      path.pop_back();
      for (i = 0; i < 4; i++) {
        x = tmp_pos[0] + d[i][0];
        y = tmp_pos[1] + d[i][1];
        z = tmp_pos[2] + 1;
        // x out of range
        if (x < 0 || x >= board.size())
          continue;
        // y out of range
        if (y < 0 || y >= board[0].size())
          continue;
        // a possible solution
        if (board[x][y] == word[z]) {
          // check the previous path to avoid duplicate
          for (j = 0; j < tmp_path.size(); j++) {
            if (x == tmp_path[j][0] && y == tmp_path[j][1])
              break;
          }
          // no duplicate
          if (j == tmp_path.size()) {
            // bingo
            if (z == word.size() - 1)
              return true;
            new_pos.clear();
            new_pos.push_back(x);
            new_pos.push_back(y);
            // copy it, oh my god
            new_path = tmp_path;
            // store new pos of path
            new_path.push_back(new_pos);
            new_pos.push_back(z);
            pos.push_back(new_pos);
            path.push_back(new_path);
          }  // end of if j == tmp_path.size()
        }  // end of if board[x][y] == word[z]
      }  // end of for i
    }  // end of while

    return false;
  }
};

int main() {
  char w[100];
  scanf("%s", w);
  char b[][4] = {{'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'},
                 {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'},
                 {'a', 'a', 'a', 'b'}};
  vector<vector<char> >board;
  for (int i = 0; i < sizeof(b)/sizeof(b[0]); i++)
    board.push_back(vector<char>(b[i],
                                 b[i] + sizeof(b[i])/sizeof(char)));
  Solution s;
  printf("%d\n", s.exist(board, string(w)));
  return 0;
}
