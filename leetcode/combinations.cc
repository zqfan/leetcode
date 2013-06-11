/* Copyright 2013 <ZhiQiang Fan>

   Given two integers n and k, return all possible combinations of k
   numbers out of 1 ... n.

   For example,
   If n = 4 and k = 2, a solution is:

   [
   [2,4],
   [3,4],
   [2,3],
   [1,2],
   [1,3],
   [1,4],
   ]
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    vector<int> tmp;
    int i, j, len;

    // invalid input
    if (n < 1 || k > n || k < 1)
      return result;

    for (i = 1; i <= n - k + 1; i++)
      result.push_back(vector<int>(1, i));
    while (--k > 0) {
      len = result.size();
      for (i = 0; i < len; i++) {
        result[i].push_back(result[i].back() + 1);
        tmp = result[i];
        for (j = result[i].back() + 1; j <= n - k + 1; j++) {
          tmp.back() = j;
          result.push_back(tmp);
        }
      }
    }

    return result;
  }
};

int main() {
  int n, k;
  Solution s;
  scanf("%d %d", &n, &k);
  vector<vector<int> >r = s.combine(n, k);
  int i, j;
  for (i = 0; i < r.size(); i++) {
    for (j = 0; j < r[i].size(); j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }
  return 0;
}
