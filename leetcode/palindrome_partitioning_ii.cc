/* Copyright 2013 <ZhiQiang Fan>

   Given a string s, partition s such that every substring of the
   partition is a palindrome.
   Return the minimum cuts needed for a palindrome partitioning of s.
   For example, given s = "aab",
   Return 1 since the palindrome partitioning ["aa","b"] could be
   produced using 1 cut.
*/
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using std::string;
using std::vector;
using std::queue;

class Solution {
  public:
  // check a string is palindrome or not
  bool _is_palindrome(const string &s, int i, int j) {
    for (; i < j; i++, j--)
      if (s[i] != s[j])
        return false;
    return true;
  }

  int minCut(string s) {
    if (s.size() == 0 || _is_palindrome(s, 0, s.size()-1))
      return 0;
    int i, j;
    vector<vector<bool> > p(s.size(), vector<bool>(s.size(), false));
    // make cache for substr palindrome check
    for (i = 0; i < s.size(); i++) {
      for (j = i; j < s.size(); j++) {
        p[i][j] = _is_palindrome(s, i, j);
      }
    }
    // cut[i][j] means min cut for s[i..j]
    vector<vector<int> > cut(s.size(), vector<int>(s.size(), 0));
    for (i = 1; i < s.size(); i++) {
      for (j = 0; j < s.size() - i; j++) {
        // is already palindrome
        // NOTE, if there is memory limit, you can drop the cache p
        // and directly call _is_palindrome(s, j, j+i), but time will
        // increase by n
        if (p[j][j+i]) {
          cut[j][j+i] = 0;
          continue;
        }
        // cut from some pos between j and j+i, the new cut is
        // left + 1 + right
        int min = i;
        for (int k = j; k < j+i; k++) {
          int _min = cut[j][k] + cut[k+1][j+i] + 1;
          if (_min < min)
            min = _min;
          if (min == 1)
            break;
        }
        cut[j][j+i] = min;
      }
    }
    return cut[0][s.size()-1];
  }
};

int main() {
  Solution s;
  printf("%d\n", s.minCut("aab"));
  return 0;
}
