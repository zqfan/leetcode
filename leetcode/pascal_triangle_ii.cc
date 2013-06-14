/* Copyright 2013 <ZhiQiang Fan>

   Given an index k, return the kth row of the Pascal's triangle.
   For example, given k = 3,
   Return [1,3,3,1].
   Note:
   Could you optimize your algorithm to use only O(k) extra space?
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  vector<int> getRow(int rowIndex) {
    vector<int> result;
    int i, j;

    if (rowIndex < 0)
      return result;

    result = vector<int>(rowIndex+1, 0);
    result[0] = 1;
    for (i = 1; i <= rowIndex; i++) {
      result[i] = 1;
      for (j = i - 1; j > 0; j--) {
        result[j] = result[j] + result[j-1];
      }
    }

    return result;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> r = Solution().getRow(n);
  for (int i = 0; i < r.size(); i++)
    printf("%d ", r[i]);
  printf("\n");
  return 0;
}
