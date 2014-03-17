/* Copyright 2013 <ZhiQiang Fan>

   Given a collection of integers that might contain duplicates, S,
   return all possible subsets.

   Note:

   Elements in a subset must be in non-descending order.
   The solution set must not contain duplicate subsets.

   For example,
   If S = [1,2,2], a solution is:
   [
   [2],
   [1],
   [1,2,2],
   [2,2],
   [1,2],
   []
   ]
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
  public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > result;
    vector<int> tmp;
    int start, end, i, j, k;

    // it is evil to modify input, but now i am Lucifer
    sort(S.begin(), S.end());

    // single element
    for (i = 0; i < S.size(); i++) {
      result.push_back(vector<int>(1, i));
      while (i + 1 < S.size() && S[i] == S[i + 1])
        i++;
    }

    end = 0;
    while (true) {
      start = end, end = result.size();
      if (start == end)
        break;
      for (i = start; i < end; i++) {
        tmp = result[i];
        k = tmp.back();
        tmp.push_back(0);
        for (j = k + 1; j < S.size(); j++) {
          tmp.back() = j;
          result.push_back(tmp);
          while (j + 1 < S.size() && S[j] == S[j + 1])
            j++;
        }
      }
    }

    for (i = 0; i < result.size(); i++)
      for (j = 0; j < result[i].size(); j++)
        result[i][j] = S[result[i][j]];

    // empty
    result.push_back(vector<int>());
    return result;
  }
};

int main() {
  int a[] = {1, 2, 2, 2};
  vector<int> S(a, a + sizeof(a)/sizeof(int));
  Solution s;
  vector<vector<int> > r = s.subsetsWithDup(S);
  int i, j;
  for (i = 0; i < r.size(); i++) {
    for (j = 0; j < r[i].size(); j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }
  return 0;
}
