class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> firstIndex;
        firstIndex[0] = -1;
        int diff = 0, ml = 0;
        for ( int i = 0, n = nums.size(); i < n; ++i ) {
            diff += nums[i] ? 1 : -1;
            if ( firstIndex.find(diff) == firstIndex.end() ) {
                firstIndex[diff] = i;
            }
            ml = max(ml, i - firstIndex[diff]);
        }
        return ml;
    }
};
