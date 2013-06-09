/* Copyright 2013 <ZhiQiang Fan>

   The set [1,2,3,…,n] contains a total of n! unique permutations.

   By listing and labeling all of the permutations in order,
   We get the following sequence (ie, for n = 3):

   "123"
   "132"
   "213"
   "231"
   "312"
   "321"
   Given n and k, return the kth permutation sequence.

   Note: Given n will be between 1 and 9 inclusive.
*/
#include <cstdio>
#include <string>
using std::string;

class Solution {
  public:
  string getPermutation(int n, int k) {
    string result;
    int a[9] = {0};
    int p[10] = {1};
    int i, j, nn = n;

    for (i = 1; i < 10; i++)
      p[i] = p[i-1] * i;

    // invalid input
    if (n < 1 || n > 9 || k > p[n])
      return result;

    while (k > 0 && result.size() < n) {
      j = (k - 1)/ p[--nn];
      k -= j * p[nn];
      for (i = 0; i < 9; i++) {
        if (!a[i])
          j--;
        if (j < 0)
          break;
      }
      a[i] = 1;
      result += string(1, i + '1');
    }

    return result;
  }
};

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  Solution s;
  printf("%s\n", s.getPermutation(n, k).c_str());
  return 0;
}
