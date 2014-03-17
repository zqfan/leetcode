/* Given a string containing just the characters '(', ')', '{', '}',
   '[' and ']', determine if the input string is valid.

   The brackets must close in the correct order, "()" and "()[]{}" are
   all valid but "(]" and "([)]" are not. */
#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> brackets;
    map<char, char> brackets_pair;
    int i;
    brackets_pair[')'] = '(';
    brackets_pair[']'] = '[';
    brackets_pair['}'] = '{';
    brackets.push(0);
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        brackets.push(s[i]);
      if (brackets_pair[s[i]] == brackets.top())
        brackets.pop();
      else if (brackets_pair[s[i]])
        return false;
    }
    return brackets.top() == 0;
  }
};

int main() {
  Solution sol;
  cout << sol.isValid(string("]")) << endl;
  return 0;
}
