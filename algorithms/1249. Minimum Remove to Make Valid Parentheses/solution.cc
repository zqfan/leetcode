class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // we can modify s because it is not a reference
        // learn from @votrubac
        std::stack<int> pindex;
        for (int i = 0; i < s.size(); ++i) {
            if ('(' == s[i]) {
                pindex.push(i);
            } else if (')' == s[i]) {
                if (pindex.empty()) {
                    s[i] = '.';
                } else {
                    pindex.pop();
                }
            }
        }
        while (pindex.size()) {
            s[pindex.top()] = '.';
            pindex.pop();
        }
        s.erase(remove(s.begin(), s.end(), '.'), s.end());
        return s;
    }
};

// Runtime: 24 ms, faster than 95.00% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
