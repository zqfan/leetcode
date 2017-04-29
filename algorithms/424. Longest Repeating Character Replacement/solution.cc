class Solution {
public:
    int characterReplacement(string s, int k) {
        int i, j, counter[26] = { 0 };
        for ( i = 0, j = 0; j < s.size(); ++j ) {
            ++counter[s[j] - 'A'];
            int major = *max_element(counter, counter + 26);
            if ( j - i + 1 - major > k) {
                --counter[s[i] - 'A'];
                ++i;
            }
        }
        return j - i;
    }
};

// 37 / 37 test cases passed.
// Status: Accepted
// Runtime: 19 ms
// beats 34.54 %
