/* Copyright 2013 <ZhiQiang Fan>

   Given numRows, generate the first numRows of Pascal's triangle.
   For example, given numRows = 5,
   Return
   [
   [1],
   [1,1],
   [1,2,1],
   [1,3,3,1],
   [1,4,6,4,1]
   ]
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result;
    int i, j;

    if (numRows < 1)
      return result;

    result.push_back(vector<int>(1, 1));
    for (i = 0; i < numRows - 1; i++) {
      result.push_back(vector<int>());
      result.back().push_back(result[i][0]);
      for (j = 0; j < i; j++) {
        result.back().push_back(result[i][j] + result[i][j+1]);
      }
      result.back().push_back(result[i].back());
    }

    return result;
  }
};

int main() {
  vector<vector<int> > r = Solution().generate(5);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }
  return 0;
}
