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
   (-1, -1, 2) */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    // a + b + c = 0 is equal to a + b = -c;
    // if num is sorted, and get a pair of number equal to a specific
    // number, costs O(N), so the search cost is O(N*N)
    // to remove duplicate answer, it should be at least cost O(M)
    // however, M will not larger than N, so entire cost O(N*N*N)
    int i, j, k, m;
    vector<vector<int> > r; // result
    // NOTE(zqfan): this has changed num, in practice, is evil
    sort(num.begin(), num.end());
    for (i = 0; i < num.size(); i++) {
      for (j = 0, k = num.size() - 1; j < k; ) {
        // ignore same elements
        if (i == j) {
          j++;
          // it must continue, to check j < k;
          continue;
        }
        if (i == k) {
          k--;
          continue;
        }
        // find a + b == -c
        if (num[j] + num[k] == 0 - num[i]) {
          vector<int> tmp;
          tmp.push_back(num[i]);
          tmp.push_back(num[j]);
          tmp.push_back(num[k]);
          // ensure increasing order
          sort(tmp.begin(), tmp.end());
          // check if there is duplicate
          for (m = 0; m < r.size(); m++) {
            if (r[m][0] == tmp[0] &&
                r[m][1] == tmp[1] &&
                r[m][2] == tmp[2])
              break;
          }
          if (m == r.size())
            r.push_back(tmp);
          // check next,
          j++;
          k--;
        }
        while (j < k && num[j] + num[k] < 0 - num[i])
          j++;
        while (j < k && num[j] + num[k] > 0 - num[i])
          k--;
      } // end for j
    } // end for i
    return r;
  }
};

int main() {
  Solution sol;
  int a[] = {0, 0, 0};
  vector<int> num(a, a+sizeof(a)/sizeof(int));
  vector<vector<int> > r = sol.threeSum(num);
  for (int i = 0; i < r.size(); i++)
    cout << r[i][0] << " " << r[i][1] << " " << r[i][2] << endl;
  return 0;
}
