bool stringCompare(const string &a, const string &b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    } else {
        return a > b;
    }
}

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), stringCompare);
        return nums[k-1];
    }
};
