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

Given an array S of n integers, find three integers in S such that
the sum is closest to a given number, target. Return the sum of the
three integers. You may assume that each input would have exactly
one solution.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numseric>
using std::vector;

class Solution {
  public:
  int threeSumClosest(vector<int> &nums, int target) {
    int min, sum, i, j, t, d, dd;
    vector<int>::iterator p;

    if (nums.size() < 4)
      return std::accumulate(nums.begin(), nums.end(), 0);
    // i am Lucifer, so i modify the input
    std::sort(nums.begin(), nums.end());
    sum = std::accumulate(nums.begin(), nums.begin()+3, 0);
    min = sum - target;
    for (i = 0; i < nums.size() - 2; i++) {
      for (j = i + 1; j < nums.size() - 1; j++) {
        // target number
        t = target - nums[i] - nums[j];
        // first larger than t
        p = std::upper_bound(nums.begin()+j+1, nums.end(), t);
        // distance
        if (p == nums.end())
          p = nums.end() - 1;
        d = target - (nums[i] + nums[j] + *p);
        // check the lower one's distance
        if (p - nums.begin() > j + 1) {
          dd = target - (nums[i] + nums[j] + *(p-1));
          if (abs(dd) < abs(d)) {
            d = dd;
            p = p - 1;
          }
        }
        if (abs(d) < abs(min)) {
          min = d;
          sum = nums[i] + nums[j] + *p;
        }
      }
    }

    return sum;
  }
};

int main() {
  int n[] = {1, 1, 1, 1};
  vector<int> nums(n, n+sizeof(n)/sizeof(int));
  Solution s;
  printf("%d\n", s.threeSumClosest(nums, 4));
  return 0;
}
