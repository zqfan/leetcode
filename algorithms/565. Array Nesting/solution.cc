class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), maxlen = 0, cur;
        vector<bool> visited(n, false);
        for ( int i = 0, j; i < n; ++i ) {
            if ( ! visited[i] ) {
                cur = 0;
                j = i;
                while ( ! visited[j] ) {
                    visited[j] = true;
                    j = nums[j];
                    ++cur;
                }
                maxlen = max(maxlen, cur);
            }
        }
        return maxlen;
    }
};
