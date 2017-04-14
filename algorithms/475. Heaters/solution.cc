class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0, i = 0;
        for ( int house : houses ) {
            while ( i < heaters.size() - 1 && heaters[i] + heaters[i+1] < 2 * house ) {
                ++i;
            }
            radius = max(radius, abs(house - heaters[i]));
        }
        return radius;
    }
};
