class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while ( true ) {
            int i = rand() % n;
            int count = 0;
            for ( int j = 0; j < n; ++j ) {
                if ( nums[i] == nums[j] ) {
                    ++count;
                }
            }
            if ( count > n / 2 ) {
                return nums[i];
            }
        }
    }
};

// 44 / 44 test cases passed.
// Status: Accepted
// Runtime: 19 ms
