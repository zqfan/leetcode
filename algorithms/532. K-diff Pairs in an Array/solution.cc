class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if ( k < 0 ) {
            return 0;
        }
        set<int> visited;
        // numbers that has a pair which larger than it
        set<int> pairs;
        for ( int n : nums ) {
            if ( visited.find(n + k) != visited.end() ) {
                pairs.insert(n);
            }
            if ( visited.find(n - k) != visited.end() ) {
                pairs.insert(n - k);
            }
            visited.insert(n);
        }
        return pairs.size();
    }
};
