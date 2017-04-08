class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// 34 / 34 test cases passed.
// Status: Accepted
// Runtime: 23 ms
