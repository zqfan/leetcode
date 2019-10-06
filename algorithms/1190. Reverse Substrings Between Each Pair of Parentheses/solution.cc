class Solution {
public:
    string reverseParentheses(string s) {
        // by lee215
        vector<int> stack, pairIndex(s.length());
        for (int i = 0; i < s.length(); ++i) {
            if ('(' == s[i]) {
                stack.push_back(i);
            } else if (')' == s[i]) {
                int j = stack.back();
                stack.pop_back();
                pairIndex[i] = j;
                pairIndex[j] = i;
            }
        }
        string result;
        for (int i = 0, d = 1; i < s.length(); i += d) {
            if ('(' == s[i] || ')' == s[i]) {
                i = pairIndex[i];
                d = -d;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};
