class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result = nums;
        for ( int i = result.size() - 1, j; i > 0; --i ) {
            j = rand() % (i + 1);
            swap(result[j], result[i]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
