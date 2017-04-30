class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum = { { 0, 1 } };
        int count = 0, sum = 0;
        for ( int n : nums ) {
            sum += n;
            count += presum[sum - k];
            ++presum[sum];
        }
        return count;
    }
};

// 80 / 80 test cases passed.
// Status: Accepted
// Runtime: 39 ms
