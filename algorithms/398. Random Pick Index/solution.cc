class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int idx;
        int count = 1;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( target == nums.at(i) ) {
                if ( rand() % count == 0 ) {
                    idx = i;
                }
                count += 1;
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
