/* Copyright @013 <ZhiQiang Fan>

   Given an array of strings, return all groups of strings that are
   anagrams.

   Note: All inputs will be in lower-case.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using std::string;
using std::vector;
using std::sort;

class Solution {
  public:
  bool static cmp_sorted_str(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1.compare(s2) <= 0;
  }

  vector<string> anagrams(const vector<string> &strs) {
    vector<string> t = strs, r;
    string s1, s2;
    int i, j;

    if (strs.size() < 2)
      return r;

    sort(t.begin(), t.end(), this->cmp_sorted_str);

    for (i = 0; i + 1 < t.size(); i++) {
      s1 = t[i];
      sort(s1.begin(), s1.end());
      j = i + 1;
      while (j < t.size()) {
        s2 = t[j];
        sort(s2.begin(), s2.end());
        if (s1.compare(s2) == 0)
          r.push_back(t[j]);
        else
          break;
        j++;
      }
      if (j != i + 1) {
        r.push_back(t[i]);
        i = j - 1;
      }
    }

    return r;
  }
};

int main() {
  Solution sol;
  string s[] = {"123", "213", "324"};
  vector<string> strs;
  int i;
  for (i = 0; i < 3; i++)
    strs.push_back(s[i]);
  vector<string> r = sol.anagrams(strs);
  for (i = 0; i < r.size(); i++)
    printf("%s\n", r[i].c_str());
  return 0;
}
