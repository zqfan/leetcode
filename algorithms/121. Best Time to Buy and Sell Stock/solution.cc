class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for ( int p : prices ) {
            maxProfit = max(maxProfit, p - minPrice);
            minPrice = min(minPrice, p);
        }
        return maxProfit;
    }
};

// 200 / 200 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 45.03%
