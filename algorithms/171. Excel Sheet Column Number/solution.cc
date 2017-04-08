class Solution {
public:
    int titleToNumber(string s) {
        int n = 0;
        for ( char c : s ) {
            n = n * 26 + c - 'A' + 1;
        }
        return n;
    }
};

// 1000 / 1000 test cases passed.
// Status: Accepted
// Runtime: 6 ms
