class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letters(26);
        for ( char c : s ) {
            ++letters[c - 'a'];
        }
        for ( char c : t ) {
            --letters[c - 'a'];
        }
        for ( int c : letters ) {
            if ( c ) {
                return false;
            }
        }
        return true;
    }
};

// 34 / 34 test cases passed.
// Status: Accepted
// Runtime: 13 ms
