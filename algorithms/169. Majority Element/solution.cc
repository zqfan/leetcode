class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        int m = nums.size() / 2;
        for ( int n : nums ) {
            if ( ++counter[n] > m ) {
                return n;
            }
        }
    }
};

// 44 / 44 test cases passed.
// Status: Accepted
// Runtime: 33 ms
