class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0, end = 0, p = 1;
        for ( int start = 0; start < nums.size(); ++start ) {
            end = max(end, start);
            while ( end < nums.size() && p * nums[end] < k ) {
                p *= nums[end];
                ++end;
            }
            result += end - start;
            p /= nums[start];
        }
        return result;
    }
};

// 64 / 64 test cases passed.
// Status: Accepted
// Runtime: 93 ms
