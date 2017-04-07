class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for ( int i = 0; i < numbers.size(); i++ ) {
            int k = target - numbers[i];
            auto j = lower_bound(numbers.begin() + i + 1, numbers.end(), k);
            if ( j != numbers.end() && *j == k ) {
                return {i + 1, j - numbers.begin() + 1};
            }
        }
    }
};
