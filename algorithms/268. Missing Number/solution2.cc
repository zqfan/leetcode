class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // in case overflow
        double sum = accumulate(nums.begin(), nums.end(), 0.0d);
        double n = nums.size();
        return n * (n + 1) / 2 - sum;
    }
};

// 121 / 121 test cases passed.
// Status: Accepted
// Runtime: 39 ms
