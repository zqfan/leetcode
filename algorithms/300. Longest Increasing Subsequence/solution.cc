class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> minimals;
        for ( int n : nums ) {
            auto p = lower_bound(minimals.begin(), minimals.end(), n);
            if ( minimals.end() == p ) {
                minimals.push_back(n);
            } else {
                *p = n;
            }
        }
        return minimals.size();
    }
};
