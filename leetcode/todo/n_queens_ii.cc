/* Copyright 2013 <ZhiQiang Fan>

   Follow up for N-Queens problem.

   Now, instead outputting board configurations, return the total
   number of distinct solutions.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <ctime>
using std::vector;
using std::stack;
using std::abs;

class Solution {
  public:
  int totalNQueens(int n) {
    vector<int> state(n, -1);  // state[i] = j, put queen on [i][j]
    int result = 0, i, j;

    if (n < 1)
      return 0;

    i = 0;
    while (i >= 0) {
      do {
        state[i]++;  // try next, for initial, try 0
        if (state[i] >= n)  // overflow, no solution for it
          break;
        // check it
        for (j = 0; j < i; j++) {
          if (state[i] == state[j] ||  // same col
              abs(i-j) == abs(state[i]-state[j]))  // diagonal
            break;
        }
        if (j == i)  // no conflict
          break;
      } while (true);
      if (state[i] >= n) {  // no solution
        state[i] = -1;
        i--;
      } else {
        if (i == n-1) {  // find a solution
          result++;  // to next loop, will start from next col
        } else  // try next row
          state[++i] = -1;
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
  int r = s.totalNQueens(n); // 10 = 724; 11 = 2680
  printf("%d\ntime=%d\n", r, (int)(time(0)-t));
  return 0;
}
