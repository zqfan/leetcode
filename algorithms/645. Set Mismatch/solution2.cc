class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // @ hao-cai
        for ( int i = 0; i < nums.size(); ++i )
            while ( nums[i] != nums[nums[i] - 1] )
                swap(nums[i], nums[nums[i] - 1]);
        for ( int i = 0; i < nums.size(); ++i )
            if ( nums[i] != i + 1 )
                return {nums[i], i + 1};
    }
};

// 49 / 49 test cases passed.
// Status: Accepted
// Runtime: 39 ms
