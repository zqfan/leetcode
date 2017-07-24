class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> counter(n + 1);
        int expect = n * (n + 1) / 2;
        int actual = accumulate(nums.begin(), nums.end(), 0);
        for ( int i : nums ) {
            if ( 1 == counter[i] )
                return {i, expect - actual + i};
            ++counter[i];
        }
    }
};
