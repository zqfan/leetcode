class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int T = 0, points = 0;
        for (int i = 0; i < k - 1; ++i) {
            T += calories[i];
        }
        for (int i = k - 1; i < calories.size(); ++i) {
            T += calories[i];
            if (T < lower)
                --points;
            else if (T > upper)
                ++points;
            T -= calories[i-k+1];
        }
        return points;
    }
};
