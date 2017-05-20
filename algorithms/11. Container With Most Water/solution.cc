class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, m = 0, h;
        while ( l < r ) {
            h = min(height[l], height[r]);
            m = max(m, h * (r - l));
            while ( l < r && height[l] <= h ) ++l;
            while ( l < r && height[r] <= h ) --r;
        }
        return m;
    }
};
