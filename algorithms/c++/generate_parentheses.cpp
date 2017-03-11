/* Given n pairs of parentheses, write a function to generate all
   combinations of well-formed parentheses.

   For example, given n = 3, a solution set is:
   "((()))", "(()())", "(())()", "()(())", "()()()" */
/* This one seems appear in cracking the coding interview */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    vector<int> c;
    stack<vector<int> > paren_count;
    stack<string> paren_str;
    string p;

    if (n <= 0)
      return result;
    paren_count.push(vector<int>(2, n));
    paren_str.push(string(""));
    while (!paren_count.empty()) {
      c = paren_count.top();
      p = paren_str.top();
      paren_count.pop();
      paren_str.pop();
      // all left and right paren are inserted
      if (c[0] == 0 && c[1] == 0) {
        result.push_back(p);
      }
      // there is a left paren can be inserted
      if (c[0] > 0 && c[1] >= c[0]) {
        c[0]--;
        paren_count.push(c);
        c[0]++;
        paren_str.push(p + "(");
      }
      // there is a right paren can be inserted
      if (c[0] >= 0 && c[1] > c[0]) {
        c[1]--;
        paren_count.push(c);
        paren_str.push(p + ")");
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<string> r = sol.generateParenthesis(4);
  for (int i = 0; i < r.size(); i++)
    cout << r[i] << endl;
  return 0;
}
