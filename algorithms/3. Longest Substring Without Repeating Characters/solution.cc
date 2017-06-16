class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastPos(256, -1);
        int result = 0, start = -1;
        for ( int i = 0, n = s.size(); i < n; ++i ) {
            start = max(start, lastPos[s[i]]);
            lastPos[s[i]] = i;
            result = max(result, i - start);
        }
        return result;
    }
};
