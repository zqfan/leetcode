class Solution {
public:
    int longestPalindrome(string s) {
        int l = 0;
        unordered_map<int, int> counter;
        for ( char c : s ) {
            if ( counter[c] ) {
                l += 2;
                --counter[c];
            } else {
                ++counter[c];
            }
        }
        for ( auto & p : counter ) {
            if ( p.second ) {
                l += 1;
                break;
            }
        }
        return l;
    }
};

// 95 / 95 test cases passed.
// Status: Accepted
// Runtime: 6 ms
