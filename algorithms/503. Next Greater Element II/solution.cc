class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> s;
        for ( int i = 0, n = nums.size() ; i < 2 * n; ++i ) {
            while ( s.size() > 0 && nums[s.top()] < nums[i % n] ) {
                result[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return result;
    }
};
