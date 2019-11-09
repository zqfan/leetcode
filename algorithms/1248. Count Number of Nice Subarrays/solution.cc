class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] & 1;
            result += m[sum - k];
            ++m[sum];
        }
        return result;
    }
};
