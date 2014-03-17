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

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number
of distinct solutions.
*/
#include <cstdio>
#include <cstring>  // memset
#include <algorithm>
#include <vector>
#include <stack>
#include <ctime>
using std::vector;
using std::stack;
using std::abs;

class Solution {
  public:
  // very slow, for n = 12, nearly cost 900ms
  int totalNQueens(int n) {
    if (n < 1) return 0;
    vector<int> state(n, -1);  // state[i] = j, put queen on [i][j]
    bool used_col[n];  // c99 style
    memset(used_col, 0, sizeof(used_col));
    int diagonal[n][n];  // diagonal conflict, c99 style
    memset(diagonal, 0, sizeof(diagonal));
    int result = 0, i = 0, j;
    while (i >= 0) {
      do {
        state[i]++;  // try next, for initial, try 0
        if (state[i] >= n)  // overflow, no solution for it
          break;
        if (used_col[state[i]] || diagonal[i][state[i]])
          continue;
        else
          break;
      } while (true);
      if (state[i] >= n) {  // no solution
        state[i] = -1;
        i--;
        if (i < 0) return result;
        used_col[state[i]] = false;
        for (j = 1; i+j < n && state[i]+j < n; j++)
          diagonal[i+j][state[i]+j]--;
        for (j = 1; i+j < n && state[i]-j >= 0; j++)
          diagonal[i+j][state[i]-j]--;
      } else {
        if (i == n-1) {  // find a solution
          result++;  // to next loop, will start from next col
        } else  {  // try next row
          used_col[state[i]] = true;
          for (j = 1; i+j < n && state[i]+j < n; j++)
            diagonal[i+j][state[i]+j]++;
          for (j = 1; i+j < n && state[i]-j >= 0; j++)
            diagonal[i+j][state[i]-j]++;
          state[++i] = -1;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n;
  scanf("%d", &n);
  time_t t = time(0);
  int r = s.totalNQueens(n);  // 10 = 724; 11 = 2680; 12 = 14200
  printf("%d\ntime=%d\n", r, static_cast<int>(time(0)-t));
  return 0;
}
