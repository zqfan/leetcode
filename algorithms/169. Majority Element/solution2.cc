class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        return nums[m];
    }
};

// 44 / 44 test cases passed.
// Status: Accepted
// Runtime: 19 ms
