class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // @zestypanda
        int s0 = 0, s1 = INT_MIN, tmp;
        for ( int p : prices ) {
            tmp = s0;
            s0 = max(s0, s1 + p);
            s1 = max(s1, tmp - p - fee);
        }
        return s0;
    }
};

// 44 / 44 test cases passed.
// Status: Accepted
// Runtime: 139 ms
