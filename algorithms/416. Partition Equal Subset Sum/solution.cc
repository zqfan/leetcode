class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        bitset<10001> bits(1);
        for ( int n : nums ) bits |= bits << n;
        return ! (sum & 1) && bits[sum / 2];
    }
};
