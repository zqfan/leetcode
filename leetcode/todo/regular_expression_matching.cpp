/* Implement regular expression matching with support for '.' and '*'.
 */
#include "iostream"
using namespace std;

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    return false;
  }
};

int main() {
  string s, p;
  cin >> s >> p;
  Solution sol;
  cout << sol.isMatch(s.c_str(), p.c_str()) << endl;
  return 0;
}
