/*
Copyright 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

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

Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to
T.

Each number in C may only be used once in the combination.

Note:

o All numbers (including target) will be positive integers.
o Elements in a combination (a1, a2, � , ak) must be in
  non-descending order. (ie, a1 ? a2 ? � ? ak).
o The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
  public:
  // worst case O(N*MlogM), N=target, M=candidates.size
  // pos is to avoid duplicate combination, since candidates is sorted
  // i just need to scan [pos,last)
  vector<vector<int> > _combination_sum(const vector<int> &candidates,
                                        int target, int pos) {
    vector<vector<int> > result;
    vector<vector<int> > sub_result;
    int i, j, t, d;

    // candidates are positive numbers
    if (target <= 0)
      return result;
    // check target already in candidates
    if (std::binary_search(candidates.begin() + pos + 1,
                           candidates.end(), target))
      result.push_back(vector<int>(1, target));
    // since this is not allowed candidate to be used multiple times
    // start pos should be previous + 1
    for (i = pos + 1; i < candidates.size(); i++) {
      // get duplicate element right bound
      d = i;
      while (d < candidates.size()-1 &&
             candidates[d] == candidates[d+1])
        d++;
      t = target - candidates[i];
      // i can not directly jump to d, because duplicate element can
      // be used, just single element cannot use duplicate times
      sub_result = this->_combination_sum(candidates, t, i);
      if (sub_result.empty())
        continue;
      for (j = 0; j < sub_result.size(); j++) {
        result.push_back(sub_result[j]);
        result.back().push_back(candidates[i]);
      }
      // jump over duplicate element, to avoid duplicate result
      i = d;
    }

    return result;
  }

  vector<vector<int> > combinationSum2(vector<int> &candidates,
                                      int target) {
    vector<vector<int> > result;
    // sort candidates for search, yes, i should not modify the input
    // but i am Lucifer, and currently, it does safe
    std::sort(candidates.begin(), candidates.end());
    result = this->_combination_sum(candidates, target, -1);
    for (int i = 0; i < result.size(); i++)
      std::reverse(result[i].begin(), result[i].end());
    return result;
  }
};

int main() {
  int n[] = {10, 1, 2, 7, 6, 1, 5};
  Solution s;
  vector<int> c(n, n+sizeof(n)/sizeof(int));
  vector<vector<int> > r = s.combinationSum2(c, 8);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }
  return 0;
}
