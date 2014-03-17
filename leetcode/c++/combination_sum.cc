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

Given a set of candidate numbers (C) and a target number (T), find all
unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of
times.

Note:
o All numbers (including target) will be positive integers.
o Elements in a combination (a1, a2, � , ak) must be in non-descending
  order. (ie, a1 ? a2 ? � ? ak).
o The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
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
    int i, j, t;

    // candidates are positive numbers
    if (target <= 0)
      return result;
    // check target already in candidates
    if (std::binary_search(candidates.begin() + pos,
                           candidates.end(), target))
      result.push_back(vector<int>(1, target));
    for (i = pos; i < candidates.size(); i++) {
      // avoid duplicate element
      while (i < candidates.size()  - 1 &&
             candidates[i] == candidates[i+1])
        i++;
      t = target - candidates[i];
      sub_result = this->_combination_sum(candidates, t, i);
      if (sub_result.empty())
        continue;
      for (j = 0; j < sub_result.size(); j++) {
        result.push_back(sub_result[j]);
        result.back().push_back(candidates[i]);
      }
    }

    return result;
  }

  vector<vector<int> > combinationSum(vector<int> &candidates,
                                      int target) {
    vector<vector<int> > result;
    // sort candidates for search, yes, i should not modify the input
    // but i am Lucifer, and currently, it does safe
    std::sort(candidates.begin(), candidates.end());
    result = this->_combination_sum(candidates, target, 0);
    for (int i = 0; i < result.size(); i++)
      std::reverse(result[i].begin(), result[i].end());
    return result;
  }
};

int main() {
  int n[] = {1, 2, 3, 6, 7};
  Solution s;
  vector<int> c(n, n+sizeof(n)/sizeof(int));
  vector<vector<int> > r = s.combinationSum(c, 7);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }
  return 0;
}
