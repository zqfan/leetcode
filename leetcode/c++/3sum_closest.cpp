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
#include <numeric>
using std::vector;

class Solution {
  public:
  int threeSumClosest(vector<int> &num, int target) {
    int min, sum, i, j, t, d, dd;
    vector<int>::iterator p;

    if (num.size() < 4)
      return std::accumulate(num.begin(), num.end(), 0);
    // i am Lucifer, so i modify the input
    std::sort(num.begin(), num.end());
    sum = std::accumulate(num.begin(), num.begin()+3, 0);
    min = sum - target;
    for (i = 0; i < num.size() - 2; i++) {
      for (j = i + 1; j < num.size() - 1; j++) {
        // target number
        t = target - num[i] - num[j];
        // first larger than t
        p = std::upper_bound(num.begin()+j+1, num.end(), t);
        // distance
        if (p == num.end())
          p = num.end() - 1;
        d = target - (num[i] + num[j] + *p);
        // check the lower one's distance
        if (p - num.begin() > j + 1) {
          dd = target - (num[i] + num[j] + *(p-1));
          if (abs(dd) < abs(d)) {
            d = dd;
            p = p - 1;
          }
        }
        if (abs(d) < abs(min)) {
          min = d;
          sum = num[i] + num[j] + *p;
        }
      }
    }

    return sum;
  }
};

int main() {
  int n[] = {1, 1, 1, 1};
  vector<int> num(n, n+sizeof(n)/sizeof(int));
  Solution s;
  printf("%d\n", s.threeSumClosest(num, 4));
  return 0;
}
