class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> counter;
        int result = 0;
        for ( auto & p1 : points ) {
            counter.clear();
            for ( auto & p2 : points ) {
                int dx = p1.first - p2.first;
                int dy = p1.second - p2.second;
                ++counter[dx * dx + dy * dy];
            }
            for ( auto p : counter ) {
                result += p.second * (p.second - 1);
            }
        }
        return result;
    }
};

// 31 / 31 test cases passed.
// Status: Accepted
// Runtime: 206 ms
