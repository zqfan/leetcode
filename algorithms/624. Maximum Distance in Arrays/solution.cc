class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0, start = arrays[0][0], end = arrays[0].back();
        for ( int i = 1, n = arrays.size(); i < n; ++i ) {
            result = max(result, abs(arrays[i].back() - start));
            result = max(result, abs(arrays[i][0] - end));
            start = min(start, arrays[i][0]);
            end = max(end, arrays[i].back());
        }
        return result;
    }
};
