class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> counter;
        for ( auto & row : wall ) {
            for ( int i = 0, sum = 0; i < row.size() - 1; ++i ) {
                sum += row[i];
                ++counter[sum];
            }
        }
        int maximum = 0;
        for ( auto & c : counter ) {
            maximum = max(maximum, c.second);
        }
        return wall.size() - maximum;
    }
};

// 85 / 85 test cases passed.
// Status: Accepted
// Runtime: 36 ms
