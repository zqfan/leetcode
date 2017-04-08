class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, count = 0;
        for ( int n : nums ) {
            if ( count == 0 ) {
                major = n;
                count = 1;
            } else if ( n == major ) {
                ++count;
            } else {
                --count;
            }
        }
        return major;
    }
};

// 44 / 44 test cases passed.
// Status: Accepted
// Runtime: 19 ms
