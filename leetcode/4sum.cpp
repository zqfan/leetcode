/* Given an array S of n integers, are there elements a, b, c, and d
   in S such that a + b + c + d = target? Find all unique quadruplets
   in the array which gives the sum of target. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  // O(n^3)
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > r;
    int i, j, k, l;
    sort(num.begin(), num.end());
    for (i = 0; i < num.size();i++) {
      for (j = i + 1; j < num.size();j++) {
        for (k = j + 1, l = num.size() - 1; k < l;) {
          if (num[i] + num[j] + num[k] + num[l] == target) {
            vector<int> tmp;
            tmp.push_back(num[i]);
            tmp.push_back(num[j]);
            tmp.push_back(num[k]);
            tmp.push_back(num[l]);
            r.push_back(tmp);
            // remove duplicate
            while (k < --l && num[l] == num[l+1]);
          }
          while (k < l && num[k] + num[l] < target - num[i] - num[j])
            k++;
          while (k < l && num[k] + num[l] > target - num[i] - num[j])
            l--;
        } // end for k
        // remove duplicate
        while (j < num.size() && num[j] == num[j+1])
          j++;
      } // end for j
      // remove duplicate
      while (i < num.size() && num[i] == num[i+1])
        i++;
    } // end for i
    return r;
  }
};

int main() {
  int a[] = {1, 1, 2, 2, 3, 3, 4, 4};
  vector<int> num(a, a+sizeof(a)/sizeof(int));
  Solution sol;
  vector<vector<int> > r = sol.fourSum(num, 10);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < 4; j++)
      cout << r[i][j] << " ";
    cout << endl;
  }
  return 0;
}
