class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        unordered_set<int> p;
        int result = 0;
        for ( int i = 31; i >= 0; --i ) {
            result <<= 1;
            p.clear();
            for ( int n : nums ) {
                p.insert(n >> i);
            }
            for ( int n : p ) {
                // consider maxxor = x ^ y, then maxxor ^ x = y
                if ( p.find(result ^ 1 ^ n) != p.end() ) {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};
