class Solution {
public:
    vector<int> grayCode(int n) {
        set<int> visited;
        vector<int> result;
        int i = 0, limit = 1 << n;
        while ( result.size() < limit ) {
            result.push_back(i);
            visited.insert(i);
            for ( int bit = 0; bit < n; ++bit ) {
                if ( visited.find(i ^ (1 << bit)) == visited.end() ) {
                    i ^= 1 << bit;
                    break;
                }
            }
        }
        return result;
    }
};

// 12 / 12 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 16.46 %
