class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        int arrows = 1;
        for ( int i = 0, minRight = INT_MAX; i < points.size(); ++i ) {
            if ( points[i].first > minRight ) {
                ++arrows;
                minRight = points[i].second;
            }
            minRight = min(minRight, points[i].second);
        }
        return points.empty() ? 0 : arrows;
    }
};
