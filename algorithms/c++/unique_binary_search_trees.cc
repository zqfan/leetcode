/* Copyright 2013 <ZhiQiang Fan>

   Given n, how many structurally unique BST's (binary search trees)
   that store values 1...n?

   For example,
   Given n = 3, there are a total of 5 unique BST's.
*/
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  int numTrees(int n) {
    if (n <= 0)
      return 0;

    vector<int> status(n + 1, 0);
    int i, j;

    status[0] = 1;  // n == 0, has 1, just fake
    status[1] = 1;  // n == 1, has 1, it real
    for (i = 2; i <= n; i++) {
      // left side can be 0...n-1
      for (j = 0; j < i; j++)
        status[i] += status[j] * status[i - j - 1];
    }

    return status[n];
  }
};

int main() {
  int n;
  Solution s;
  scanf("%d", &n);
  printf("%d\n", s.numTrees(n));
  return 0;
}
