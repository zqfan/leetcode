class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = * min_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum - min * nums.size();
    }
};
