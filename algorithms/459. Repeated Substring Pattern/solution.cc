class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        string t(ss.begin() + 1, ss.end() - 1);
        return t.find(s) != string::npos;
    }
};

// 107 / 107 test cases passed.
// Status: Accepted
// Runtime: 32 ms
// beats 79.23%
