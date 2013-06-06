/* Copyright 2013 <ZhiQiang Fan>

   Given a collection of numbers that might contain duplicates, return
   all possible unique permutations.

   For example,
   [1,1,2] have the following unique permutations:
   [1,1,2], [1,2,1], and [2,1,1].
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
  public:
  /* we just sort num and ignore the duplicated numbers */
  vector<vector<int> > permuteUnique(const vector<int> &num) {
    vector<vector<int> > r, rr;
    vector<int> n, t;
    int i, j;

    if (num.size() == 1) {
      r.push_back(num);
      return r;
    }

    n = num;
    sort(n.begin(), n.end());

    for (i = 0; i < n.size(); i++) {
      t = n;
      t.erase(t.begin() + i);
      rr = this->permuteUnique(t);
      for (j = 0; j < rr.size(); j++) {
        rr[j].push_back(n[i]);
        r.push_back(rr[j]);
      }
      // ignore the duplicated numbers
      while (i + 1 < n.size() && n[i] == n[i + 1])
        i++;
    }

    return r;
  }
};

int main() {
  Solution s;
  int n[] = {1, 2, 1};
  vector<int> num(n, n + sizeof(n)/sizeof(int));
  vector<vector<int> > r = s.permuteUnique(num);
  int i, j;
  for (i = 0; i < r.size(); i++) {
    for (j = 0; j < r[i].size(); j++) {
      printf("%d ", r[i][j]);
    }
    printf("\n");
  }
  return 0;
}
