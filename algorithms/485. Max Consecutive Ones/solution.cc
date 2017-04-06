class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, curLen = 0;
        for ( int bit : nums ) {
            if ( !bit ) {
                curLen = 0;
            } else {
                curLen++;
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};
