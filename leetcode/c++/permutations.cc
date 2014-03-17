/* Copyright 2013 <ZhiQiang Fan>

   Given a collection of numbers, return all possible permutations.

   For example,
   [1,2,3] have the following permutations:
   [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  vector<vector<int> > permute(const vector<int> &num) {
    vector<vector<int> > r, rr;
    vector<int> t;
    int i, j;

    if (num.size() == 1) {
      r.push_back(num);
      return r;
    }

    for (i = 0; i < num.size(); i++) {
      t = num;
      t.erase(t.begin() + i);
      rr = this->permute(t);
      for (j = 0; j < rr.size(); j++) {
        rr[j].push_back(num[i]);
        r.push_back(rr[j]);
      }
    }

    return r;
  }
};

int main() {
  Solution s;
  int n[] = {1, 2, 3, 4, 5, 6, 7};
  vector<int> num(n, n + sizeof(n)/sizeof(int));
  vector<vector<int> > r = s.permute(num);
  int i, j;
  for (i = 0; i < r.size(); i++) {
    for (j = 0; j < r[i].size(); j++) {
      printf("%d ", r[i][j]);
    }
    printf("\n");
  }
  return 0;
}
