class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = 0;
        for ( int i = 0; i < nums.size(); ++i ) {
            miss ^= nums[i];
            miss ^= i;
        }
        return miss ^ nums.size();
    }
};

// 121 / 121 test cases passed.
// Status: Accepted
// Runtime: 33 ms
