class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // @againest1
        int ones = 0, twos = 0;
        for ( int n : nums ) {
            ones = (ones ^ n) & (~twos);
            twos = (twos ^ n) & (~ones);
        }
        return ones;
    }
};
