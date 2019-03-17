class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> counter(60);
        int result = 0;
        for ( int t : time ) {
            result += counter[(60 - t % 60) % 60];
            counter[t % 60]++;
        }
        return result;
    }
};
