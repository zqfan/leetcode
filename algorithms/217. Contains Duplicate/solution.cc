class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

// 18 / 18 test cases passed.
// Status: Accepted
// Runtime: 39 ms
