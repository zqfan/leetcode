/* Copyright 2013 <ZhiQiang Fan>

   Given a string s, partition s such that every substring of the
   partition is a palindrome.
   Return the minimum cuts needed for a palindrome partitioning of s.
   For example, given s = "aab",
   Return 1 since the palindrome partitioning ["aa","b"] could be
   produced using 1 cut.
*/
#include <cstdio>
#include <cstring>
#include <string>
using std::string;

class Solution {
  public:
  // NOTE(zqfan): i read solution of wanyya@leetcode,
  // url:discuss.leetcode.com/questions/1266/palindrome-partitioning-ii
  // my origin solution is time limit exceed because it is O(N^3)
  int minCut(string s) {
    int len = s.size();
    // min[i] means min cut of s[i,end)
    // min[len] will be -1 since no such cut and avoid corner case
    // min[j+1]+1
    // NOTE(zqfan): the dynamic array is only supported in C99
    int min[len+1];
    for (int i = 0; i <= len; i++)
      min[i] = len-i-1;  // all part to single characters
    // p[i][j] means s[i,j] is palindrome string
    bool p[len][len];
    memset(p, 0, sizeof(p));
    for (int i = len-1; i >=0 ; i--) {
      for (int j = i; j < len; j++) {
        // s[i,j] is palindrome
        if (s[i] == s[j] && (j-i < 2 || p[i+1][j-1])) {
          p[i][j] = true;
          // 1. s[i,j] is palindrome and need one more cut besides
          // min[j+1], which stores min cut of s[j+1,end)
          // 2. if s[i,j] is not palindrome, for first palindrome of
          // s[i,j] end at k, then one candidate is min[k+1]+1
          // since k < j, it has already been compared before
          min[i] = std::min(min[i], min[j+1]+1);
        }
      }
    }
    return min[0];
  }
};

int main() {
  Solution s;
  printf("%d\n", s.minCut("aab"));
  return 0;
}
