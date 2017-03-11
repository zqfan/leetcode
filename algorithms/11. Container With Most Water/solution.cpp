/* Given n non-negative integers a1, a2, ..., an, where each
   represents a point at coordinate (i, ai). n vertical lines are
   drawn such that the two endpoints of line i is at (i, ai) and
   (i, 0). Find two lines, which together with x-axis forms a
   container, such that the container contains the most water.

   Note: You may not slant the container. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    /* sort height, keep their index info
       for example, height = [4, 6, 5], after sort, [4, 5, 6],
       4 doesn't need to know which one it with to form a container,
       it just need to know the left and the right bound, so the max
       area for 4 is 4 * max(abs(1 - 2), abs(1 - 3))
    */
    int i, left, right, area, max_area = 0;
    vector< vector<int> > hi; // height, index
    for (i = 0; i < height.size(); i++) {
      vector<int> tmp;
      tmp.push_back(height[i]);
      tmp.push_back(i);
      hi.push_back(tmp);
    }
    // sort by increasing order
    sort(hi.begin(), hi.end());
    left = right = hi[hi.size() - 1][1];
    for (i = hi.size() - 2; i >= 0; i--) {
      // abs is necessary because i can be out of range of
      // [left, right]
      area = hi[i][0] * max(abs(hi[i][1] - left),
                            abs(hi[i][1] - right));
      if (area > max_area)
        max_area = area;
      // update the left and right bound
      left = hi[i][1] < left ? hi[i][1] : left;
      right = hi[i][1] > right ? hi[i][1] : right;
    }
    return max_area;
  }
};

int main() {
  int a[] = {1, 2};
  vector<int> hs(a, a + sizeof(a)/sizeof(int));
  Solution sol;
  cout << sol.maxArea(hs) << endl;
  return 0;
}
