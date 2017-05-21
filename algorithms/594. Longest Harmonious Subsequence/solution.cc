class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counter;
        for ( int n : nums ) {
            ++counter[n];
        }
        int lhs = 0;
        for ( auto & p : counter ) {
            if ( counter.find(p.first + 1) != counter.end() ) {
                lhs = max(lhs, p.second + counter[p.first + 1]);
            }
        }
        return lhs;
    }
};
