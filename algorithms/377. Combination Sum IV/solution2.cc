class Solution {
    map<int, int> mem;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if ( 0 == target ) {
            return 1;
        }
        if ( mem.find(target) != mem.end() ) {
            return mem[target];
        }
        int count = 0;
        for ( int n : nums ) {
            if ( target >= n ) {
                count += combinationSum4(nums, target - n);
            }
        }
        return mem[target] = count;
    }
};

// 17 / 17 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 5.28 %
