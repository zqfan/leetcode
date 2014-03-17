/* Given a string containing just the characters '(' and ')', find the
   length of the longest valid (well-formed) parentheses substring.

   For "(()", the longest valid parentheses substring is "()", which
   has length = 2.

   Another example is ")()())", where the longest valid parentheses
   substring is "()()", which has length = 4. */
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> istack;
    int i, cur, max;
    istack.push(0);
    cur = max = 0;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        istack.push(-1);
      } else if (istack.top() == -1) {
        istack.pop();
        istack.push(2);
      } else {
        cur = 0;
        while (!istack.empty() && istack.top() != -1) {
          cur += istack.top();
          istack.pop();
        }
        if (istack.empty()) {
          if (cur > max)
            max = cur;
          istack.push(0);
        } else {
          istack.pop();
          istack.push(cur + 2);
        }
      }
    }
    cur = 0;
    while (!istack.empty()) {
      if (istack.top() != -1)
        cur += istack.top();
      else
        cur = 0;
      if (cur > max)
        max = cur;
      istack.pop();
    }
    return max;
  }
};

int main() {
  Solution sol;
  string s;
  cin >> s;
  cout << sol.longestValidParentheses(s) << endl;
  return 0;
}
