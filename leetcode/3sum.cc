/* Copyright (C) 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

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
*/
/* Given an array S of n integers, are there elements a, b, c in S
   such that a + b + c = 0? Find all unique triplets in the array
   which gives the sum of zero.

   Note:
   Elements in a triplet (a,b,c) must be in non-descending order.
   (ie, a ? b ? c)
   The solution set must not contain duplicate triplets.

   For example, given array S = {-1 0 1 2 -1 -4},

   A solution set is:
   (-1, 0, 1)
   (-1, -1, 2)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> & num) {
    // a + b + c = 0 is equal to a + b = -c;
    // if num is sorted, and get a pair of number equal to a specific
    // number, costs O(N), so the search cost is O(N*N).
    // Accepted: 296ms
    vector<vector<int> > ret;
    // the modification of input is safe for this case
    std::sort(num.begin(), num.end());
    int i, j, k;
    for (i = 0; i < num.size(); i++) {
      j = i+1, k = num.size()-1;
      while (j < k) {
        int s = num[i]+num[j]+num[k];
        if (s == 0) {
          ret.push_back(vector<int>());
          ret.back().push_back(num[i]);
          ret.back().push_back(num[j]);
          ret.back().push_back(num[k]);
          // try next, and jump over duplicate elements
          while (++j < num.size() && num[j] == num[j-1]) {}
          while (--k >= 0 && num[k] == num[k+1]) {}
        } else if (s > 0) {  // we need to reduce num[j]+num[k]
          // reduce it by backward k since num is ascending
          // elements before j have already been tested.
          k--;
        } else {  // we need to increase num[j]+num[k]
          j++;
        }
      }
      // fast forward to next element not equal to num[i], to avoid
      // duplicated result. since all result start with num[i] has
      // already been found, it will not miss any result.
      while (i+1 < num.size() && num[i] == num[i+1])
        i++;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int a[] = {-1, 0, 1, 2, -1, -4};
  vector<int> num(a, a+sizeof(a)/sizeof(int));
  vector<vector<int> > r = sol.threeSum(num);
  for (int i = 0; i < r.size(); i++)
    printf("%d %d %d\n", r[i][0], r[i][1], r[i][2]);
  return 0;
}
