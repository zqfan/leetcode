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

Given an unsorted array of integers, find the length of the longest
consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
length: 4.

Your algorithm should run in O(n) complexity.
*/
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::unordered_map;

class Solution {
  public:
  int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> hash;
    int len, i, left, right, max_len = 0;

    // if num.size() is very large, the built time of hash will larger
    // than O(n), because hash will recall hash function when increase
    // hash size, for small and medium size, it is fine
    for (i = 0; i < num.size(); i++)
      hash[num[i]] = 1;  // element is not counted yet

    for (i = 0; i < num.size(); i++) {
      if (hash[num[i]]) {
        len = 1;
        hash[num[i]] = 0;  // this element already been counted
        left = num[i] - 1;
        while (hash.find(left) != hash.end() && hash[left]) {
          len++;
          hash[left--] = 0;
        }
        right = num[i] + 1;
        while (hash.find(right) != hash.end() && hash[right]) {
          len++;
          hash[right++] = 0;
        }
        max_len = std::max(len, max_len);
      }
    }
    return max_len;
  }
};

int main() {
  int a[] = {100, 4, 200, 1, 3, 2};
  vector<int> num(a, a+sizeof(a)/sizeof(int));
  Solution s;
  printf("%d\n", s.longestConsecutive(num));
  return 0;
}
