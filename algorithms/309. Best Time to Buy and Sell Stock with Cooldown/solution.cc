class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prebuy = 0, presell = 0, buy = INT_MIN, sell = 0;
        for ( int p : prices ) {
            prebuy = buy;
            buy = max(presell - p, buy);
            presell = sell;
            sell = max(prebuy + p, sell);
        }
        return sell;
    }
};
