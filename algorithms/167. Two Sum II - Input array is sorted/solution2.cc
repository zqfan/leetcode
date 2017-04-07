class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> lastIdx;
        for ( int i = 0; i < numbers.size(); i++ ) {
            lastIdx[numbers[i]] = i;
        }
        for ( int i = 0; i < numbers.size(); i++ ) {
            int k = target - numbers[i];
            if ( lastIdx.count(k) && lastIdx[k] > i ) {
                return {i + 1, lastIdx[k] + 1};
            }
        }
    }
};
