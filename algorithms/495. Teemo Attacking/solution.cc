class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        long result = timeSeries.size() * duration;
        for ( int i = 1; i < timeSeries.size(); ++i ) {
            result -= max(0, timeSeries[i-1] + duration - timeSeries[i]);
        }
        return result;
    }
};
