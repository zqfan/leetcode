class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26);
        vector<int> last(26);
        for ( int i = 0; i < s.size(); ++i ) {
            ++count[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }
        int minIdx = s.size();
        for ( int i = 0; i < 26; ++i ) {
            if ( 1 == count[i] ) {
                minIdx = min(minIdx, last[i]);
            }
        }
        return minIdx == s.size() ? -1 : minIdx;
    }
};

// 104 / 104 test cases passed.
// Status: Accepted
// Runtime: 46 ms
